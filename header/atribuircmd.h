#ifndef __TOCARCMD_H__
#define __TOCARCMD_H__

#include <string>
#include "exprint.h"
#include "variavel.h"
#include "comando.h"

class TocarComando : public Comando {
private:

  Nota   nota;
  double duracao;
  std::string palavra;

public:

  TocarComando(Nota,
               double,
               std::string)
  void executar();
};

#endif // ifndef __TOCARCMD_H__
