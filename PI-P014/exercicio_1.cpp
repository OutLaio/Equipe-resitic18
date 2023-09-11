#include <iostream>

// Função recursiva para calcular o fatorial
unsigned long long calcularFatorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Caso base: fatorial de 0 e 1 é 1
    } else {
        // Chamada recursiva para calcular o fatorial
        return n * calcularFatorial(n - 1);
    }
}

int main() {
    int numeros[3]; // Array para armazenar os três números
    
    // Solicita ao usuário que insira três números inteiros não negativos
    for (int i = 0; i < 3; ++i) {
        std::cout << "Digite o " << i + 1 << "º numero inteiro nao negativo: ";
        std::cin >> numeros[i];
        
        if (numeros[i] < 0) {
            std::cout << "O fatorial nao esta definido para numeros negativos." << std::endl;
            return 1; // Encerra o programa se um número negativo for inserido
        }
    }
    
    // Calcula e exibe o fatorial para cada um dos três números
    for (int i = 0; i < 3; ++i) {
        unsigned long long fatorial = calcularFatorial(numeros[i]);
        std::cout << "O fatorial de " << numeros[i] << " eh " << fatorial << std::endl;
    }
    
    return 0;
}
