#include <iostream>

using namespace std;

int main() {
    int altura;

    cout << "Digite a altura do padrao: ";
    cin >> altura;

    cout << endl << "a." << endl;

    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << " * ";
        }
        cout << endl;
    }

    cout << endl << "b." << endl;

    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= i; j++) {
            cout << " * ";
        }
        cout << endl;
    }

    cout << endl << "c." << endl;

    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << (i==1||i==altura||j==1||j==4 ? " * " : "   ");
        }
        cout << endl;
    }

    return 0;
}
