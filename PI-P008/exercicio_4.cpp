#include<iostream>
#include<sstream>
#include <fstream>
#include<string>
#include<vector>
#include<math.h>
#include <cstdlib>
#include <ctime>

#define WIDTH 640
#define HEIGHT 480

using namespace std;

void salvarImagemPGM(const string& nomeArquivo, int imagem[WIDTH][HEIGHT]) {
    ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
        return;
    }

    arquivo << "P2\n";
    arquivo << WIDTH << " " << HEIGHT << "\n";
    arquivo << "255\n";

    for (int x = 0; x < HEIGHT; ++x) {
        for (int y = 0; y < WIDTH; ++y) {
            arquivo << imagem[x][y] << " ";
        }
        arquivo << "\n";
    }

    arquivo.close();
}

int main(){
    int img[WIDTH][HEIGHT];
    srand(time(nullptr));

    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            img[i][j] = rand()%256;
        }
    }
    salvarImagemPGM("imagem_gerada1.pgm", img);

    cout << "Imagem salva com sucesso!" << endl;
    return 0;
}