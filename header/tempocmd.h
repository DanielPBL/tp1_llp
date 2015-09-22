#ifndef __TEMPOCMD_H__
#define __TEMPOCMD_H__

#include "comando.h"

class TempoComando : public Comando {
private:
  const int tempo;

public:
  TempoComando : tempo(tempo) {}
  void executar();
};

#endif
