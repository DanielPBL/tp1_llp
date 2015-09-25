#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "variavel.h"
#include <map>
#include <string>

namespace musica {
  extern double tempo;
  extern std::map<std::string, Variavel*> vars;

  void initVars();
  void destroiVars();
}

#endif // ifndef __GLOBALS_H__
