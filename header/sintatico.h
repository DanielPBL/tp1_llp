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
  double           getTempo();
  BlocoComandos*   procPrograma();
  TempoComando*    procTempo();
  BlocoComandos*   procComandos();
  Comando*         procComando();
  TocarComando*    procTocar();
  double           procDuracao();
  PausarComando*   procPausar();
  AtribuirComando* procAtribuir();
  SeComando*       procSe();
  RepetirComando*  procRepetir();
  std::string      procString();
  ConstInt*        procNumero();
  Nota             procNota();
  Variavel*        procVar();
  ExprLogica*      procBoolExp();
  RelOp            procRelOp();
  ExprInteira*     procIntExp();
  ArithOp          procArithOp();
  Termo*           procTerm();
};

#endif // ifndef __SINTATICO_H__
