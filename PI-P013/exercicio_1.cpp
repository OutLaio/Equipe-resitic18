#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Passagem{
    string numeroAssento;
    string dataHora;
    string CPF;
    string nome;
    int idade;
};
struct Viagem{
    vector<Passagem> passageiros;
};

void incluirPassagem(vector<Passagem> &passagens, string assento, string dataHora, string CPF, string nome, int idade);
string encontrarPassageiro(Viagem &viagem, string poltrona);
void totalArrecadadoViagem(Viagem &viagem);
void totalArrecadadoMes(vector<Viagem> &viagens, string mes);
void totalArrecadadoHorario(vector<Viagem> &viagens, string horario);
double mediaIdade(vector<Viagem> &viagens);

int main() {
    vector<Viagem> viagens(10);

    incluirPassagem(viagens[0].passageiros, "1", "2023-12-13 10:00", "45687946520", "Brendom", 24);
    incluirPassagem(viagens[0].passageiros, "2", "2023-12-13 10:00", "78436258720", "Maria", 29);
    incluirPassagem(viagens[1].passageiros, "2", "2023-12-13 13:00", "99601325110", "João", 21);
    incluirPassagem(viagens[3].passageiros, "23", "2023-12-13 15:00", "78699957410", "Danilo", 27);
    incluirPassagem(viagens[2].passageiros, "7", "2023-12-13 12:00", "12345678901", "Vitória", 33);
    incluirPassagem(viagens[1].passageiros, "9", "2023-12-13 13:00", "98765432100", "Marcelo", 18);
    incluirPassagem(viagens[3].passageiros, "10", "2023-12-13 17:00", "98543432100", "Daniel", 20);

    totalArrecadadoViagem(viagens[1]);
    totalArrecadadoMes(viagens, "09");
    totalArrecadadoHorario(viagens, "2023-12-13 13:00");

    int viagemSelecionada = 0;
    string poltronaDesejada = "2";
    string nomePassageiro = encontrarPassageiro(viagens[viagemSelecionada], poltronaDesejada);

    if (nomePassageiro != "A poltrona está vazia.") {
        cout << "A poltrona " << poltronaDesejada << " foi reservada por " << nomePassageiro << " na viagem " << viagemSelecionada << endl;
    } else {
        cout << "A poltrona " << poltronaDesejada << " não foi reservada na viagem " << viagemSelecionada << endl;
    }

    cout << "Media de idade dos passageiros: " << setprecision(0) << mediaIdade(viagens) << " anos" << endl;

    return 0;
}

void incluirPassagem(vector<Passagem> &passagens, string assento, string dataHora, string CPF, string nome, int idade){
    Passagem passageiro;
    passageiro.numeroAssento = assento;
    passageiro.dataHora = dataHora;
    passageiro.CPF = CPF;
    passageiro.nome = nome;
    passageiro.idade = idade;
    passagens.push_back(passageiro);
}
string encontrarPassageiro(Viagem &viagem, string poltrona) {
    for (Passagem &passageiro : viagem.passageiros) {
        if (passageiro.numeroAssento == poltrona) return passageiro.nome;
    }
    return "A poltrona está vazia.";
}
void totalArrecadadoViagem(Viagem &viagem) {
    double total = viagem.passageiros.size() * 80.0;
    cout << "Total arrecadado desta viagem: " << fixed << setprecision(2) << total << " reais."<< endl;
}
void totalArrecadadoMes(vector<Viagem> &viagens, string mes) {
    double total = 0.0;
    for (Viagem viagem : viagens) {
        for (Passagem passageiro : viagem.passageiros) {
            if (passageiro.dataHora.substr(5, 2) == mes) total += 80.0;
        }
    }
    cout << "Total arrecadado no mes " << mes << ": R$" << fixed << setprecision(2) << total << endl;
}
void totalArrecadadoHorario(vector<Viagem> &viagens, string horario) {
    double total = 0.0;
    for (Viagem v : viagens) {
        for (Passagem passageiro : v.passageiros) {
            if (passageiro.dataHora == horario) {
                total += 80.0;
            }
        }
    }
    cout << "Total arrecadado para o horario " << horario << ": R$" << fixed << setprecision(2) << total << endl;
}
double mediaIdade(vector<Viagem> &viagens) {
    int idades = 0;
    int passageiros = 0;
    
    for (Viagem viagem : viagens) {
        for (Passagem passageiro : viagem.passageiros) {
            idades += passageiro.idade;
            passageiros++;
        }
    }
    if (passageiros > 0) return static_cast<double>(idades) / passageiros;
    else return 0.0;
}
