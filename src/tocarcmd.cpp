#include "tocarcmd.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define BEEP_PATH "/usr/bin/beep"

using namespace std;

TocarComando::TocarComando(Nota   nota,
                           Duracao* duracao,
                           string palavra) : nota(nota), duracao(duracao),
                                             palavra(palavra) {}

void TocarComando::executar() {
  char cmd[255];
  double duracao = this->duracao->getValor();

  sprintf(cmd, "%s -f %.02f -l %.02f", BEEP_PATH,
          this->nota.frequencia(), duracao);
  cout << "(" << this->nota.nome() << ", " << duracao << ") -> " <<
          this->palavra << endl;
  system(cmd);
}
