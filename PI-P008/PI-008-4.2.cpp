#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype> // Para toupper

using namespace std;

int main() {
    // Semente para gerar números aleatórios
    srand(time(0));

    // Lista para armazenar as strings aleatórias
    string strings[10];

    // Gerar 10 strings aleatórias
    for (int i = 0; i < 10; i++) {
        string randomString;
        
        // Gerar 10 caracteres aleatórios
        for (int j = 0; j < 10; j++) {
            char randomChar = 'a' + rand() % ('z' - 'a' + 1);
            randomString += randomChar;
        }

        // Substituir o primeiro caractere por maiúscula
        randomString[0] = toupper(randomString[0]);

        // Adicionar a string gerada à lista
        strings[i] = randomString;
    }

    // Exibir as strings geradas
    for (int i = 0; i < 10; i++) {
        cout << "String " << i+1 << ": " << strings[i] << endl;
    }

    return 0;
}
