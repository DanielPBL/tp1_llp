#include "secmd.h"

SeComando::SeComando(ExprLogica    *expr,
                     BlocoComandos *se,
                     BlocoComandos *senao) : expr(expr), comandosSe(se),
                                             comandosSenao(senao) {}

void SeComando::executar() {
  if (this->expr->avaliar())
    this->comandosSe->executar();
  else
    this->comandosSenao->executar();
}
