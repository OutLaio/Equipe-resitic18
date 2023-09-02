#include<iostream>

using namespace std;

int main(){
    int a, b, c;

    cout << "Digite um numero: ";
    cin >> a;
    cout << "Digite outro numero: ";
    cin >> b;

    c = (a>b) ? a-b : b-a;

    cout << "A diferenca absoluta entre os dois numeros eh : " << c <<endl;

    return 0;
}