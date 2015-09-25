#include "exprlogd.h"

ExprLogicaDupla::ExprLogicaDupla(Termo *termo1,
                                 RelOp  op,
                                 Termo *termo2) : termo1(termo1), op(op),
                                                  termo2(termo2) {}

bool ExprLogicaDupla::avaliar() {
  switch (this->op) {
  case Igual:
    return this->termo1->getValor() == this->termo2->getValor();

  case Diferente:
    return this->termo1->getValor() != this->termo2->getValor();

  case Menor:
    return this->termo1->getValor() < this->termo2->getValor();

  case MenorIgual:
    return this->termo1->getValor() <= this->termo2->getValor();

  case Maior:
    return this->termo1->getValor() > this->termo2->getValor();

  case MaiorIgual:
    return this->termo1->getValor() >= this->termo2->getValor();
  }

  return false;
}
