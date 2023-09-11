#include <iostream>
using namespace std;

int fatorial(int num);

int main(){

    int a = 6;
    int b = 9;
    int c = 11;

    cout << "Fatorial de 6: " << fatorial(a) << endl;
    cout << "Fatorial de 9: " << fatorial(b) << endl;
    cout << "Fatorial de 11: " << fatorial(c) << endl;

    return 0;
}
int fatorial(int num){
    int soma = 1;

    if(num < 0) return 0;
    
    for(int i=1; i<=num; i++) soma *= i;

    return soma;
}