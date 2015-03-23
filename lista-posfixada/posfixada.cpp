#include "posfixada.h"
using namespace std;

posfixada::posfixada(int tamanho_pilha, int tamanho_expressao):
pilha(tamanho_pilha),
expressao(new char[tamanho_expressao]),
tamanho(tamanho_expressao)
{ }

posfixada::~posfixada()
{
    delete [] expressao;
}

// Le expressao para ser avaliada
void posfixada::le_expressao()
{
    cout << "Entre com expressao posfixada: ";
    cin.getline(expressao, tamanho);
}

// Testa se simbolo corrente � um operador
bool posfixada::operador(const char simbolo)  const
{
    if (simbolo == '*' || simbolo == '+' ||
        simbolo == '-' || simbolo == '/')
        return true;
    return false;
}
// Aplica operador aos dois simbolos do topo da pilha
// Retorna verdadeiro se operacao realizada com sucesso,
// falso caso contrario
bool posfixada::aplica_operador(const char operador)
{
    int operando1, operando2;
    
    // Desempilha dois operandos
    if (!pilha.pop(operando1)) return false;
    if (!pilha.pop(operando2)) return false;
    
    switch (operador) {
        case '*':
            pilha.push(operando2 * operando1);  break;
        case '+':
            pilha.push(operando2 + operando1); break;
        case '/':
            pilha.push(operando2 / operando1);  break;
        case '-':
            pilha.push(operando2 - operando1);  break;
        default:
            return false;
    }
    return true;
}

bool posfixada::avalia_expressao()
{
    int simbolo = 0;
    
    while(expressao[simbolo]) {
        if (operador(expressao[simbolo])) {
            if (!aplica_operador(expressao[simbolo])) {
                cout << "Erro: poucos operadores\n";
                return false;
            }
        } else if (int(expressao[simbolo]) >= int('0')
                   && int(expressao[simbolo]) <= int('9'))
            pilha.push(int(expressao[simbolo])- int('0'));
        simbolo++;
    }
    if (!pilha.pop(resposta)) {
        cout << "Erro desempilhando resposta.\n";
        return false;
    } else if (!pilha.vazia()) {
        cout << "Erro: poucos operandos.\n";
        return false;
    }
    return true;
}

void posfixada::imprime_resultado() const
{
    cout << "Resposta = " << resposta << endl;
}