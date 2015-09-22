#include "tp1.h"
#include <cstdio>
#include <string>

AnalisadorSintatico::AnalisadorSintatico(AnalisadorLexico& lexica) : lexica(
                                                                       lexica) {
  this->atual = lexica.getLexema();
}

void AnalisadorSintatico::matchToken(int tipo) {
  if (this->atual.tipo == tipo) {
    this->atual = this->lexica.getLexema();
  } else {
    char *l         = new char[10];
    std::string msg = "";
    sprintf(l, "%02d", this->lexica.getLinha());
    std::string linha(l);
    delete l;
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
  this->procPrograma();
}

void AnalisadorSintatico::procPrograma() {
  if (this->atual.tipo == TEMPO) this->procTempo();
  this->matchToken(MUSICA);
  this->procString();
  this->matchToken(PONTO_VIRGULA);
  this->matchToken(FACA);
  this->procComandos();
  this->matchToken(FIM);
  this->matchToken(FIM_ARQ_NORMAL);
}

void AnalisadorSintatico::procTempo() {
  this->matchToken(TEMPO);
  this->procNumero();
  this->matchToken(PONTO_VIRGULA);
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

void AnalisadorSintatico::procComando() {
  switch (this->atual.tipo) {
  case TOCAR:
    this->procTocar();
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
}

void AnalisadorSintatico::procTocar() {
  this->matchToken(TOCAR);
  this->matchToken(ABRE_PARENTESES);
  this->procNota();
  this->matchToken(VIRGULA);
  this->procDuracao();
  this->matchToken(FECHA_PARENTESES);

  if (this->atual.tipo == DOIS_PONTOS) {
    this->matchToken(DOIS_PONTOS);
    this->procString();
  }
  this->matchToken(PONTO_VIRGULA);
}

void AnalisadorSintatico::procDuracao() {
  if (this->atual.tipo == PORCENTO) {
    this->matchToken(PORCENTO);
    this->procNumero();
  } else {
    this->procNumero();

    if (this->atual.tipo == PONTO) this->matchToken(PONTO);
  }
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

void AnalisadorSintatico::procString() {
  this->matchToken(STRING);
}

void AnalisadorSintatico::procNumero() {
  this->matchToken(NUMERO);
}

const Nota AnalisadorSintatico::procNota() {
  std::string nota = this->atual.token;

  this->matchToken(NOTA);

  return Nota::nomeParaNota(nota);
}

void AnalisadorSintatico::procVar() {
  this->matchToken(VARIAVEL);
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
