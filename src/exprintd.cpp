#include "exprintd.h"

ExprInteiraDupla::ExprInteiraDupla(Termo  *termo1,
                                   ArithOp op,
                                   Termo  *termo2) : termo1(termo1), op(op),
                                                     termo2(termo2) {}

int ExprInteiraDupla::avaliar() {
  switch (this->op) {
  case Mais:
    return termo1->getValor() + termo2->getValor();

  case Menos:
    return termo1->getValor() - termo2->getValor();

  case Multiplicacao:
    return termo1->getValor() * termo2->getValor();

  case Divisao:
    return termo1->getValor() / termo2->getValor();
  }

  return 0;
}
