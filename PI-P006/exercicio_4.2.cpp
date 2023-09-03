#include<iostream>
#include<math.h>

using namespace std;

int main(){
    double x, y;

    cout <<endl << "Digite a coordenada x: ";
    cin >> x;
    cout << "Digite a coordenada y: ";
    cin >> y;

    cout << "O ponto esta no " 
    << (x>0 ? (y>0 ? "primeiro quadrante" : (y<0 ? "quarto quadrante" : "eixo x")) : (x<0 ? (y>0 ? "segundo quadrante" : (y<0 ? "terceiro quadrante" : "eixo x")) : "eixo y")) 
    << endl;

    return 0;
}