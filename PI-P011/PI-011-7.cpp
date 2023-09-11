#include <iostream>

void multiplica_por_n(int *vet, int qtde, int n) {
    for (int i = 0; i < qtde; i++) {
        vet[i] *= n;
    }
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int multiplicador = 2;

    std::cout << "Vetor original: ";
    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i] << " ";
    }

    multiplica_por_n(vetor, tamanho, multiplicador);

    std::cout << "\nVetor multiplicado por " << multiplicador << ": ";
    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i] << " ";
    }

    return 0;
}
