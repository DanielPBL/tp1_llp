#ifndef __EXPRINTD_H__
#define __EXPRINTD_H__

#include "termo.h"
#include "exprint.h"

enum ArithOp { Mais, Menos, Multiplicacao, Divisao };

class ExprInteiraDupla : public ExprInteira {
private:

  Termo *termo1;
  ArithOp op;
  Termo *termo2;

public:

  ExprInteiraDupla(Termo*, ArithOp, Termo*);
  int avaliar();
};

#endif // ifndef __EXPRINTD_H__
