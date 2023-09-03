#include <iostream>
using namespace std;

int main(){

    // LETRA A
    for(int i=48; i<=57; i++){
        cout << "'" << char(i) << "' - " << i << endl;
    }

    // LETRA B
    for(int i=48; i<=57; i++){
        cout << "DECIMAL:" << endl;
        cout << dec << "'" << char(i) << "' - " << i << endl;
        cout << "OCTAL" << endl;
        cout << oct << "'" << char(i) << "' - " << i << endl;
        cout << "HEXADECIMAL: " << endl;
        cout << hex << "'" << char(i) << "' - " << i << endl;
        cout << endl;
    }

    // LETRA C
    char escolhaUsuario;
    cout << "Digite um numero: ";
    cin >> escolhaUsuario;
    
    cout << "DECIMAL:" << endl;
    cout << dec << "'" << int(escolhaUsuario) << "' - " << escolhaUsuario << endl;
    cout << "OCTAL" << endl;
    cout << oct << "'" << int(escolhaUsuario) << "' - " << escolhaUsuario << endl;
    cout << "HEXADECIMAL: " << endl;
    cout << hex << "'" << int(escolhaUsuario) << "' - " << escolhaUsuario << endl;
    cout << endl;

    // LETRA D
    /* Utilizando o wchar_t é possível armazenar caracteres especiais. */
    wchar_t caracterC = 'ç';
    wchar_t caracterA = 'ã';

    cout << caracterC << endl << caracterA << endl;

    return 0;
}