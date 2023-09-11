#include <iostream>
#include <string>

std::string codificarString(const std::string &texto) {
    std::string textoCodificado = texto;
    for (char &ch : textoCodificado) {
        if (std::isalpha(ch)) {
            if (ch == 'z') {
                ch = 'a';
            } else if (ch == 'Z') {
                ch = 'A';
            } else {
                ch++;
            }
        }
    }
    return textoCodificado;
}

std::string decodificarString(const std::string &textoCodificado) {
    std::string textoDecodificado = textoCodificado;
    for (char &ch : textoDecodificado) {
        if (std::isalpha(ch)) {
            if (ch == 'a') {
                ch = 'z';
            } else if (ch == 'A') {
                ch = 'Z';
            } else {
                ch--;
            }
        }
    }
    return textoDecodificado;
}

int main() {
    std::string textoOriginal = "Estruturas de Dados";
    std::string textoCodificado = codificarString(textoOriginal);
    std::string textoDecodificado = decodificarString(textoCodificado);

    std::cout << "Texto Original:     " << textoOriginal << std::endl;
    std::cout << "Texto Codificado:   " << textoCodificado << std::endl;
    std::cout << "Texto Decodificado: " << textoDecodificado << std::endl;

    return 0;
}
