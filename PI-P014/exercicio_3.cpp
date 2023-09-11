#include <iostream>
#include <cmath> // Para usar a função sqrt (raiz quadrada)

// Definição da struct Ponto
struct Ponto {
    double x;
    double y;
};

// Função para calcular a distância entre dois pontos
double calcularDistancia(Ponto ponto1, Ponto ponto2) {
    double diferencaX = ponto1.x - ponto2.x;
    double diferencaY = ponto1.y - ponto2.y;

    // Aplicando o teorema de Pitágoras para calcular a distância
    return std::sqrt(diferencaX * diferencaX + diferencaY * diferencaY);
}

int main() {
    // Criando dois pontos
    Ponto pontoA;
    pontoA.x = 1.0;
    pontoA.y = 2.0;

    Ponto pontoB;
    pontoB.x = 4.0;
    pontoB.y = 6.0;

    // Calculando a distância entre os pontos
    double distancia = calcularDistancia(pontoA, pontoB);

    // Imprimindo a distância
    std::cout << "Distância entre os pontos A e B: " << distancia << std::endl;

    return 0;
}
