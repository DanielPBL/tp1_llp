#ifndef __CONSTINT_H__
#define __CONSTINT_H__

#include "termo.h"

class ConstInt : public Termo {
private:

  int valor;

public:

  ConstInt(int);
  int getValor();
};

#endif // ifndef __CONSTINT_H__
