#include<iostream>

using namespace std;

int main(){
    long int li = 0xFFFFFFFFFFFFFFFF; 
    // Devido a li ser do tipo signed, este número corresponde a o maior número negativo que no caso é -1.

    unsigned long int uli = li;
    // Para o tipo unsigned, corresponde ao maior número que pode ser escrito.

    cout << "O valor de li eh: " << li << endl;

    cout << "O valor de uli eh: " << uli << endl;

    return 0;
}