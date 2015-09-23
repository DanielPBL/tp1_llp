#ifndef __ATRIBCMD_H__
#define __ATRIBCMD_H__

#include "comando.h"
#include "variavel.h"
#include "exprint.h"

class AtribuirComando : public Comando {
private:
  Variavel var;
  ExprInteira expr;

public:

  AtribuirComando(Variavel, ExprInteira);
  void executar();
};

#endif // ifndef __ATRIBCMD_H__
