#include <iostream>

int insere_meio(int vetor[], int& tam, int elemento) {
    // Verifica se o tamanho do vetor é par
    if (tam % 2 == 0) {
        // Se for par, movemos metade dos elementos para a direita
        for (int i = tam - 1; i >= tam / 2; i--) {
            vetor[i + 1] = vetor[i];
        }
    } else {
        // Se for ímpar, movemos metade dos elementos + 1 para a direita
        for (int i = tam - 1; i > tam / 2; i--) {
            vetor[i + 1] = vetor[i];
        }
    }

    // Inserimos o elemento no meio do vetor
    vetor[tam / 2] = elemento;

    // Atualizamos o tamanho do vetor
    tam++;

    return tam;
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6};
    int tam = 6;
    int elemento = 100;

    std::cout << "Vetor original: ";
    for (int i = 0; i < tam; i++) {
        std::cout << vetor[i] << " ";
    }

    tam = insere_meio(vetor, tam, elemento);

    std::cout << "\nVetor modificado: ";
    for (int i = 0; i < tam; i++) {
        std::cout << vetor[i] << " ";
    }

    std::cout << "\nNovo tamanho do vetor: " << tam << std::endl;

    return 0;
}
