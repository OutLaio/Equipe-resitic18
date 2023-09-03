#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    vector<vector<string>> dadosAlunos;
    int continuarCadastro = true, escolhaCadastro = 0;

    do{
        string matricula, nota1, nota2, nota3;

        cout << "<< Aluno " << dadosAlunos.size() << " >>" << endl;
        cout << "Matricula: ";
        cin >> matricula;
        cout << "1º Nota: ";
        cin >> nota1;
        cout << "2º Nota: ";
        cin >> nota2;
        cout << "3º Nota: ";
        cin >> nota3;
        dadosAlunos.push_back({matricula, nota1, nota2, nota3});

        do{ // Controle de adição de alunos
            cout << endl << "Cadastrar mais um aluno? 1/Sim | 0/Não" << endl << "> ";
            cin >> escolhaCadastro;
            if(escolhaCadastro == 0) continuarCadastro = false;
            else if (escolhaCadastro != 1 && escolhaCadastro != 0) cout << "Opção inválida! 1 ou 0" << endl;
        }while(escolhaCadastro != 1 && escolhaCadastro != 0);
    }while(continuarCadastro == true);

    cout << endl;

    for (vector<string> aluno : dadosAlunos){ // Impressão da tabela
        float media = (stof(aluno[1]) + stof(aluno[2]) + stof(aluno[3])) / 3;
        cout << "MATRICULA" << setw(10) << "NOTA1" << setw(10) << "NOTA2" << setw(10) << "NOTA3" << setw(10) << "MEDIA" << endl << setfill('=') << setw(49) << "" << endl;
        cout << setfill(' ') << aluno[0] << setw(10) << aluno[1] << setw(10) << aluno[2] << setw(10) << aluno[3] << setw(10) << setprecision(2) << media << endl << endl;
    }
    return 0;
}