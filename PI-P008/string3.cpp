#include <iostream>
#include <vector>
using namespace std;

int main(){
    srand(time(NULL));

    vector<string> listaStrings;

    for(int i=0; i<10; i++){
        string letras = "";
        for(int i=0; i<10; i++){
            letras.push_back('a' + rand()%('z' - 'a'));
        }
        letras.at(0) = toupper(letras.at(0));
        listaStrings.push_back(letras);
    }

    for(string s : listaStrings){
        cout << "- " << s << endl;
    }

    return 0;
}