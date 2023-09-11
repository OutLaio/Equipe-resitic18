#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed para gerar números aleatórios
    std::srand(std::time(0));

    // Tamanho do array para armazenar as temperaturas de 250 estações meteorológicas
    const int numEstacoes = 250;

    // Array para armazenar as temperaturas
    double temperaturas[numEstacoes];

    // Inicialize a soma das temperaturas
    double somaTemperaturas = 0.0;

    // Preencher o array com temperaturas aleatórias no intervalo de 10 a 40 graus e calcular a soma
    for (int i = 0; i < numEstacoes; i++) {
        double temperatura = 10 + 30.0 * (std::rand() % 100) / 3000.0;
        temperaturas[i] = temperatura;
        somaTemperaturas += temperatura;
    }

    // Calcular a temperatura média
    double temperaturaMedia = somaTemperaturas / numEstacoes;

    // Exibir as temperaturas originais armazenadas
    std::cout << "Temperaturas Originais:" << std::endl;
    for (int i = 0; i < numEstacoes; i++) {
        std::cout << "Estacao " << i + 1 << ": " << temperaturas[i] << " graus Celsius" << std::endl;
    }

    // Atualizar as temperaturas com base na previsão do modelo
    for (int i = 0; i < numEstacoes; i++) {
        if (temperaturas[i] > temperaturaMedia) {
            temperaturas[i] += 1.0; // Aumentar 1 grau para estações acima da média
        } else {
            temperaturas[i] -= 2.0; // Diminuir 2 graus para estações abaixo da média
        }
    }

    // Exibir as temperaturas atualizadas
    std::cout << "\nTemperaturas Atualizadas:" << std::endl;
    for (int i = 0; i < numEstacoes; i++) {
        std::cout << "Estacao " << i + 1 << ": " << temperaturas[i] << " graus Celsius" << std::endl;
    }

    return 0;
}
