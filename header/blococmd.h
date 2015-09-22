#ifndef __BLOCOCMD_H__
#define __BLOCOCMD_H__

#include "comando.h"
#include <list>

class BloboComando : public Comando {
private:
  std::list<Comando> comandos;

public:
  void adicionarComando(Comando c);
  void executar();
};

#endif
