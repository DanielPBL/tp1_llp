#ifndef __NOTA_H__
#define __NOTA_H__

#include <string>
#include <list>

class Nota {
private:

  double nota;
  std::string nomeNota;
  static std::list<Nota> listaNotas;

  Nota(double,
       std::string);

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

  std::string           nome();
  double                frequencia();

  static std::list<Nota>obterNotas();
  static Nota           nomeParaNota(std::string);
};

#endif // ifndef __NOTA_H__
