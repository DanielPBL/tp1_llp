#ifndef __TOCARCMD_H__
#define __TOCARCMD_H__

#include <string>
#include "nota.h"
#include "comando.h"

class TocarComando : public Comando {
private:
  Nota nota;
  double duracao;
  std::string palavra;

public:
  TocarComando : nota(nota), duracao(duracao), palavra(palavra) {}
  void executar();
};

#endif
