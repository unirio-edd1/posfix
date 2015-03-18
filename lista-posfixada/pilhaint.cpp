#include "pilhaint.h"
using namespace std;

pilhaint::pilhaint(int tamanho) :
n(tamanho),
vet(new int[tamanho]),
topo(-1)
{}

pilhaint::~pilhaint()
{
    delete [] vet;
}
bool pilhaint::vazia() const
{
    return topo == -1 ? true : false;
}

bool pilhaint::cheia() const
{
    return topo == n - 1 ? true: false;
}

bool pilhaint::pop(int& elemento)
{
    if (!vazia()) {
        elemento = vet[topo--];
        return true;
    } else {
        cout << "Pilha vazia: pop nao funcionou.\n";
        return false;
    }
}

bool pilhaint::push(const int& elemento)
{
    if (!cheia()) {
        vet[++topo] = elemento;
        return true;
    } else {
        cout << "Pilha cheia: push nao funcionou.\n";
        return false;
    }
}

bool pilhaint::pilha_topo(int& elemento)
{
    if(!vazia()){
        elemento = vet[topo];
        return true;
    }
    else return false;
}	
