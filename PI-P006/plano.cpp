#include <iostream>
using namespace std;

int main(){

    float x, y;

    cout << "Digite um valor: ";
    cin >> x;
    cout << "Digite um valor: ";
    cin >> y;

    (x>0 && y>0) ? cout << "Primeiro quadrante":cout<<"";
    (x<0 && y>0) ? cout << "Segundo quadrante":cout<<"";
    (x<0 && y<0) ? cout << "Terceiro quadrante":cout<<"";
    (x>0 && y<0) ? cout << "Quarto quadrante":cout<<"";
    x==0 && y==0 ? cout << "Estão sobre os eixos":cout<<"";

    return 0;
}
