#include <iostream>
using namespace std;

int main(){

    unsigned char infoGene, mascara = 1;
    int genesPresentes = 0, geneEspecifico;
    
    // LETRA A
    cout << "Gene da Planta: ";
    cin >> infoGene;

    // LETRA B
    for (int i = 0; i < 8; i++) {
        if ((infoGene & mascara) != 0) {
            genesPresentes++;
        }
        mascara = mascara << 1;
    }
    cout << "Genes presentes: " << genesPresentes << endl;
    
    // LETRA C
    cout << "Digite o número do gene específico que deseja verificar (entre 1 e 8): ";
    cin >> geneEspecifico;

    mascara = 1 << (geneEspecifico - 1);

    if ((infoGene & mascara) != 0) {
        cout << "O gene " << geneEspecifico << " está presente na planta." << endl;
    } else {
        cout << "O gene " << geneEspecifico << " não está presente na planta." << endl;
    }

    return 0;
}