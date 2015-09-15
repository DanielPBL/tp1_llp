#include <iostream>
#include <string>
#include <list>
#include "scanner.h"
#include "sintatico.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

using namespace std;

int main(int argc, char **argv) {
  if (argc < 2) {
    cout << "Faltam argumentos!" << endl;
    return EXIT_FAILURE;
  }

  try {
    Scanner scanner(argv[1]);
    AnaliseSintatica sintatico(scanner);

    sintatico.init();

    /*
       while ((lexema = scanner.getLexema()).tipo != FIM_ARQ_NORMAL) {
       if (lexema.tipo < 0) {
        switch (lexema.tipo) {
        case FIM_ARQ_INEXPERADO:
          cout << "Fim de arquivo inexperado!";
          break;

        case TOKEN_INVALIDO:
          cout << "(" << lexema.token << ")" << "Token inválido!";
          cout << " - Linha: " << scanner.getLinha() << endl;
          break;
        }
        return EXIT_FAILURE;
       } else {
        cout << "Token: " << lexema.token << " - Tipo: " << lexema.tipo << endl;
       }
       }*/
  } catch (string msg) {
    cout << msg << endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
