#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int numero;
    string s_numero, temp;

    cin >> numero;
    s_numero = to_string(numero);

    temp = s_numero;
    reverse(temp.begin(), temp.end());

    if(s_numero.length() > 1){
        temp == s_numero ? cout << "É palindromo!" : cout << "Não é palindromo!";
        cout << endl;
    } else {
        cout << "Apesar de ter apenas um digito, é palindromo" << endl;
    }

    return 0;
}
