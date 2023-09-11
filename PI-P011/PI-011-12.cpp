#include <iostream>
#include <string>

std::string intersecaoStrings(const std::string& A, const std::string& B) {
    std::string C;

    // Loop através dos caracteres da string A
    for (char a : A) {
        // Verifique se o caractere está presente na string B
        if (B.find(a) != std::string::npos) {
            // Se estiver presente em ambas as strings, adicione-o à string C
            if (C.find(a) == std::string::npos) {
                C.push_back(a);
            }
        }
    }

    return C;
}

int main() {
    std::string stringA = "abcdef";
    std::string stringB = "bcxyz";

    std::string resultado = intersecaoStrings(stringA, stringB);

    std::cout << "Caracteres em comum: " << resultado << std::endl;

    return 0;
}
