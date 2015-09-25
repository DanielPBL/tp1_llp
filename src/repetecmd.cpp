#include "repetecmd.h"

RepetirComando::RepetirComando(ExprLogica    *expr,
                               BlocoComandos *cmds) : expr(expr),
                                                      comandos(cmds) {}

void RepetirComando::executar() {
  while (this->expr->avaliar()) this->comandos->executar();
}
