#include <iostream>
#include <vector>

void encontrarPosicoes(const std::string& str, char letra, std::vector<int>& posicoes, int* tamanho) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == letra) {
            posicoes.push_back(i);
        }
    }
    *tamanho = posicoes.size();
}

int main() {
    std::string input;
    char letra;

    std::cout << "Digite uma string de caracteres: ";
    std::cin >> input;

    std::cout << "Digite uma letra: ";
    std::cin >> letra;

    std::vector<int> posicoes;
    int tamanho;

    encontrarPosicoes(input, letra, posicoes, &tamanho);

    if (tamanho > 0) {
        std::cout << "A letra '" << letra << "' foi encontrada nas seguintes posicoes: ";
        for (int i = 0; i < tamanho; ++i) {
            std::cout << posicoes[i];
            if (i < tamanho - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "A letra '" << letra << "' nao foi encontrada na string." << std::endl;
    }

    return 0;
}
