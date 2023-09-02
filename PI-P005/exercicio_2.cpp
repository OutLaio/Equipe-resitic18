#include<iostream>
#include<string>

using namespace std;

int main(){

    char ch1, ch2, ch3;
    int i;

    cout << "Digite um caractere: ";
    cin >> ch1;

    i = (ch1 >= 48 && ch1 <= 57) ? 3 : (ch1 >= 97 && ch1 <= 122) ? 2 : (ch1 >= 65 && ch1 <= 90) ? 1 : 4;

    cout << "O caractere digitado eh ";
    switch (i){
        case 1:
            cout << "uma letra maiuscula;" << endl;
            break;
        case 2:
            cout << "uma letra minuscula;" << endl;
            break;
        case 3:
            cout << "um digito;" << endl;
            break;
        case 4:
            cout << "outro tipo de caractere;" << endl;
            break;
        default:
            break;
    }

    return 0;
}