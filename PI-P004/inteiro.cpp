#include <iostream>
#include <climits>
using namespace std;

int main(){
    
    // LETRA A
    cout << "Maior inteiro possível: " << INT_MAX << endl;

    // LETRA B
    unsigned long int uli = ULONG_MAX;
    cout << "Maior unsigned long int possível: " << uli << endl;

    // LETRA C
    long int li = uli;
    uli = li;
    cout << "unsigned long int uli: " << uli << endl;
    cout << "long int li: " << li << endl;
    /* A variavel li utliza o primeiro bit pra controlar valores negativos. Então retornou -1 como valor por conta desse primeiro bit. */
    
    // LETRA D
    li = LONG_MIN;
    cout << "Menor long int possível: " << li << endl;
    li = LONG_MAX;
    cout << "Maior long int possível: " << li << endl;

    // LETRA E
    unsigned int ui = li;
    li = ui;
    cout << "unsigned int: " << ui << endl;
    cout << "long int: " << li << endl;
    /* Ao armazenar li em ui com espaço menor, o valor que fica é o da variável com espaço menor ao fazer o contrário. */

    // LETRA F
    ui = UINT_MAX;
    cout << "Maior unsigned int possível: " << ui << endl;
    ui = 0;
    cout << "Menor unsigned int possível: " << ui << endl;

    return 0;
}
