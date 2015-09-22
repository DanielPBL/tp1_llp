#ifndef __NOTA_H__
#define __NOTA_H__

#include <string>

class Nota {
private:
  double nota;
  std::string nomeNota;
  Nota(double nota, std::string nome) : nota(nota), nomeNota(nome) {}
public:
  static const Nota La;
  static const Nota LaSustenido;
  static const Nota Si;
  static const Nota Do;
  static const Nota DoSustenido;
  static const Nota Re;
  static const Nota ReSustenido;
  static const Nota Mi;
  static const Nota Fa;
  static const Nota FaSustenido;
  static const Nota Sol;
  static const Nota SolSustenido;

  operator double() const { return this->nota; }
  operator std::string() const { return this->nomeNota; }
  std::string nome() { return this->nomeNota; }
  double frequencia() { return this->nota; }
};

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

#endif
