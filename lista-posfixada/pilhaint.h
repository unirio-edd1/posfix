#ifndef PILHAINT_H
#define PILHAINT_H
#include <iostream>
#include <cstdlib>
class pilhaint
{
protected:
    int n;
    int *vet;
    int topo;
public:
    bool vazia() const;
    bool cheia() const;
    pilhaint(int tamanho = 10);
    ~pilhaint();
    bool pop(int& elemento);
    bool push(const int& elemento);
    bool pilha_topo (int& elemento);
};
#endif

