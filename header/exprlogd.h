#ifndef __EXPRLOGD_H__
#define __EXPRLOGD_H__

#include "termo.h"
#include "exprlog.h"

enum RelOp {
  Igual,
  Diferente,
  Menor,
  MenorIgual,
  Maior,
  MaiorIgual
};

class ExprLogicaDupla : public ExprLogica {
private:

  Termo *termo1;
  RelOp  op;
  Termo *termo2;

public:

  ExprLogicaDupla(Termo*,
                  RelOp,
                  Termo*);
  bool avaliar();
};

#endif // ifndef __EXPRLOGD_H__
