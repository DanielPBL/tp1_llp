#include "pausarcmd.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define SLEEP_PATH "sleep"

using namespace std;

PausarComando::PausarComando(ConstInt *tempo) : tempo(tempo) {}

void PausarComando::executar() {
  char cmd[255];

  sprintf(cmd, "%s %.03f", SLEEP_PATH,
          (this->tempo->getValor() * musica::tempo / 1000));
  cout << "(" <<
  (this->tempo->getValor() * musica::tempo) << ")" << endl;
  system(cmd);
}
