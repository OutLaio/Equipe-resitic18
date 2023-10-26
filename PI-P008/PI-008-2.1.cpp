#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
    // Inicializa o gerador de números aleatórios com uma semente única
    srand(static_cast<unsigned int>(time(nullptr)));

    // Tamanho do array
    const int tamanho = 100;

    // Declarando  o array original
    int array[tamanho];

    // Preenchendo o array com valores aleatórios entre 1 e 20
    for (int i = 0; i < tamanho; ++i) {
        array[i] = 1 + rand() % 20;
    }

    // Declarando um array para contar as ocorrências de cada valor
    int contagem[20] = {0}; // Inicializa todas as posições com zero

    // Contagem das ocorrências
    for (int i = 0; i < tamanho; ++i) {
        contagem[array[i] - 1]++; // Subtrai 1 para mapear valores entre 1 e 20 para índices de 0 a 19
    }

    // Encontre o valor (ou valores) com o maior número de ocorrências
    int maxOcorrencias = 0;
    vector<int> numerosMaisFrequentes;

    for (int i = 0; i < 20; ++i) {
        if (contagem[i] > maxOcorrencias) {
            maxOcorrencias = contagem[i];
            numerosMaisFrequentes.clear();
            numerosMaisFrequentes.push_back(i + 1); // Adiciona o valor ao vetor
        } else if (contagem[i] == maxOcorrencias) {
            numerosMaisFrequentes.push_back(i + 1); // Adiciona o valor ao vetor
        }
    }

    // Exibindo  os números mais frequentes
    cout << "Número(s) mais frequente(s): ";
    for (int i = 0; i < numerosMaisFrequentes.size(); ++i) {
        cout << numerosMaisFrequentes[i];
        if (i < numerosMaisFrequentes.size() - 1) {
            cout << ", ";
        }
    }
    cout << " (aparecem " << maxOcorrencias << " vezes)" << endl;

    return 0;
}