#include<iostream>

using namespace std;

int main(){
    unsigned int ui = 0x7FFFFFFF; 
    // Devido a ui ser do tipo unsigned, este número corresponde a algum valor positivo correspondente.

    long int li = ui;
    // Para o tipo signed, corresponde ao maior número que pode ser escrito.

    //Obs.: Em ambos os casos, o valor impresso será o mesmo, pois ui abrange todos os números positivos que pode ser escrito em li

    cout << "O valor de li eh: " << li << endl;

    cout << "O valor de ui eh: " << ui << endl;

    return 0;
}