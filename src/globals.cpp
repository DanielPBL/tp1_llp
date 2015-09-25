#include "globals.h"
#include <iostream>

using namespace std;

namespace musica {
  double tempo = 500;
  map<string, Variavel*> vars;

  void initVars() {
    vars["a"] = new Variavel();
    vars["b"] = new Variavel();
    vars["c"] = new Variavel();
    vars["d"] = new Variavel();
    vars["e"] = new Variavel();
    vars["f"] = new Variavel();
    vars["g"] = new Variavel();
    vars["h"] = new Variavel();
    vars["i"] = new Variavel();
    vars["j"] = new Variavel();
    vars["k"] = new Variavel();
    vars["l"] = new Variavel();
    vars["m"] = new Variavel();
    vars["n"] = new Variavel();
    vars["o"] = new Variavel();
    vars["p"] = new Variavel();
    vars["q"] = new Variavel();
    vars["r"] = new Variavel();
    vars["s"] = new Variavel();
    vars["t"] = new Variavel();
    vars["u"] = new Variavel();
    vars["v"] = new Variavel();
    vars["w"] = new Variavel();
    vars["x"] = new Variavel();
    vars["y"] = new Variavel();
    vars["z"] = new Variavel();
  }

  void destroiVars() {
    map<string, Variavel*>::iterator it;

    for (it = vars.begin(); it != vars.end(); ++it)
      delete it->second;
  }
}
