#include "nota.h"

using namespace std;

Nota::Nota(double nota,
           string nome) : nota(nota), nomeNota(nome) {}

string Nota::nome() {
  return this->nomeNota;
}

double Nota::frequencia() {
  return this->nota;
}

const Nota Nota::La(440.0, "A");
const Nota Nota::LaSustenido(466.2, "A#");
const Nota Nota::Si(493.9, "B");
const Nota Nota::Do(261.6, "C");
const Nota Nota::DoSustenido(277.2, "C#");
const Nota Nota::Re(293.7, "D");
const Nota Nota::ReSustenido(311.1, "D#");
const Nota Nota::Mi(329.6, "E");
const Nota Nota::Fa(349.2, "F");
const Nota Nota::FaSustenido(370.0, "F#");
const Nota Nota::Sol(392.0, "G");
const Nota Nota::SolSustenido(415.3, "G#");

list<Nota> notas = Nota::obterNotas();

list<Nota>Nota::obterNotas() {
  list<Nota> notas;

  notas.push_front(Nota::La);
  notas.push_front(Nota::LaSustenido);
  notas.push_front(Nota::Si);
  notas.push_front(Nota::Do);
  notas.push_front(Nota::DoSustenido);
  notas.push_front(Nota::Re);
  notas.push_front(Nota::ReSustenido);
  notas.push_front(Nota::Mi);
  notas.push_front(Nota::Fa);
  notas.push_front(Nota::FaSustenido);
  notas.push_front(Nota::Sol);
  notas.push_front(Nota::SolSustenido);

  return notas;
}

Nota Nota::nomeParaNota(string nome) {
  list<Nota>::iterator it;

  for (it = notas.begin(); it != notas.end(); ++it) {
    if (nome == it->nome()) return *it;
  }

  return Nota::SolSustenido;
}
