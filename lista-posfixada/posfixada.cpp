//
//  posfixada.cpp
//  lista-posfixada
//
//  Created by Diogo Martins on 3/18/15.
//  Copyright (c) 2015 Diogo Martins. All rights reserved.
//

#include <stdio.h>
#include "pilhaint.h"
#include "posfixada.h"

using namespace std;

posfixada::posfixada(int tamanho_pilha, int tamanho_expressao){
    expressao = new char[tamanho];
    pilha = tamanho_pilha;
    tamanho = tamanho_pilha;
}

posfixada::~posfixada(){
    delete [] expressao;
}

void posfixada::le_expressao(){
    cout << "Digite expressao pos fixada \n";
    cin.getline(expressao, tamanho);
}

bool posfixada::operador(const char simbolo) const{
    if (simbolo == '+' || simbolo == '-' || simbolo == '*' || simbolo == '/'){
        return true;
    }
    return false;
}
