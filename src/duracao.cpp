#include "duracao.h"
#include "globals.h"

Duracao::Duracao(int         numero,
                 TipoDuracao duracao) : numero(numero), duracao(duracao) {}

double Duracao::getValor() {
  double duracao = musica::tempo;

  switch (this->duracao) {
  case Seminima:
    return duracao * this->numero;

  case Colcheia:
    return duracao / this->numero;

  case Meia:
    return duracao * this->numero * 1.5;
  }

  return duracao;
}
