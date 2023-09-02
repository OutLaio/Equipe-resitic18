#include<iostream>

using namespace std;

int main(){
    int a, b, c;

    cout << "Digite um numero: ";
    cin >> a;
    cout << "Digite outro numero: ";
    cin >> b;

    if (b == 0){
        cout << "Divisao por zero nao eh possivel" << endl; 
    }else if(a%b == 0){
        cout << "A divisao entre os dois numeros eh exata." << endl;
        c = a/b;
        cout << "O quociente entre os dois numeros eh : " << c <<endl;
    }else{
        cout << "A divisao entre os dois numeros nao eh exata." << endl;
    }
    
    return 0;
}