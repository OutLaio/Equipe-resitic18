#include <iostream>
using namespace std;

int main(){
    cout << "Numeros Primos: ";

    for(int i=2; i<=100; i++){ 
        if(i == 2 || i == 3 || i == 5 || i == 7){
            if(i == 7) cout << i; // Controle de Formatação
            else cout << i << ", ";
        } else if (i % 2 != 0 && i % 3 != 3 && i % 5 != 0 && i % 7 != 0){
            cout << ", " << i;
        }
    }

    cout << endl;
    
    return 0;
}
