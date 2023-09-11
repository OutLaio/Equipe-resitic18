#include <iostream>

// Função para ordenar quatro variáveis float em ordem crescente
void ordenar(float &a, float &b, float &c, float &d) {
    if (a > b) {
        std::swap(a, b);
    }
    if (a > c) {
        std::swap(a, c);
    }
    if (a > d) {
        std::swap(a, d);
    }
    if (b > c) {
        std::swap(b, c);
    }
    if (b > d) {
        std::swap(b, d);
    }
    if (c > d) {
        std::swap(c, d);
    }
}

int main() {
    float num1, num2, num3, num4;

    // Solicita ao usuário que insira os quatro números
    std::cout << "Digite o primeiro numero: ";
    std::cin >> num1;
    std::cout << "Digite o segundo numero: ";
    std::cin >> num2;
    std::cout << "Digite o terceiro numero: ";
    std::cin >> num3;
    std::cout << "Digite o quarto numero: ";
    std::cin >> num4;

    // Chama a função para ordenar os números
    ordenar(num1, num2, num3, num4);

    // Exibe os números ordenados
    std::cout << "Numeros ordenados em ordem crescente: " << num1 << ", " << num2 << ", " << num3 << ", " << num4 << std::endl;

    return 0;
}
