#include <iostream>
#include "Tarefa.h"  // Supondo que você tenha criado um arquivo "Tarefa.h" para a classe Tarefa
#include "GerenciadorTarefas.h"  // Supondo que você tenha criado um arquivo "GerenciadorTarefas.h" para a classe GerenciadorTarefas
#include "BancoDeDados.h"  // Supondo que você tenha criado um arquivo "BancoDeDados.h" para a classe BancoDeDados

int main() {
    GerenciadorTarefas gerenciador;

    // Carregar tarefas do arquivo (se houver)
    BancoDeDados::carregarTarefas(gerenciador, "tarefas.txt");

    int escolha;

    do {
        std::cout << "----- Aplicativo de Controle de Tarefas -----" << std::endl;
        std::cout << "1. Adicionar nova tarefa" << std::endl;
        std::cout << "2. Marcar tarefa como concluída" << std::endl;
        std::cout << "3. Listar tarefas pendentes" << std::endl;
        std::cout << "4. Sair e salvar tarefas" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1: {
                std::cin.ignore();  // Limpa o buffer de entrada
                std::cout << "Digite a descrição da tarefa: ";
                std::string descricao;
                std::getline(std::cin, descricao);
                gerenciador.adicionarTarefa(Tarefa(descricao));
                break;
            }
            case 2: {
                int indice;
                std::cout << "Digite o índice da tarefa a ser marcada como concluída: ";
                std::cin >> indice;
                gerenciador.marcarTarefaComoConcluida(indice);
                break;
            }
            case 3: {
                std::vector<Tarefa> pendentes = gerenciador.listarTarefasPendentes();
                std::cout << "Tarefas pendentes:" << std::endl;
                for (size_t i = 0; i < pendentes.size(); ++i) {
                    std::cout << i << ". " << pendentes[i].getDescricao() << std::endl;
                }
                break;
            }
            case 4: {
                BancoDeDados::salvarTarefas(gerenciador, "tarefas.txt");
                std::cout << "Tarefas salvas. Saindo do aplicativo." << std::endl;
                break;
            }
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
                break;
        }

    } while (escolha != 4);

    return 0;
}
