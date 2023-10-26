#include <iostream>
#include <iomanip>
#include "Ponto.cpp"
using namespace std;

int main(){

    // "defaultfloat - reinicia as formatações aplicadas."

    // Primeiro Teste
    Ponto p1(3, 4);
    double distancia = p1.calcDistancia();
    cout << "A distância do ponto (" << p1.getX() << ", " << p1.getY() << ")"
    << " até a origem é aproximadamente " << fixed << setprecision(2) << distancia << "." << endl;
    
    // Segundo Teste
    Ponto p2(-2, 7);
    p2.setCoordenadas(1, 1);
    distancia = p2.calcDistancia();
    cout << defaultfloat << "A distância do ponto (" << p2.getX() << ", " << p2.getY() << ")"
    << " até a origem é aproximadamente " << fixed << setprecision(5)<< distancia << "." << endl;

    // Terceiro Teste
    Ponto p3(0, 3);
    Ponto p4(4, 0);
    double distancia_p3 = p3.calcDistancia();
    double distancia_p4 = p4.calcDistancia();
    cout << defaultfloat << "A distância do ponto (" << p3.getX() << ", " << p3.getY() << ")"
    << " até a origem é " << fixed << setprecision(1)<< distancia_p3 << defaultfloat << " e do ponto (" << p4.getX() << ", " << p4.getY() << ")"
    << " até a origem é " << fixed << distancia_p4 << "." << endl;

    // Quarto Teste
    Ponto pontos[3];
    pontos[0].setCoordenadas(2, 2);
    pontos[1].setCoordenadas(-1, 5);
    pontos[2].setCoordenadas(0, 0);
    
    for(int i=0; i<3; i++){
        distancia = pontos[i].calcDistancia();
        if(pontos[i].getX() != 0 && pontos[i].getY() != 0)
            cout << defaultfloat << "Distância do ponto " << i + 1 << " até a origem: " << fixed << setprecision(5) << distancia << endl;
        else cout << defaultfloat << "Distância do ponto " << i + 1 << " até a origem: " << fixed << setprecision(1) << distancia << endl;
    }

    // Quinto Teste
    Ponto p5;
    cout << defaultfloat << "Coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;
    p5.setCoordenadas(8, -3);
    cout << "Novas coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;

    return 0;
}
