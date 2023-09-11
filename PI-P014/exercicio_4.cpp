#include <iostream>
#include <cmath>
using namespace std;

typedef struct Ponto {
    double x;
    double y;
} P;

double distanciaPontos(P ponto1, P ponto2);

int main() {
    P pontoA = {1.0, 2.0};
    P pontoB = {4.0, 6.0};

    double distancia = distanciaPontos(pontoA, pontoB);

    cout << "A distancia do ponto A(" << pontoA.x << ", " << pontoA.y << ") até o ponto B(" << pontoB.x << ", " << pontoB.y << ") é: " << distancia << endl;

    return 0;
}
double distanciaPontos(P ponto1, P ponto2) {
    double x, y;
    x = ponto1.x - ponto2.x;
    y = ponto1.y - ponto2.y;
    return sqrt(x * x + y * y);
}