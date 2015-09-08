#ifndef __SCANNER_H__
#define __SCANNER_H__

#include <fstream>
#include <string>
#include <map>

#define FIM_ARQ_INEXPERADO -2
#define TOKEN_INVALIDO     -1
#define FIM_ARQ_NORMAL     0
#define TEMPO              1
#define MUSICA             2
#define FACA               3
#define REPETIR            4
#define TOCAR              5
#define SE                 6
#define SENAO              7
#define FIM                8
#define PAUSAR             9
#define VARIAVEL           10
#define NOTA               11
#define PONTO_VIRGULA      12
#define IGUAL              13
#define ABRE_PARENTESES    14
#define FECHA_PARENTESES   15
#define DOIS_PONTOS        16
#define PONTO              17
#define PORCENTO           18
#define IGUAL_IGUAL        19
#define DIFERENTE          20
#define MENOR              21
#define MAIOR              22
#define IGUAL_MENOR        23
#define MAIOR_IGUAL        24
#define MAIS               25
#define MENOS              26
#define VEZES              27
#define DIVIDIDO           28
#define NUMERO             29
#define STRING             30
#define VIRGULA            31

typedef struct LEXEMA {
  std::string token;
  int         tipo;
} Lexema;

class Scanner {
private:

  std::ifstream arquivo;
  int linha;
  std::map<std::string, int> tabelaSimbolos;

public:

  Scanner(char *arquivo);
  ~Scanner();
  Lexema getLexema();
  int    getLinha();

private:

  int         consultarTabelaSimbolos(std::string);
  void        criarTabelaSimbolos();
  void        ungetChar(char);
  static bool isDigit(char);
  static bool isLowerLetter(char);
  static bool isUperLetter(char);
  static bool isLetter(char);
  static bool isBlank(char);
  static bool isSimbolo(char);
};

#endif // ifndef __SCANNER_H__
