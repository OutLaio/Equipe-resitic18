#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cout << "Informe o limite de alunos (N): ";
    cin >> N;

    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;

    for (int i = 0; i < N; ++i) {
        string nome;
        float nota1, nota2;

        cout << "Informe o nome do aluno " << i + 1 << ": ";
        cin >> nome;

        cout << "Informe a primeira nota do aluno " << i + 1 << ": ";
        cin >> nota1;

        cout << "Informe a segunda nota do aluno " << i + 1 << ": ";
        cin >> nota2;

        nomes.push_back(nome);
        notas1.push_back(nota1);
        notas2.push_back(nota2);
    }

    // Exibindo os dados dos alunos e seus resultados
    cout << "\nResultados dos alunos:\n";
    for (int i = 0; i < N; ++i) {
        float media = (notas1[i] + notas2[i]) / 2;
        cout << "Aluno " << i + 1 << ":\n";
        cout << "Nome: " << nomes[i] << endl;
        cout << "Nota 1: " << notas1[i] << endl;
        cout << "Nota 2: " << notas2[i] << endl;
        cout << "Media: " << media << endl;
        cout << "Status: " << (media >= 7 ? "Aprovado" : "Reprovado") << endl;
        cout << "----------------------\n";
    }

    return 0;
}
