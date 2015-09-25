#ifndef __SECMD_H__
#define __SECMD_H__

#include "blococmd.h"
#include "exprlog.h"

class SeComando : public Comando {
private:
  ExprLogica *expr;
  BlocoComandos *comandosSe;
  BlocoComandos *comandosSenao;

public:

  SeComando(ExprLogica*, BlocoComandos*, BlocoComandos*);
  void executar();
};

#endif // ifndef __SECMD_H__
