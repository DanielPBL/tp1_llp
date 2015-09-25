#include "blococmd.h"
#include "globals.h"
#include <iostream>

using namespace std;

BlocoComandos::BlocoComandos() {
  this->comandos = list<Comando*>();
}

void BlocoComandos::adicionarComando(Comando *comando) {
  this->comandos.push_back(comando);
}

void BlocoComandos::executar() {
  list<Comando*>::iterator it;

  for (it = this->comandos.begin(); it != this->comandos.end(); ++it)
    (*it)->executar();
}
