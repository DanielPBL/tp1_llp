#ifndef __VARIAVEL_H__
#define __VARIAVEL_H__

#include "termo.h"

class Variavel : public Termo {
private:

  int valor;

public:

  Variavel();
  int  getValor();
  void setValor(int);
};

#endif // ifndef __TOCARCMD_H__
