#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int a, b, c;

    cout <<endl << "Digite um numero: ";
    cin >> a;
    cout << "Digite outro numero: ";
    cin >> b;

    if (a == b){
        cout << endl << "Estes numeros sao iguais";
    }else{
        c = (a>b ? a : b);
        cout << c << " eh maior e eh " << (c%2==0 ? "par" : "impar") << endl;
    }

    return 0;
}