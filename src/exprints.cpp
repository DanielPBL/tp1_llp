#include "exprints.h"

ExprInteiraSimples::ExprInteiraSimples(Termo *termo) : termo(termo) {}

int ExprInteiraSimples::avaliar() {
  return this->termo->getValor();
}
