#include <iostream>
#include <string>
using namespace std;

string codificarString(string &entrada);
string decodificarString(string &entrada);

int main() {
    string msgOriginal = "Estruturas de Dados";
    string msgCodificada = codificarString(msgOriginal);
    string msgDecodificada = decodificarString(msgCodificada);

    cout << "Mensagem Original: " << msgOriginal << endl;
    cout << "Mensagem Codificada: " << msgCodificada << endl;
    cout << "Mensagem Decodificada: " << msgDecodificada << endl;
    return 0;
}
string codificarString(string &entrada) {
    string resultado = entrada;

    for (char &c : resultado) {
        if (isalpha(c)) {
            if (c == 'z' || c == 'Z') c = c - 25;
            else c++;
        }
    }
    return resultado;
}
string decodificarString(string &entrada) {
    string resultado = entrada;

    for(char &c : resultado) {
        if (isalpha(c)) {
            if (c == 'a' || c == 'A') c = c + 25;
            else c--;
        }
    }
    return resultado;
}