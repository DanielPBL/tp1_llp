#include "tp1.h"
#include "tempocmd.h"

TempoComando::TempoComando(ConstInt tempo) : tempo(tempo) {}

void TempoComando::executar() {
  musica::tempo = this->tempo.getValor();
}
