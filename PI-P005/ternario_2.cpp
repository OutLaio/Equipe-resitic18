#include <iostream>
#include <climits>
using namespace std;

int main(){

    int x;
    cout << "Digite um numero: ";
    cin >> x;
    
    x > SHRT_MIN && x < SHRT_MAX ? cout << "este valor pertence ao intervalo dos short int" : cout << "e maior que um short int";

    return 0;
}
