#include<iostream>

using namespace std;

int main(){
    int a, b, c;

    cout << "Digite um numero: ";
    cin >> a;
    cout << "Digite outro numero: ";
    cin >> b;

    c = a+b;

    cout << "A soma dos dois numeros em hexadecimal eh : 0x" << hex << c <<endl;

    return 0;
}