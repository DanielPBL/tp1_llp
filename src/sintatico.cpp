#include "tp1.h"
#include <cstdio>
#include <cstdlib>
#include <string>

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
  this->procPrograma();
  musica::destroiVars();
}

void AnalisadorSintatico::procPrograma() {
  if (this->atual.tipo == TEMPO) this->procTempo()->executar();
  this->matchToken(MUSICA);
  this->procString();
  this->matchToken(PONTO_VIRGULA);
  this->matchToken(FACA);
  this->procComandos();
  this->matchToken(FIM);
  this->matchToken(FIM_ARQ_NORMAL);
}

TempoComando* AnalisadorSintatico::procTempo() {
  this->matchToken(TEMPO);
  ConstInt tempo = this->procNumero();
  this->matchToken(PONTO_VIRGULA);

  return new TempoComando(tempo);
}

void AnalisadorSintatico::procComandos() {
  while (this->atual.tipo == TOCAR ||
         this->atual.tipo == PAUSAR ||
         this->atual.tipo == VARIAVEL ||
         this->atual.tipo == SE ||
         this->atual.tipo == REPETIR) {
    this->procComando();
  }
}

Comando * AnalisadorSintatico::procComando() {
  Comando *comando = NULL;

  switch (this->atual.tipo) {
  case TOCAR:
    comando = this->procTocar();
    break;

  case PAUSAR:
    this->procPausar();
    break;

  case REPETIR:
    this->procRepetir();
    break;

  case VARIAVEL:
    this->procAtribuir();
    break;

  case SE:
    this->procSe();
    break;
  }

  if (comando == NULL) comando = new Comando();

  comando->executar();
  delete comando;

  return comando;
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
    ConstInt numero = this->procNumero();
    duracao = musica::tempo / numero.getValor();
  } else {
    ConstInt numero = this->procNumero();
    duracao = musica::tempo / numero.getValor();

    if (this->atual.tipo == PONTO) {
      this->matchToken(PONTO);
      duracao *= 1.5;
    }
  }

  return duracao;
}

void AnalisadorSintatico::procPausar() {
  this->matchToken(PAUSAR);
  this->matchToken(ABRE_PARENTESES);
  this->procNumero();
  this->matchToken(FECHA_PARENTESES);
  this->matchToken(PONTO_VIRGULA);
}

void AnalisadorSintatico::procAtribuir() {
  this->procVar();
  this->matchToken(IGUAL);
  this->procIntExp();
  this->matchToken(PONTO_VIRGULA);
}

void AnalisadorSintatico::procSe() {
  this->matchToken(SE);
  this->matchToken(ABRE_PARENTESES);
  this->procBoolExp();
  this->matchToken(FECHA_PARENTESES);
  this->matchToken(PONTO_VIRGULA);
  this->matchToken(FACA);
  this->procComandos();

  if (this->atual.tipo == SENAO) {
    this->matchToken(SENAO);
    this->procComandos();
  }
  this->matchToken(FIM);
}

void AnalisadorSintatico::procRepetir() {
  this->matchToken(REPETIR);
  this->matchToken(ABRE_PARENTESES);
  this->procBoolExp();
  this->matchToken(FECHA_PARENTESES);
  this->matchToken(PONTO_VIRGULA);
  this->matchToken(FACA);
  this->procComandos();
  this->matchToken(FIM);
}

string AnalisadorSintatico::procString() {
  string str = this->atual.token;

  this->matchToken(STRING);

  return str;
}

ConstInt AnalisadorSintatico::procNumero() {
  string num = this->atual.token;

  this->matchToken(NUMERO);

  return ConstInt(atoi(num.c_str()));
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

void AnalisadorSintatico::procBoolExp() {
  this->procTerm();
  this->procRelOp();
  this->procTerm();
}

void AnalisadorSintatico::procRelOp() {
  switch (this->atual.tipo) {
  case IGUAL_IGUAL:
    this->matchToken(IGUAL_IGUAL);
    break;

  case DIFERENTE:
    this->matchToken(DIFERENTE);
    break;

  case MENOR:
    this->matchToken(MENOR);
    break;

  case MAIOR:
    this->matchToken(MAIOR);
    break;

  case IGUAL_MENOR:
    this->matchToken(IGUAL_MENOR);
    break;

  case MAIOR_IGUAL:
    this->matchToken(MAIOR_IGUAL);
    break;
  }
}

void AnalisadorSintatico::procIntExp() {
  this->procTerm();

  if ((this->atual.tipo == MAIS) ||
      (this->atual.tipo == MENOS) ||
      (this->atual.tipo == VEZES) ||
      (this->atual.tipo == DIVIDIDO)) {
    this->procArithOp();
    this->procTerm();
  }
}

void AnalisadorSintatico::procArithOp() {
  switch (this->atual.tipo) {
  case MAIS:
    this->matchToken(MAIS);
    break;

  case MENOS:
    this->matchToken(MENOS);
    break;

  case VEZES:
    this->matchToken(VEZES);
    break;

  case DIVIDIDO:
    this->matchToken(DIVIDIDO);
    break;
  }
}

void AnalisadorSintatico::procTerm() {
  if (this->atual.tipo == VARIAVEL) this->procVar();
  else this->procNumero();
}
