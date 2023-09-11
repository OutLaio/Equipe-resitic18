#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    srand(time(NULL));
    int matrizImagem[640][480];
    int repeticoes[256] = {0};

    for(int lin=0; lin<640; lin++){
        for(int col=0; col<480; col++){
            matrizImagem[lin][col] = rand() % 256;
            repeticoes[matrizImagem[lin][col]]++;
        }
    }

    cout << "Intensidade" << setw( 17 ) << "Frequência" << endl;
    for(int pixel=0; pixel<256; pixel++){
        cout << setw( 6 ) << pixel << setw(18) << repeticoes[pixel] << setw( 9 ) << endl;
    }
    return 0;
}