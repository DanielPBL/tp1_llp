#ifndef __EXPRINTS_H__
#define __EXPRINTS_H__

#include "termo.h"
#include "exprint.h"

class ExprInteiraSimples : public ExprInteira {
private:
  Termo *termo;
public:

  ExprInteiraSimples(Termo*);
  int avaliar();
};

#endif // ifndef __EXPRINTS_H__
