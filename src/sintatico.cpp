#include "sintatico.h"
#include "globals.h"
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

AnalisadorSintatico::AnalisadorSintatico(AnalisadorLexico& lexica) : lexica(
                                                                       lexica) {
  this->atual = lexica.getLexema();
}

void AnalisadorSintatico::matchToken(int tipo) {
  if (this->atual.tipo == tipo) {
    this->atual = this->lexica.getLexema();
  } else {
    char   l[10];
    string msg = "";
    sprintf(l, "%02d", this->lexica.getLinha());
    string linha(l);
    msg = linha + ": ";

    switch (this->atual.tipo) {
    case TOKEN_INVALIDO:
      msg += "Lexema inválido [" + this->atual.token + "]";
      break;

    case FIM_ARQ_INESPERADO:
    case FIM_ARQ_NORMAL:
      msg += "Fim de arquivo inesperado";
      break;

    default:
      msg += "Lexema não esperado [" + this->atual.token + "]";
    }

    throw msg;
  }
}

void AnalisadorSintatico::init() {
  musica::initVars();
  this->procPrograma()->executar();
  musica::destroiVars();
}

double AnalisadorSintatico::getTempo() {
  return musica::tempo;
}

BlocoComandos* AnalisadorSintatico::procPrograma() {
  BlocoComandos *cmds = new BlocoComandos();

  if (this->atual.tipo == TEMPO)
    cmds->adicionarComando(this->procTempo());

  this->matchToken(MUSICA);
  this->procString();
  this->matchToken(PONTO_VIRGULA);
  this->matchToken(FACA);
  cmds->adicionarComando(this->procComandos());
  this->matchToken(FIM);
  this->matchToken(FIM_ARQ_NORMAL);

  return cmds;
}

TempoComando* AnalisadorSintatico::procTempo() {
  this->matchToken(TEMPO);
  ConstInt *tempo = this->procNumero();
  this->matchToken(PONTO_VIRGULA);

  return new TempoComando(tempo->getValor());
}

BlocoComandos* AnalisadorSintatico::procComandos() {
  BlocoComandos *cmds = new BlocoComandos();

  while (this->atual.tipo == TOCAR ||
         this->atual.tipo == PAUSAR ||
         this->atual.tipo == VARIAVEL ||
         this->atual.tipo == SE ||
         this->atual.tipo == REPETIR) {
    cmds->adicionarComando(this->procComando());
  }

  return cmds;
}

Comando* AnalisadorSintatico::procComando() {
  switch (this->atual.tipo) {
  case TOCAR:
    return this->procTocar();
    break;

  case PAUSAR:
    return this->procPausar();
    break;

  case REPETIR:
    return this->procRepetir();
    break;

  case VARIAVEL:
    return this->procAtribuir();
    break;

  case SE:
    return this->procSe();
    break;
  }

  return new Comando();
}

TocarComando * AnalisadorSintatico::procTocar() {
  double duracao;
  string palavra = "";

  this->matchToken(TOCAR);
  this->matchToken(ABRE_PARENTESES);
  Nota nota = this->procNota();
  this->matchToken(VIRGULA);
  duracao = this->procDuracao();
  this->matchToken(FECHA_PARENTESES);

  if (this->atual.tipo == DOIS_PONTOS) {
    this->matchToken(DOIS_PONTOS);
    palavra = this->procString();
  }
  this->matchToken(PONTO_VIRGULA);

  return new TocarComando(nota, duracao, palavra);
}

double AnalisadorSintatico::procDuracao() {
  double duracao = 0;

  if (this->atual.tipo == PORCENTO) {
    this->matchToken(PORCENTO);
    ConstInt *numero = this->procNumero();
    duracao = this->getTempo() / numero->getValor();
  } else {
    ConstInt *numero = this->procNumero();
    duracao = this->getTempo() / numero->getValor();

    if (this->atual.tipo == PONTO) {
      this->matchToken(PONTO);
      duracao *= 1.5;
    }
  }

  return duracao;
}

PausarComando* AnalisadorSintatico::procPausar() {
  ConstInt *tempo;

  this->matchToken(PAUSAR);
  this->matchToken(ABRE_PARENTESES);
  tempo = this->procNumero();
  this->matchToken(FECHA_PARENTESES);
  this->matchToken(PONTO_VIRGULA);

  return new PausarComando(tempo);
}

AtribuirComando* AnalisadorSintatico::procAtribuir() {
  Variavel *var;
  ExprInteira* expr;

  var = this->procVar();
  this->matchToken(IGUAL);
  expr = this->procIntExp();
  this->matchToken(PONTO_VIRGULA);

  return new AtribuirComando(var, expr);
}

SeComando* AnalisadorSintatico::procSe() {
  ExprLogica *expr;
  BlocoComandos *se;
  BlocoComandos *senao = NULL;

  this->matchToken(SE);
  this->matchToken(ABRE_PARENTESES);
  expr = this->procBoolExp();
  this->matchToken(FECHA_PARENTESES);
  this->matchToken(PONTO_VIRGULA);
  this->matchToken(FACA);
  se = this->procComandos();

  if (this->atual.tipo == SENAO) {
    this->matchToken(SENAO);
    senao = this->procComandos();
  }
  this->matchToken(FIM);

  if (senao == NULL) senao = new BlocoComandos();

  return new SeComando(expr, se, senao);
}

RepetirComando* AnalisadorSintatico::procRepetir() {
  ExprLogica *expr;
  BlocoComandos *cmds;

  this->matchToken(REPETIR);
  this->matchToken(ABRE_PARENTESES);
  expr = this->procBoolExp();
  this->matchToken(FECHA_PARENTESES);
  this->matchToken(PONTO_VIRGULA);
  this->matchToken(FACA);
  cmds = this->procComandos();
  this->matchToken(FIM);

  return new RepetirComando(expr, cmds);
}

string AnalisadorSintatico::procString() {
  string str = this->atual.token;

  this->matchToken(STRING);

  return str;
}

ConstInt* AnalisadorSintatico::procNumero() {
  string num = this->atual.token;

  this->matchToken(NUMERO);

  return new ConstInt(atoi(num.c_str()));
}

Nota AnalisadorSintatico::procNota() {
  string nota = this->atual.token;

  this->matchToken(NOTA);

  return Nota::nomeParaNota(nota);
}

Variavel* AnalisadorSintatico::procVar() {
  string var  = this->atual.token;

  this->matchToken(VARIAVEL);

  return musica::vars[var];
}

ExprLogica* AnalisadorSintatico::procBoolExp() {
  Termo *termo1, *termo2;
  RelOp op;

  termo1 = this->procTerm();
  op = this->procRelOp();
  termo2 = this->procTerm();

  return new ExprLogicaDupla(termo1, op, termo2);
}

RelOp AnalisadorSintatico::procRelOp() {
  switch (this->atual.tipo) {
  case IGUAL_IGUAL:
    this->matchToken(IGUAL_IGUAL);
    return Igual;

  case DIFERENTE:
    this->matchToken(DIFERENTE);
    return Diferente;

  case MENOR:
    this->matchToken(MENOR);
    return Menor;

  case MAIOR:
    this->matchToken(MAIOR);
    return Maior;

  case IGUAL_MENOR:
    this->matchToken(IGUAL_MENOR);
    return MenorIgual;

  case MAIOR_IGUAL:
    this->matchToken(MAIOR_IGUAL);
    return MaiorIgual;
  }

  return Igual;
}

ExprInteira* AnalisadorSintatico::procIntExp() {
  Termo *termo1, *termo2;
  ArithOp op;
  ExprInteira *expr;

  termo1 = this->procTerm();

  if ((this->atual.tipo == MAIS) ||
      (this->atual.tipo == MENOS) ||
      (this->atual.tipo == VEZES) ||
      (this->atual.tipo == DIVIDIDO)) {
    op = this->procArithOp();
    termo2 = this->procTerm();
    expr = new ExprInteiraDupla(termo1, op, termo2);
  } else {
    expr = new ExprInteiraSimples(termo1);
  }

  return expr;
}

ArithOp AnalisadorSintatico::procArithOp() {
  switch (this->atual.tipo) {
  case MAIS:
    this->matchToken(MAIS);
    return Mais;

  case MENOS:
    this->matchToken(MENOS);
    return Menos;

  case VEZES:
    this->matchToken(VEZES);
    return Multiplicacao;

  case DIVIDIDO:
    this->matchToken(DIVIDIDO);
    return Divisao;
  }

  return Mais;
}

Termo* AnalisadorSintatico::procTerm() {
  Termo *termo;

  if (this->atual.tipo == VARIAVEL) termo = this->procVar();
  else termo = this->procNumero();

  return termo;
}
