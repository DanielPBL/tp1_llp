#ifndef __PAUSARCMD_H__
#define __PAUSARCMD_H__

#include "globals.h"
#include "comando.h"
#include "constint.h"

class PausarComando : public Comando {
private:
  ConstInt *tempo;

public:

  PausarComando(ConstInt*);
  void executar();
};

#endif // ifndef __PAUSARCMD_H__
