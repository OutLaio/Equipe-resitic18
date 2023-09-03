#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int numero, i;

    cout << "Digite um numero inteiro: ";
    cin >> numero;

    cout << "Os divisores de " << numero << " sao: ";

    for (i = 1; i <= numero; ++i) {
        if (numero % i == 0) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}