#include <iostream>

using namespace std;

int main() {
    int numero, primeiro = 0, segundo = 1, proximo;

    cout << "Digite um numero inteiro positivo: ";
    cin >> numero;

    cout << "Sequencia de Fibonacci ate " << numero << ":" << endl;

    cout << primeiro << " " << segundo << " ";

    proximo = primeiro + segundo;
    while (proximo <= numero) {
        cout << proximo << " ";
        primeiro = segundo;
        segundo = proximo;
        proximo = primeiro + segundo;
    }

    cout << endl;

    return 0;
}