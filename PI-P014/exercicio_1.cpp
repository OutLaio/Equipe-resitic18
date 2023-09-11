#include <iostream>

using namespace std;

unsigned long long calcularFatorial(int numero) {
    if (numero < 0) {
        cout << "Fatorial não está definido para números negativos." << endl;
        return 0;
    }
    
    unsigned long long resultado = 1;
    
    for (int i = 1; i <= numero; i++) {
        resultado *= i;
    }
    
    return resultado;
}

int main() {
    int numero1 = 5; 
    int numero2 = 10; 
    int numero3 = 0; 
    
    cout << "Fatorial de " << numero1 << ": " << calcularFatorial(numero1) << endl;
    cout << "Fatorial de " << numero2 << ": " << calcularFatorial(numero2) << endl;
    cout << "Fatorial de " << numero3 << ": " << calcularFatorial(numero3) << endl;
    
    return 0;
}