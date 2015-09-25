#include "tocarcmd.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define BEEP_PATH "/usr/bin/beep"

using namespace std;

TocarComando::TocarComando(Nota   nota,
                           double duracao,
                           string palavra) : nota(nota), duracao(duracao),
                                             palavra(palavra) {}

void TocarComando::executar() {
  char cmd[255];

  sprintf(cmd, "%s -f %.02f -l %.02f", BEEP_PATH,
          this->nota.frequencia(), this->duracao);
  cout << "(" << this->nota.nome() << ", " << this->duracao << ") -> " <<
          this->palavra << endl;
  system(cmd);
}
