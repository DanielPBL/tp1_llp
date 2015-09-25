#ifndef __REPETECMD_H__
#define __REPETECMD_H__

#include "blococmd.h"
#include "exprlog.h"

class RepetirComando : public Comando {
private:
  ExprLogica *expr;
  BlocoComandos *comandos;

public:

  RepetirComando(ExprLogica*, BlocoComandos*);
  void executar();
};

#endif // ifndef __REPETECMD_H__
