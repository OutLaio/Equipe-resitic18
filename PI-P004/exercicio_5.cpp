#include<iostream>

using namespace std;

int main(){
    int ia = 0, ib = 55;
    float fa = 0.00, fb = 0.15;
    double da = 0.000, db = 5.78;
    
    cout << "Convertendo a variavel ia para booleano fica: " << (bool)ia << endl;
    cout << "Convertendo a variavel ib para booleano fica: " << (bool)ib << endl;
    cout << "Convertendo a variavel fa para booleano fica: " << (bool)fa << endl;
    cout << "Convertendo a variavel fb para booleano fica: " << (bool)fb << endl;
    cout << "Convertendo a variavel da para booleano fica: " << (bool)da << endl;
    cout << "Convertendo a variavel db para booleano fica: " << (bool)db << endl; 

    /*Obs.: Ao ser convertido para booleano, as variáveis que contém qualquer valor diferente de zero são consideradas 
            como verdadeiro e possuem valor lógico 1.*/

    return 0;
}