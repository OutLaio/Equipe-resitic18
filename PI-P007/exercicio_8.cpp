#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int escolhaUsuario = 0;

    cout << "Digite a altura: ";
    cin >> escolhaUsuario;

    cout << "a:" << endl;
    for(int i=0; i<escolhaUsuario; i++) {
        for(int j=0; j<escolhaUsuario; j++) cout << "*";
        cout << endl;
    }
    cout << endl << "b:" << endl;
    for(int i=1; i<=escolhaUsuario; i++) {
        for(int j=0; j<i; j++) cout << "*";
        cout << endl;
    }
    cout << endl << "c:" << endl;
    for(int i=0; i<escolhaUsuario; i++) {
        if(i==0 || i==escolhaUsuario-1){
            for(int j=0; j<escolhaUsuario; j++) {
                cout << "*";
            }
        } else {
            cout << "*" << setw(escolhaUsuario-1) << "*";
        }
        cout << endl;
    }
    return 0;
}
