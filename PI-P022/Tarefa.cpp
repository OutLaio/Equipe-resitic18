#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Tarefa {
private:
    std::string descricao;
    bool concluida;

public:
    Tarefa(const std::string& descricao) : descricao(descricao), concluida(false) {}

    const std::string& getDescricao() const {
        return descricao;
    }

    bool estaConcluida() const {
        return concluida;
    }

    void marcarConcluida() {
        concluida = true;
    }

    void desmarcarConcluida() {
        concluida = false;
    }
};
