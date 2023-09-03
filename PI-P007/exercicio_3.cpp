#include <iostream>
using namespace std;

int main(){
    int numero;

    cout << "Numero: ";
    cin >> numero;
    cout << "Divisores de " << numero << ": ";

    for(int i=numero; i>0; i--){
        if(numero % i == 0){
            cout << i;
            if(i != 1) cout << ", ";
            else cout << "." << endl;
        }
    }
}
