#include <iostream>
#include <cctype>
using namespace std;

int main(){

    // LETRA A
    char ch1, ch2, ch3;

    // LETRA B
    cout << "Digite um caractere: ";
    cin >> ch1;

    // LETRA C
    (ch1 >= 65) && (ch1 <= 90) ? cout << "Letra maiúcula" << endl : cout<<"";
    (ch1 >= 97) && (ch1 <= 122) ? cout << "Letra minúcula" << endl : cout<<"";
    (ch1 >= 48) && (ch1 <= 57) ? cout << "Digito" << endl : cout<<"";
    
    // LETRA D
    if(isupper(ch1)) cout << "Letra maiúscula" << endl;
    else if(islower(ch1)) cout << "Letra minúscula" << endl;
    else if(isdigit(ch1)) cout << "Digito" << endl;
    else cout << "Outro tipo de caractere" << endl;

    // LETRA E
    ch2 = 81;
    cout << endl << "Caractere: " << ch2 << endl;
    cout << "Decimal: " << dec << int(ch2) << endl;
    cout << "Ocital: " << oct << int(ch2) << endl;
    cout << "Hexadecimal: " << hex << int(ch2) << endl << endl;
    // LETRA F
    ch3 = 113;
    cout << "Caractere: " << ch3 << endl;
    cout << "Decimal: " << dec << int(ch3) << endl;
    cout << "Ocital: " << oct << int(ch3) << endl;
    cout << "Hexadecimal: " << hex << int(ch3) << endl;

    return 0;
}
