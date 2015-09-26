#ifndef __TOCARCMD_H__
#define __TOCARCMD_H__

#include <string>
#include "nota.h"
#include "comando.h"
#include "duracao.h"

class TocarComando : public Comando {
private:

  Nota nota;
  Duracao *duracao;
  std::string palavra;

public:

  TocarComando(Nota,
               Duracao*,
               std::string);
  void executar();
};

#endif // ifndef __TOCARCMD_H__
