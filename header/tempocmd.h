#ifndef __TEMPOCMD_H__
#define __TEMPOCMD_H__

#include "comando.h"
#include "constint.h"

class TempoComando : public Comando {
private:

  ConstInt tempo;

public:

  TempoComando(ConstInt);
  void executar();
};

#endif // ifndef __TEMPOCMD_H__
