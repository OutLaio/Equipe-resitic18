#include <iostream>
#include <string>

using namespace std;

const int MAX_EMPREGADOS = 50;

typedef struct T_empregado {
    string nome;
    string sobrenome;
    int anoNascimento;
    string RG;
    int anoAdmissao;
    double salario;
} Empregado;

void Reajusta_dez_porcento(Empregado empregados[], int numEmpregados) {
    for (int i = 0; i < numEmpregados; i++) {
        empregados[i].salario *= 1.10;
    }
}

int main() {
    Empregado empregados[MAX_EMPREGADOS];
    int numEmpregados;

    numEmpregados = 3;
    empregados[0] = {"Laio", "Rodrigues", 1980, "123456789", 2010, 3000.0};
    empregados[1] = {"Joao", "Ramos", 1995, "987654321", 2015, 2500.0};
    empregados[2] = {"Vitor", "Sousa", 1985, "555555555", 2009, 3500.0};

    Reajusta_dez_porcento(empregados, numEmpregados);

    cout << "Empregados apos o reajuste de 10%:" << endl;
    for (int i = 0; i < numEmpregados; i++) {
        cout << "Nome: " << empregados[i].nome << " " << empregados[i].sobrenome << endl;
        cout << "Ano de Nascimento: " << empregados[i].anoNascimento << endl;
        cout << "RG: " << empregados[i].RG << endl;
        cout << "Ano de Admissao: " << empregados[i].anoAdmissao << endl;
        cout << "Salario: R$" << empregados[i].salario << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}