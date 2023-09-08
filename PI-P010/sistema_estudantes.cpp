#include <iostream>
#include <vector>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN "cls"
#else
#include <unistd.h>
#define CLEAR_SCREEN "clear"
#endif

using namespace std;

static void ordenaABC(vector<string> &palavras);

int main(){

    int qntAlunos;
    vector<string> nomeAlunos;
    vector<float> notasAlunos;

    cout << "Bem vindo ao Sistema de Notas dos Estudantes" << endl << endl;

    cout << "Digite quantos alunos serão cadastrados:" << endl << "> ";
    cin >> qntAlunos;

    system(CLEAR_SCREEN); // Limpando terminal

    // Preenchendo nomes e notas
    for(int i=0; i<qntAlunos; i++){
        string nomeAluno;
        float notaI, notaII;
        cout << "Digite o nome do aluno:" << endl << "> ";
        cin >> nomeAluno;

        cout << endl << "Nota I: ";
        cin >> notaI;
        cout << "Nota II: ";
        cin >> notaII;
        
        nomeAlunos.push_back(nomeAluno);
        notasAlunos.push_back(notaI);
        notasAlunos.push_back(notaII);
    }

    // Ordenando nomes
    ordenaABC(nomeAlunos);

    return 0;
}

static void ordenaABC(vector<string> &palavras){
    int n = palavras.size() - 1, cont = 0;
    bool trocou;

    do{
        trocou = false;
        for(int i=0; i<n; i++){
            cont = 0;
            while(palavras.at(i).at(cont) == palavras.at(i+1).at(cont)) cont++;
            
            if(tolower(palavras.at(i).at(cont)) > tolower(palavras.at(i+1).at(cont))){
                swap(palavras.at(i), palavras.at(i+1));
                trocou = true;
            }
        }
        n--;
    }while(trocou);
}