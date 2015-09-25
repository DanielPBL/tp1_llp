#ifndef __TP1_H__
#define __TP1_H__

#include "lexico.h"
#include "nota.h"
#include "comando.h"
#include "constint.h"
#include "termo.h"
#include "variavel.h"
#include "exprint.h"
#include "exprints.h"
#include "exprintd.h"
#include "exprlog.h"
#include "exprlogd.h"
#include "tempocmd.h"
#include "tocarcmd.h"
#include "atribcmd.h"
// #include "blococmd.h"
#include "sintatico.h"

#include <map>

namespace musica {
  extern double tempo;
  extern std::map<std::string, Variavel*> vars;

  void initVars();
  void printVars();
  void destroiVars();
}


#endif // ifndef __TP1_H__
