#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

string codificaString(const string &texto) {
    string codificada = texto;

    for (size_t i = 0; i < codificada.length(); i++) {
        if (isalpha(codificada[i])) { 
            if (codificada[i] == 'z')
                codificada[i] = 'a'; 
            else if (codificada[i] == 'Z')
                codificada[i] = 'A';
            else
                codificada[i]++;
        }
    }
    return codificada;
}

string decodificaString(const string &textoCodificado) {
    string decodificada = textoCodificado;

    for (size_t i = 0; i < decodificada.length(); i++) {
        if (isalpha(decodificada[i])) {
            if (decodificada[i] == 'a')
                decodificada[i] = 'z';
            else if (decodificada[i] == 'A')
                decodificada[i] = 'Z';
            else
                decodificada[i]--;
        }
    }
    return decodificada;
}

int main() {
    string texto = "Estruturas de Dados";
    string textoCodificado = codificaString(texto);
    string textoDecodificado = decodificaString(textoCodificado);

    cout << "Texto Original: " << texto << endl
         << "Texto Codificado: " << textoCodificado << endl
         << "Texto Decodificado: " << textoDecodificado << endl;

    return 0;
}