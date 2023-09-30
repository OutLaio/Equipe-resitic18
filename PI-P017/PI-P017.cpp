#include <iostream>
#include <cmath>

class Ponto {
private:
    double x;
    double y;

public:
    // Construtor padrão
    Ponto() : x(0.0), y(0.0) {}

    // Construtor que permite definir as coordenadas x e y
    Ponto(double _x, double _y) : x(_x), y(_y) {}

    // Métodos para obter as coordenadas x e y
    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    // Métodos para definir as coordenadas x e y
    void setX(double _x) {
        x = _x;
    }

    void setY(double _y) {
        y = _y;
    }

    // Método para calcular a distância até a origem (0,0)
    double calcularDistanciaOrigem() const {
        return std::sqrt(x * x + y * y);
    }
};

int main() {
    // Criando um ponto (3, 4)
    Ponto ponto1(3.0, 4.0);

    // Obtendo as coordenadas do ponto1
    std::cout << "Coordenadas do ponto1: (" << ponto1.getX() << ", " << ponto1.getY() << ")" << std::endl;

    // Calculando a distância até a origem para o ponto1
    double distancia = ponto1.calcularDistanciaOrigem();
    std::cout << "Distancia ate a origem: " << distancia << std::endl;

    // Definindo novas coordenadas para o ponto1
    ponto1.setX(5.0);
    ponto1.setY(6.0);

    // Obtendo as novas coordenadas do ponto1
    std::cout << "Novas coordenadas do ponto1: (" << ponto1.getX() << ", " << ponto1.getY() << ")" << std::endl;

    return 0;
}
