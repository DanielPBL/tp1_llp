#ifndef __SINTATICO_H__
#define __SINTATICO_H__

#include "scanner.h"

class AnaliseSintatica {
private:

  Scanner& lexica;
  Lexema   atual;

public:

  AnaliseSintatica(Scanner& lexica);
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
  void procNota();
  void procVar();
  void procBoolExp();
  void procRelOp();
  void procIntExp();
  void procArithOp();
  void procTerm();
};

#endif // ifndef __SINTATICO_H__
