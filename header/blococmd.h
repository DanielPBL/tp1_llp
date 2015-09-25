#ifndef __BLOCOCMD_H__
#define __BLOCOCMD_H__

#include "comando.h"
#include <list>

class BlocoComandos : public Comando {
private:

  std::list<Comando*> comandos;

public:

  BlocoComandos();
  void adicionarComando(Comando*);
  void executar();
};

#endif // ifndef __BLOCOCMD_H__
