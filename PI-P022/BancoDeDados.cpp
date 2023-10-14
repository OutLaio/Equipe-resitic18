#include<iostream>
#include<string>
#include<vector>

using namespace std;

#include <fstream>
#include <iostream>

class BancoDeDados {
public:
    static void salvarTarefas(const GerenciadorTarefas& gerenciador, const std::string& nomeArquivo) {
        std::ofstream arquivo(nomeArquivo);
        if (arquivo.is_open()) {
            for (const Tarefa& tarefa : gerenciador.listarTarefasPendentes()) {
                arquivo << tarefa.getDescricao() << std::endl;
            }
            arquivo.close();
            std::cout << "Tarefas salvas com sucesso!" << std::endl;
        } else {
            std::cerr << "Erro ao abrir o arquivo para salvar as tarefas." << std::endl;
        }
    }

    static void carregarTarefas(GerenciadorTarefas& gerenciador, const std::string& nomeArquivo) {
        std::ifstream arquivo(nomeArquivo);
        if (arquivo.is_open()) {
            std::string descricao;
            while (std::getline(arquivo, descricao)) {
                gerenciador.adicionarTarefa(Tarefa(descricao));
            }
            arquivo.close();
            std::cout << "Tarefas carregadas com sucesso!" << std::endl;
        } else {
            std::cerr << "Erro ao abrir o arquivo para carregar as tarefas." << std::endl;
        }
    }
};
