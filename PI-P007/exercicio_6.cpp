#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    char continuar;
    int matricula;
    double nota1, nota2, nota3, media;
    do {

        cout << "Digite a matricula do aluno (apenas numeros): ";
        cin >> matricula;

        cout << "Digite as 3 notas do aluno: ";
        cin >> nota1 >> nota2 >> nota3;

        media = (nota1 + nota2 + nota3) / 3.0;

        cout << "MATRICULA   NOTA1   NOTA2   NOTA3   MEDIA" << endl;
        cout << "==========================================" << endl;
        cout << setw(9) << matricula << setw(8) << nota1 << setw(8) << nota2 
            << setw(8) << nota3 << setw(8) << fixed << setprecision(1) << media << endl;

        cout << "Deseja cadastrar outro aluno? (S/N): ";
        cin >> continuar;
    } while (continuar == 'S' || continuar == 's');

    return 0;
}