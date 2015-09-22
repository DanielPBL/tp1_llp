#include "tp1.h"

Nota::Nota(double nota, std::string nome) : nota(nota), nomeNota(nome) {

}

Nota::operator double() const {
  return this->nota;
}

Nota::operator std::string() const {
  return this->nomeNota;
}

std::string Nota::nome() {
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

const Nota Nota::nomeParaNota(std::string nome) {
  if (nome == "A")
    return Nota::La;
  // ...
  else
    return Nota::SolSustenido;
}
// std::list<const Nota> notas = Nota::obterNotas();
//
// std::list<const Nota> Nota::obterNotas() {
//   std::list<const Nota> notas;
//   notas << Nota::La
//         << Nota::LaSustenido
//         << Nota::Si
//         << Nota::Do
//         << Nota::DoSustenido
//         << Nota::Re
//         << Nota::ReSustenido
//         << Nota::Mi
//         << Nota::Fa
//         << Nota::FaSustenido
//         << Nota::Sol
//         << Nota::SolSustenido;
//   return notas;
// }
//
// const Nota Nota::nomeParaNota(std::string nome) {
//   for (std::list<const Nota>::iterator it = notas.begin(); it != notas.end(); ++it) {
//     if (nome == (std::string)(*it))
//       return *it;
//   }
//
//   return Nota::SolSustenido;
// }
