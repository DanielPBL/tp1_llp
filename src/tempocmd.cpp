#include "globals.h"
#include "tempocmd.h"
#include <iostream>
using namespace std;
TempoComando::TempoComando(ConstInt tempo) : tempo(tempo) {}

void TempoComando::executar() {
  musica::tempo = this->tempo.getValor();
}
