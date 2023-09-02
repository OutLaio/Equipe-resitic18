#include<iostream>
#include<string>

using namespace std;

int main(){

    char ch1, ch2, ch3;
    int i;

    cout << "Digite um caractere: ";
    cin >> ch1;

    // i = isdigit(ch1) ? 3 : islower(ch1) ? 2 : isupper(ch1) ? 1 : 4;
    /*  as funções isdigit, islower e isupper verificam se a variável possui caractere do tipo:
        dígito, minusculo e maiusculo, respectivamente, e retornam true ou false */

    i = isalnum(ch1);
    /*  a função is alnum retorna:
        1, se a variável possuir caractere maiúsculo;
        2, se a variável possuir caractere minúsculo;
        4, se a variável possuir caractere numérico;
        0, se a variável possuir qualquer outro caractere;*/

    cout << "O caractere digitado eh ";
    switch (i){
        case 1:
            cout << "uma letra maiuscula;" << endl;
            break;
        case 2:
            cout << "uma letra minuscula;" << endl;
            break;
        case 4:
            cout << "um digito;" << endl;
            break;
        case 0:
            cout << "outro tipo de caractere;" << endl;
            break;
        default:
            break;
    }

    return 0;
}