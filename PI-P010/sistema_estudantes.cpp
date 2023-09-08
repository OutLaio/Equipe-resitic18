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

int main(){

    int qntAlunos;
    vector<string> nomeAlunos;
    vector<float> notasAlunos;

    cout << "Bem vindo ao Sistema de Notas dos Estudantes" << endl << endl;

    cout << "Digite quantos alunos serão cadastrados:" << endl << "> ";
    cin >> qntAlunos;

    system(CLEAR_SCREEN); // limpa terminal

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

    return 0;
}
