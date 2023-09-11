#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

double potenciacao(double base, double expoente) {
    return pow(base, expoente);
}

double radiciacao(double numero, double indice) {
    if (indice != 0) {
        return pow(numero, 1.0 / indice);
    } else {
        cout << "Erro: Índice de raiz inválido!" << endl;
        return NAN; 
    }
}

double divisao(double num1, double num2){
    if(num2 != 0) return (num1/num2);
    cout << "Erro: Não é possível dividir por 0." << endl;
    return 0;
}

double multiplicacao(double num1, double num2){
    return num1 * num2;
}

double adicao(double num1, double num2){
    return num1 + num2;

}
double subtracao(double num1, double num2){
    return num1 - num2;
}

int main() {
    char operacao;
    double num1, num2;

    cout << "Calculadora Simples" << endl;
    cout << "Operações disponíveis: +, -, *, /, ^ (potência), r (raiz)" << endl;

    cout << "Digite a operação (+, -, *, /, ^, r): ";
    cin >> operacao;

    cout << "Digite o primeiro número: ";
    cin >> num1;

    if (operacao != 'r') {
        cout << "Digite o segundo número: ";
        cin >> num2;
    }

    double resultado;

    switch (operacao) {
        case '+':
            resultado = adicao(num1, num2);
            break;
        case '-':
            resultado = subtracao(num1, num2);
            break;
        case '*':
            resultado = multiplicacao(num1, num2);
            break;
        case '/':
            resultado = divisao(num1, num2);
            break;
        case '^':
            resultado = potenciacao(num1, num2);
            break;
        case 'r':
            cout << "Digite o índice da raiz: ";
            cin >> num2;
            resultado = radiciacao(num1, num2);
            break;
        default:
            cout << "Operação inválida." << endl;
            return 1;
    }

    if (!isnan(resultado)) {
        cout << "Resultado: " << resultado << endl;
    }

    return 0;
}