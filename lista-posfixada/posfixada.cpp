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

posfixada::posfixada(int tamanho_pilha, int tamanho_expressao)
{
    pilha = pilhaint(tamanho_pilha);
    tamanho = tamanho_pilha;
    expressao = new char[tamanho];
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

bool posfixada::aplica_operador(const char operador){
    int op1, op2;
    
    if (! pilha.pop(op2)) return false;
    if (! pilha.pop(op1)) return false;
    
    switch (operador) {
        case '+':
            pilha.push(op2+op1);
            break;
        case '-':
            pilha.push(op1-op2);
            break;
        case '*':
            pilha.push(op2*op1);
            break;
        case '/':
            pilha.push(op1/op2);
            break;
        default:
            return false;
    }
    
    return true;
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
    
    while (expressao[i] != '\0'){
        c = expressao[i];
        if (operador(c)){
            if (! aplica_operador(c)){
                cout << "ERRO ao aplicador operador \n";
                return false;
            }
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

void posfixada::imprime_resultado(){
    cout << "resultado " << resposta << endl;
}

