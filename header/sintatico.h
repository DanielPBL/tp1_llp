#ifndef __SINTATICO_H__
#define __SINTATICO_H__

#include "lexico.h"

class AnalisadorSintatico {
private:

  AnalisadorLexico& lexica;
  Lexema atual;

public:

  AnalisadorSintatico(AnalisadorLexico& lexica);
  void matchToken(int);
  void init();

private:

  void procPrograma();
  void procTempo();
  void procComandos();
  void procComando();
  void procTocar();
  void procDuracao();
  void procPausar();
  void procAtribuir();
  void procSe();
  void procRepetir();
  void procString();
  void procNumero();
  Nota procNota();
  void procVar();
  void procBoolExp();
  void procRelOp();
  void procIntExp();
  void procArithOp();
  void procTerm();
};

#endif // ifndef __SINTATICO_H__
