#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int numero, numeroOriginal, soma = 0, digitos = 0;

    cout << "Digite um numero inteiro: ";
    cin >> numero;
    numeroOriginal = numero;

    while (numero > 0) {
        numero /= 10;
        digitos++;
    }

    numero = numeroOriginal;

    while (numero > 0) {
        int digito = numero % 10;
        soma += pow(digito, digitos);
        numero /= 10;
    }

    cout << endl << "O numero " << numeroOriginal << (soma == numeroOriginal ? " " : " nao ") << "eh um numero Armstrong" << endl;

    return 0;
}