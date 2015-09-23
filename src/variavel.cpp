#include "tp1.h"
#include "variavel.h"

Variavel::Variavel() : valor(0) {}

int Variavel::getValor() {
  return this->valor;
}

void Variavel::setValor(int valor) {
  this->valor = valor;
}
