#include "atribcmd.h"

AtribuirComando::AtribuirComando(Variavel    var,
                                 ExprInteira expr) : var(var), expr(expr) {}

void AtribuirComando::executar() {
  this->var->setValor(this->expr.avaliar());
}
