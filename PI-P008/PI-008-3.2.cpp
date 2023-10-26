#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cctype>
#include <algorithm> // Para std::sort

using namespace std;

int main() {
    // Seed para o gerador de números aleatórios
    srand(time(0));

    // Tamanho das strings
    const int tamanho = 10;

    // Inicialize as strings vazias
    string stringAleatoria1 = "";
    string stringAleatoria2 = "";

    // Gere as strings aleatórias
    for (int i = 0; i < tamanho; i++) {
        char caractere1 = 'a' + rand() % ('z' - 'a' + 1);
        char caractere2 = 'a' + rand() % ('z' - 'a' + 1);

        // Adicione os caracteres às strings
        stringAleatoria1 += caractere1;
        stringAleatoria2 += caractere2;
    }

    // Transforme o primeiro caractere de cada string em maiúscula
    stringAleatoria1[0] = toupper(stringAleatoria1[0]);
    stringAleatoria2[0] = toupper(stringAleatoria2[0]);

    // Crie um vetor para armazenar as strings
    vector<string> strings;

    // Adicione as strings ao vetor
    strings.push_back(stringAleatoria1);
    strings.push_back(stringAleatoria2);

    // Ordene o vetor em ordem alfabética
    sort(strings.begin(), strings.end());

    // Imprima as strings em ordem alfabética
    cout << "Strings em ordem alfabetica:" << endl;
    for (const string& str : strings) {
        cout << str << endl;
    }

    return 0;
}
