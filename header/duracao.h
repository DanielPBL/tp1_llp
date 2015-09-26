#ifndef __DURACAO_H__
#define __DURACAO_H__

enum TipoDuracao { Colcheia, Seminima, Meia };

class Duracao {
private:

  int numero;
  TipoDuracao duracao;

public:

  Duracao(int,
          TipoDuracao);
  double getValor();
};

#endif // ifndef __DURACAO_H__
