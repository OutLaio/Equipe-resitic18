#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int a, b;

    cout <<endl << "Digite um numero: ";
    cin >> a;
    cout << "Digite outro numero: ";
    cin >> b;

    cout << endl << (a>b ? a : b) << " e maior" << endl;

    return 0;
}