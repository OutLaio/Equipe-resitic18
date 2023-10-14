#include<iostream>
#include<string>
#include<vector>

using namespace std;



class GerenciadorTarefas {
private:
    std::vector<Tarefa> tarefas;

public:
    void adicionarTarefa(const Tarefa& tarefa) {
        tarefas.push_back(tarefa);
    }

    void marcarTarefaComoConcluida(int indice) {
        if (indice >= 0 && indice < tarefas.size()) {
            tarefas[indice].marcarConcluida();
        }
    }

    std::vector<Tarefa> listarTarefasPendentes() const {
        std::vector<Tarefa> pendentes;
        for (const Tarefa& tarefa : tarefas) {
            if (!tarefa.estaConcluida()) {
                pendentes.push_back(tarefa);
            }
        }
        return pendentes;
    }
};
