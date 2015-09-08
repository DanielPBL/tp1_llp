#include "sintatico.h"

AnaliseSintatica::AnaliseSintatica(Scanner& lexica) : lexica(lexica) {
  this->atual = lexica.getLexema();
}

void AnaliseSintatica::matchToken(int tipo) {
  if (this->atual.tipo == tipo) this->atual = this->lexica.getLexema();
  else throw "Lexema não esperado";
}

void AnaliseSintatica::init() {
  this->procPrograma();
}

void AnaliseSintatica::procPrograma() {
  if (this->atual.tipo == TEMPO) this->procTempo();
  this->matchToken(MUSICA);
  this->procString();
  this->matchToken(PONTO_VIRGULA);
  this->matchToken(FACA);
  this->procComandos();
  this->matchToken(FIM);
  this->matchToken(FIM_ARQ_NORMAL);
}

void AnaliseSintatica::procTempo() {
  this->matchToken(TEMPO);
  this->procNumero();
  this->matchToken(PONTO_VIRGULA);
}

void AnaliseSintatica::procComandos() {
  while (this->atual.tipo == TOCAR ||
         this->atual.tipo == PAUSAR ||
         this->atual.tipo == VARIAVEL ||
         this->atual.tipo == SE ||
         this->atual.tipo == REPETIR) {
    this->procComando();
  }
}

void AnaliseSintatica::procComando() {
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
    this->procVar();
    break;

  case SE:
    this->procSe();
    break;
  }
}

void AnaliseSintatica::procTocar() {
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

void AnaliseSintatica::procDuracao() {
  if (this->atual.tipo == PORCENTO) {
    this->matchToken(PORCENTO);
    this->procNumero();
  } else {
    this->procNumero();

    if (this->atual.tipo == PONTO) this->matchToken(PONTO);
  }
}

void AnaliseSintatica::procPausar() {
  this->matchToken(PAUSAR);
  this->matchToken(ABRE_PARENTESES);
  this->procNumero();
  this->matchToken(FECHA_PARENTESES);
  this->matchToken(PONTO_VIRGULA);
}

void AnaliseSintatica::procAtribuir() {
  this->procVar();
  this->matchToken(IGUAL);
  this->procIntExp();
  this->matchToken(PONTO_VIRGULA);
}

void AnaliseSintatica::procSe() {
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

void AnaliseSintatica::procRepetir() {
  this->matchToken(REPETIR);
  this->matchToken(ABRE_PARENTESES);
  this->procBoolExp();
  this->matchToken(FECHA_PARENTESES);
  this->matchToken(PONTO_VIRGULA);
  this->matchToken(FACA);
  this->procComandos();
  this->matchToken(FIM);
}

void AnaliseSintatica::procString() {
  this->matchToken(STRING);
}

void AnaliseSintatica::procNumero() {
  this->matchToken(NUMERO);
}

void AnaliseSintatica::procNota() {
  this->matchToken(NOTA);
}

void AnaliseSintatica::procVar() {
  this->matchToken(VARIAVEL);
}

void AnaliseSintatica::procBoolExp() {
  this->procTerm();
  this->procRelOp();
  this->procTerm();
}

void AnaliseSintatica::procRelOp() {
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

void AnaliseSintatica::procIntExp() {
  this->procTerm();

  if ((this->atual.tipo == MAIS) ||
      (this->atual.tipo == MENOS) ||
      (this->atual.tipo == VEZES) ||
      (this->atual.tipo == DIVIDIDO)) {
    this->procArithOp();
    this->procTerm();
  }
}

void AnaliseSintatica::procArithOp() {
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

void AnaliseSintatica::procTerm() {
  if (this->atual.tipo == VARIAVEL) this->procVar();
  else this->procNumero();
}
