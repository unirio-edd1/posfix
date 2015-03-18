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

bool posfixada::aplica_operador(const char Operator){
    return false;
}

bool posfixada::is_digito(const char c){
    int n = int(c);
    if (n >= int('0') && n <= int('9')){
        return true;
    }
    return false;
}

int posfixada::char_to_int(const char c){
    return int(c) - int('0');
}

bool posfixada::avalia_expressao(){
    int i = 0;
    char c;
    
    while (expressao[i] != '\n'){
        c = expressao[i];
        if (operador(c)){
            aplica_operador(c);
        }
        else if (posfixada::is_digito(c)){
            pilha.push(char_to_int(c));
        }
        i++;
    }
    if (!pilha.pop(resposta)){
        cout << "ERRO ao desempilhar \n";
        return false;
    }
    else if(! pilha.vazia()){
        /* 
         Ao desempilhar, o unico elemento deve ser o resultado. Se sobrar alguma coisa
         algo deu errado
         */
        cout << "ERRO \n";
        return false;
    }
    return true;
}

