#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Inicialize a semente para gerar números aleatórios diferentes a cada execução.
    srand(time(0));

    // Tamanho da imagem
    int largura = 640;
    int altura = 480;

    // Crie a matriz para armazenar os valores de intensidade de iluminação
    int imagem[altura][largura];

    // Preencha a matriz com valores aleatórios entre 0 e 255
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            imagem[i][j] = rand() % 256;
        }
    }

    // Construa o histograma
    int histograma[256] = {0}; // Inicialize todas as frequências como 0

    // Contagem das frequências
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            int intensidade = imagem[i][j];
            histograma[intensidade]++;
        }
    }

    // Exiba o histograma
    for (int i = 0; i < 256; i++) {
        cout << "Intensidade " << i << ": " << histograma[i] << " pixels" << endl;
    }

    return 0;
}
