#ifndef __SINTATICO_H__
#define __SINTATICO_H__

#include "tp1.h"

class AnalisadorSintatico {
private:

  AnalisadorLexico& lexica;
  Lexema atual;

public:

  AnalisadorSintatico(AnalisadorLexico& lexica);
  void matchToken(int);
  void init();

private:

  void          procPrograma();
  TempoComando* procTempo();
  void          procComandos();
  Comando*      procComando();
  TocarComando* procTocar();
  double        procDuracao();
  void          procPausar();
  void          procAtribuir();
  void          procSe();
  void          procRepetir();
  std::string   procString();
  ConstInt      procNumero();
  Nota          procNota();
  Variavel*     procVar();
  void          procBoolExp();
  void          procRelOp();
  void          procIntExp();
  void          procArithOp();
  void          procTerm();
};

#endif // ifndef __SINTATICO_H__
