#include <iostream>

int* intercala(int *vet1, int tam1, int *vet2, int tam2) {
    int *resultado = new int[tam1 + tam2];
    
    int i = 0, j = 0, k = 0;
    
    while (i < tam1 && j < tam2) {
        resultado[k++] = vet1[i++];
        resultado[k++] = vet2[j++];
    }
    
    while (i < tam1) {
        resultado[k++] = vet1[i++];
    }
    
    while (j < tam2) {
        resultado[k++] = vet2[j++];
    }
    
    return resultado;
}

int main() {
    int tam1, tam2;
    
    std::cout << "Digite o tamanho do primeiro vetor: ";
    std::cin >> tam1;
    
    std::cout << "Digite o tamanho do segundo vetor: ";
    std::cin >> tam2;
    
    int *vet1 = new int[tam1];
    int *vet2 = new int[tam2];
    
    std::cout << "Digite os elementos do primeiro vetor:" << std::endl;
    for (int i = 0; i < tam1; i++) {
        std::cin >> vet1[i];
    }
    
    std::cout << "Digite os elementos do segundo vetor:" << std::endl;
    for (int i = 0; i < tam2; i++) {
        std::cin >> vet2[i];
    }
    
    int *resultado = intercala(vet1, tam1, vet2, tam2);
    
    std::cout << "Vetor intercalado:" << std::endl;
    for (int i = 0; i < (tam1 + tam2); i++) {
        std::cout << resultado[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] vet1;
    delete[] vet2;
    delete[] resultado;
    
    return 0;
}
