#include <iostream>
#include <vector>

bool eh_primo(int numero) {
    if (numero <= 1) {
        return false;
    }
    
    for (int i = 2; i * i <= numero; ++i) {
        if (numero % i == 0) {
            return false;
        }
    }
    
    return true;
}

int conta_primos(const std::vector<int>& vetor) {
    int contador = 0;
    
    for (int numero : vetor) {
        if (eh_primo(numero)) {
            contador++;
        }
    }
    
    return contador;
}

int main() {
    std::vector<int> numeros = {2, 3, 5, 7, 10, 11, 13};
    
    int quantidade_primos = conta_primos(numeros);
    
    std::cout << "Quantidade de numeros primos no vetor: " << quantidade_primos << std::endl;
    
    return 0;
}
