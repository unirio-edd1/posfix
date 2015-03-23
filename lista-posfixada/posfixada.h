#ifndef POSFIXADA_H
#define POSFIXADA_H
#include "pilhaint.h"

class posfixada
{
private:
    int resposta;		// Armazena a resposta final
    pilhaint pilha;	// Pilha para armazenar os operandos
    char *expressao;	// Expressao posfixada
    int tamanho;      // Tamanho da expressao posfixada
    
    // verifica se sibolo eh um operador?
    bool operador(const char simbolo) const;
    // Aplica operador a 2 operandos e informa erros
    bool aplica_operador(const char Operator);
    
public:
    posfixada(int tamanho_pilha = 10, int tamanho_expressao = 50);
    ~posfixada();
    void le_expressao();
    // Avalia expressao posfixada e reporta erros
    bool avalia_expressao();
    void imprime_resultado() const;
};
#endif