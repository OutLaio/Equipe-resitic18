#include <iostream>

void maxmin(int vetor[], int n, int &maximo, int &minimo) {
    if (n <= 0) {
        std::cerr << "Erro: O vetor está vazio." << std::endl;
        return;
    }

    maximo = vetor[0];
    minimo = vetor[0];

    for (int i = 1; i < n; i++) {
        if (vetor[i] > maximo) {
            maximo = vetor[i];
        }
        if (vetor[i] < minimo) {
            minimo = vetor[i];
        }
    }
}

int main() {
    int vetor[] = {5, 3, 9, 1, 7, 2};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int max, min;

    maxmin(vetor, tamanho, max, min);

    std::cout << "Maximo: " << max << std::endl;
    std::cout << "Minimo: " << min << std::endl;

    return 0;
}
