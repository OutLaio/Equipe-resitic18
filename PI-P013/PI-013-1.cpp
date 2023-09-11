#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Estrutura para representar uma passagem vendida
struct Passagem {
    string assento;
    string dataHora;
    string cpf;
    string nome;
    int idade;
};

// Função para calcular o total arrecadado para uma determinada viagem
float calcularTotalViagem(const vector<Passagem>& passagens) {
    float total = 0;
    for (const Passagem& passagem : passagens) {
        total += 80; // Cada passagem custa 80 reais
    }
    return total;
}

// Função para calcular o total arrecadado em um determinado mês
float calcularTotalMes(const vector<Passagem>& passagens, int mes) {
    float total = 0;
    for (const Passagem& passagem : passagens) {
        // Supondo que a dataHora está no formato "dd/mm/yyyy hh:mm"
        int mesPassagem = stoi(passagem.dataHora.substr(3, 2));
        if (mesPassagem == mes) {
            total += 80; // Cada passagem custa 80 reais
        }
    }
    return total;
}

// Função para obter o nome do passageiro de uma determinada poltrona P de uma viagem
string obterNomePassageiro(const vector<Passagem>& passagens, string poltrona) {
    for (const Passagem& passagem : passagens) {
        if (passagem.assento == poltrona) {
            return passagem.nome;
        }
    }
    return "Poltrona vazia";
}

// Função para encontrar o horário de viagem mais rentável
string encontrarHorarioMaisRentavel(const map<string, vector<Passagem>>& viagens) {
    string horarioMaisRentavel;
    float maiorArrecadacao = 0;
    for (const auto& par : viagens) {
        float arrecadacao = calcularTotalViagem(par.second);
        if (arrecadacao > maiorArrecadacao) {
            maiorArrecadacao = arrecadacao;
            horarioMaisRentavel = par.first;
        }
    }
    return horarioMaisRentavel;
}

// Função para calcular a média de idade dos passageiros
float calcularMediaIdade(const vector<Passagem>& passagens) {
    int totalIdades = 0;
    int numPassageiros = passagens.size();
    for (const Passagem& passagem : passagens) {
        totalIdades += passagem.idade;
    }
    return static_cast<float>(totalIdades) / numPassageiros;
}

int main() {
    map<string, vector<Passagem>> viagens; // Mapeia horários de viagem para passagens vendidas

    // Simulando a venda de passagens (substitua esta parte com entrada de dados real)
    Passagem passagem1 = {"A1", "01/09/2023 08:00", "123456789", "Joao", 25};
    Passagem passagem2 = {"B3", "02/09/2023 10:00", "987654321", "Maria", 30};
    viagens["01/09/2023 08:00"].push_back(passagem1);
    viagens["02/09/2023 10:00"].push_back(passagem2);

    // Exemplo de uso das funções
    cout << "Total arrecadado para a viagem 01/09/2023 08:00: " << calcularTotalViagem(viagens["01/09/2023 08:00"]) << " reais" << endl;
    cout << "Total arrecadado em setembro de 2023: " << calcularTotalMes(viagens["01/09/2023 08:00"], 9) << " reais" << endl;
    cout << "Nome do passageiro da poltrona A1 na viagem 01/09/2023 08:00: " << obterNomePassageiro(viagens["01/09/2023 08:00"], "A1") << endl;
    cout << "Horario de viagem mais rentavel: " << encontrarHorarioMaisRentavel(viagens) << endl;
    cout << "Media de idade dos passageiros da viagem 01/09/2023 08:00: " << calcularMediaIdade(viagens["01/09/2023 08:00"]) << " anos" << endl;

    return 0;
}
