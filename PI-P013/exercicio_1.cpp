#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Passagem {
    int numeroAssento;
    string dataHora;
    string CPF;
    string nome;
    int idade;
};

struct Viagem {
    vector<Passagem> passageiros;
};

void incluirPassagem(vector<Passagem>& passagens, int assento, const string& dataHora, const string& CPF, const string& nome, int idade) {
    Passagem passageiro;
    passageiro.numeroAssento = assento;
    passageiro.dataHora = dataHora;
    passageiro.CPF = CPF;
    passageiro.nome = nome;
    passageiro.idade = idade;
    
    passagens.push_back(passageiro);
}

string localizarNomeDoPassageiro(const Viagem& viagem, int poltrona) {
    for (const Passagem& passageiro : viagem.passageiros) {
        if (passageiro.numeroAssento == poltrona) {
            return passageiro.nome;
        }
    }
    return "Poltrona vazia";
}

void imprimirTotalArrecadadoViagem(const Viagem& viagem) {
    double totalArrecadado = viagem.passageiros.size() * 80.0;
    cout << "Total arrecadado para esta viagem: R$" << fixed << setprecision(2) << totalArrecadado << endl;
}

void imprimirTotalArrecadadoMes(const vector<Viagem>& viagens, const string& mesSelecionado) {
    double arrecadacaoMes = 0.0;
    for (const Viagem& viagem : viagens) {
        for (const Passagem& passageiro : viagem.passageiros) {
            if (passageiro.dataHora.substr(5, 2) == mesSelecionado) {
                arrecadacaoMes += 80.0;
            }
        }
    }
    cout << "Total arrecadado no mes " << mesSelecionado << ": R$" << fixed << setprecision(2) << arrecadacaoMes << endl;
}

void imprimirTotalArrecadadoHorario(const vector<Viagem>& viagens, const string& horarioSelecionado) {
    double arrecadacaoHorario = 0.0;
    for (const Viagem& viagem : viagens) {
        for (const Passagem& passageiro : viagem.passageiros) {
            if (passageiro.dataHora == horarioSelecionado) {
                arrecadacaoHorario += 80.0;
            }
        }
    }
    cout << "Total arrecadado para o horario " << horarioSelecionado << ": R$" << fixed << setprecision(2) << arrecadacaoHorario << endl;
}

double calcularMediaIdade(const vector<Viagem>& viagens) {
    int totalIdades = 0;
    int totalPassageiros = 0;
    
    for (const Viagem& viagem : viagens) {
        for (const Passagem& passageiro : viagem.passageiros) {
            totalIdades += passageiro.idade;
            totalPassageiros++;
        }
    }
    
    if (totalPassageiros > 0) {
        return static_cast<double>(totalIdades) / totalPassageiros;
    } else {
        return 0.0; 
    }
}

int main() {
    vector<Viagem> viagens(10);

    
    incluirPassagem(viagens[0].passageiros, 1, "2023-09-10 10:00", "12345678901", "Laio", 23);
    incluirPassagem(viagens[0].passageiros, 2, "2023-09-10 10:00", "98765432100", "Joao", 24);
    incluirPassagem(viagens[1].passageiros, 2, "2023-09-10 13:00", "12345678901", "Brendom", 22);
    incluirPassagem(viagens[3].passageiros, 23, "2023-09-10 15:00", "98765432100", "Albert", 27);
    incluirPassagem(viagens[2].passageiros, 7, "2023-09-10 12:00", "12345678901", "Degas", 32);
    incluirPassagem(viagens[1].passageiros, 9, "2023-09-10 13:00", "98765432100", "Vitor", 30);

    imprimirTotalArrecadadoViagem(viagens[0]);
    imprimirTotalArrecadadoMes(viagens, "09");
    imprimirTotalArrecadadoHorario(viagens, "2023-09-10 10:00");

    int viagemSelecionada = 0, poltronaDesejada = 2;
    string nomePassageiro = localizarNomeDoPassageiro(viagens[viagemSelecionada], poltronaDesejada);

    if (nomePassageiro != "Poltrona vazia") {
        cout << "Nome do passageiro da poltrona " << poltronaDesejada << " na viagem " << viagemSelecionada << ": " << nomePassageiro << endl;
    } else {
        cout << "A poltrona " << poltronaDesejada << " na viagem " << viagemSelecionada << " está vazia." << endl;
    }

    double mediaIdade = calcularMediaIdade(viagens);
    
    cout << "Media de idade dos passageiros: " << fixed << setprecision(2) << mediaIdade << " anos" << endl;


    return 0;
}