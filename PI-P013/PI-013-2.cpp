#include <iostream>
#include <string>

// Definição da estrutura para armazenar dados de empregados
struct Empregado {
    std::string nome;
    std::string sobrenome;
    int anoNascimento;
    std::string RG;
    int anoAdmissao;
    double salario;
};

// Função para reajustar o salário de cada empregado em 10%
void Reajusta_dez_porcento(Empregado empregados[], int numEmpregados) {
    for (int i = 0; i < numEmpregados; i++) {
        empregados[i].salario *= 1.10; // Aumenta o salário em 10%
    }
}

int main() {
    // Criação de um vetor de empregados com capacidade para até 50 empregados
    Empregado empregados[50];

    // Preenchendo os dados de alguns empregados (exemplo)
    empregados[0] = {"Joao", "Silva", 1985, "12345678", 2010, 3000.0};
    empregados[1] = {"Maria", "Santos", 1990, "98765432", 2015, 3500.0};
    empregados[2] = {"Pedro", "Ferreira", 1980, "54321678", 2005, 2800.0};

    int numEmpregados = 3; // Número atual de empregados no vetor

    // Chamando a função para reajustar os salários em 10%
    Reajusta_dez_porcento(empregados, numEmpregados);

    // Exibindo os dados atualizados dos empregados
    std::cout << "Dados dos empregados apos o reajuste de 10%:\n";
    for (int i = 0; i < numEmpregados; i++) {
        std::cout << "Nome: " << empregados[i].nome << " " << empregados[i].sobrenome << "\n";
        std::cout << "Ano de Nascimento: " << empregados[i].anoNascimento << "\n";
        std::cout << "RG: " << empregados[i].RG << "\n";
        std::cout << "Ano de Admissao: " << empregados[i].anoAdmissao << "\n";
        std::cout << "Salario: R$" << empregados[i].salario << "\n";
        std::cout << "\n";
    }

    return 0;
}
