#include <iostream>
#include <vector>
using namespace std;

struct Passageiro{
    string numeroAssento;
    string dataHora;
    string Cpf;
    string nome;
    int idade;
};

void iniciaViagem(string dataViagem);
void cadastraPassageiro(vector<Passageiro> &passageiroCad, string numero, string data, string cpf, string nome, int idade);

int main(){

    string data1 = "19/02/2024 21:00";

    // Viagem 1
    iniciaViagem(data1);

    return 0;
}

void iniciaViagem(string dataViagem){
    vector<Passageiro> passageiros;

    cadastraPassageiro(passageiros, "19", dataViagem, "12345678910", "Bruno", 23);
    cadastraPassageiro(passageiros, "33", dataViagem, "12345678910", "Bruno", 23);
    cadastraPassageiro(passageiros, "12", dataViagem, "12345678910", "Bruno", 23);
    cadastraPassageiro(passageiros, "40", dataViagem, "12345678910", "Bruno", 23);
    cadastraPassageiro(passageiros, "1", dataViagem, "12345678910", "Bruno", 23);
    cadastraPassageiro(passageiros, "9", dataViagem, "12345678910", "Bruno", 23);
    cadastraPassageiro(passageiros, "4", dataViagem, "12345678910", "Bruno", 23);
    cadastraPassageiro(passageiros, "10", dataViagem, "12345678910", "Bruno", 23);
    cadastraPassageiro(passageiros, "32", dataViagem, "12345678910", "Bruno", 23);
    cadastraPassageiro(passageiros, "39", dataViagem, "12345678910", "Bruno", 23);
}
void cadastraPassageiro(vector<Passageiro> &passageiroCad, string numero, string data, string cpf, string nome, int idade){
    Passageiro passageiro;
    passageiro.numeroAssento = numero;
    passageiro.nome = nome;
    passageiro.dataHora = data;
    passageiro.Cpf = cpf;
    passageiro.idade = idade;
    passageiroCad.push_back(passageiro);
}