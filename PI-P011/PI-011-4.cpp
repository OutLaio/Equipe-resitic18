#include <iostream>

void calcula(int &X, int &Y) {
    int soma = X + Y;
    int subtracao = X - Y;
    X = soma;
    Y = subtracao;
}

int main() {
    int X = 10;
    int Y = 5;

    calcula(X, Y);

    std::cout << "X apos a funcao: " << X << std::endl;
    std::cout << "Y apos a funcao: " << Y << std::endl;

    return 0;
}
