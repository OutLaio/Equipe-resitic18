#include<iostream>
#include<math.h>

using namespace std;

int main(){

    int a, b, c, delta;
    float x1, x2;

    cout << "Digite o coeficiente a: ";
    cin >> a;
    cout << "Digite o coeficiente b: ";
    cin >> b;
    cout << "Digite o coeficiente c: ";
    cin >> c;

    delta = pow(b,2) - 4*a*c;

    if(delta < 0){
        cout << "Nao existem raizes reais!" << endl;
        return 0;
    }

    x1 = (-b+sqrt(delta))/2*a;
    x2 = (-b-sqrt(delta))/2*a;

    if(delta == 0){
        cout << "O polinomio tem duas raizes iguais em x = " << x1 << endl;
    }else{
        cout << "O polinomio tem duas raizes em x = " << x1 << " e x = " << x2 <<  endl;
    }

    return 0;
}