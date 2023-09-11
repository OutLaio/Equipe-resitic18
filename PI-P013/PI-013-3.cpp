#include <iostream>
#include <string>
#include <iomanip>

const int MAX_PRODUTOS = 300;
const int CODIGO_LENGTH = 13;
const int NOME_LENGTH = 20;

struct Produto {
    std::string codigo;
    std::string nome;
    double preco;
};

struct Supermercado {
    Produto produtos[MAX_PRODUTOS];
    int numProdutos = 0;

    bool codigoExiste(const std::string& codigo) {
        for (int i = 0; i < numProdutos; i++) {
            if (produtos[i].codigo == codigo) {
                return true;
            }
        }
        return false;
    }

    bool nomeExiste(const std::string& nome) {
        for (int i = 0; i < numProdutos; i++) {
            if (produtos[i].nome == nome) {
                return true;
            }
        }
        return false;
    }

    void inserirProduto() {
        if (numProdutos >= MAX_PRODUTOS) {
            std::cout << "Limite de produtos atingido!" << std::endl;
            return;
        }

        Produto novoProduto;
        std::cout << "Digite o codigo do produto (13 caracteres): ";
        std::cin.ignore();
        std::getline(std::cin, novoProduto.codigo);

        if (novoProduto.codigo.length() != CODIGO_LENGTH) {
            std::cout << "Codigo deve ter 13 caracteres!" << std::endl;
            return;
        }

        if (codigoExiste(novoProduto.codigo)) {
            std::cout << "Cadigo ja existe!" << std::endl;
            return;
        }

        std::cout << "Digite o nome do produto (máximo 20 caracteres): ";
        std::getline(std::cin, novoProduto.nome);

        if (novoProduto.nome.length() > NOME_LENGTH) {
            std::cout << "Nome excede o tamanho máximo!" << std::endl;
            return;
        }

        if (nomeExiste(novoProduto.nome)) {
            std::cout << "Nome já existe!" << std::endl;
            return;
        }

        std::cout << "Digite o preço do produto: ";
        std::cin >> novoProduto.preco;

        produtos[numProdutos] = novoProduto;
        numProdutos++;

        std::cout << "Produto cadastrado com sucesso!" << std::endl;
    }

    void excluirProduto() {
        std::string codigo;
        std::cout << "Digite o codigo do produto a ser excluido: ";
        std::cin.ignore();
        std::getline(std::cin, codigo);

        for (int i = 0; i < numProdutos; i++) {
            if (produtos[i].codigo == codigo) {
                for (int j = i; j < numProdutos - 1; j++) {
                    produtos[j] = produtos[j + 1];
                }
                numProdutos--;
                std::cout << "Produto excluido com sucesso!" << std::endl;
                return;
            }
        }

        std::cout << "Produto nao encontrado!" << std::endl;
    }

    void listarProdutos() {
        std::cout << "Lista de Produtos:" << std::endl;
        std::cout << std::left << std::setw(15) << "Codigo" << std::setw(25) << "Nome" << std::setw(10) << "Preço" << std::endl;
        for (int i = 0; i < numProdutos; i++) {
            std::cout << std::left << std::setw(15) << produtos[i].codigo << std::setw(25) << produtos[i].nome << std::fixed << std::setprecision(2) << std::setw(10) << produtos[i].preco << std::endl;
        }
    }

    void consultarPreco() {
        std::string codigo;
        std::cout << "Digite o codigo do produto para consultar o preço: ";
        std::cin.ignore();
        std::getline(std::cin, codigo);

        for (int i = 0; i < numProdutos; i++) {
            if (produtos[i].codigo == codigo) {
                std::cout << "Preco do produto: " << std::fixed << std::setprecision(2) << produtos[i].preco << std::endl;
                return;
            }
        }

        std::cout << "Produto não encontrado!" << std::endl;
    }
};

int main() {
    Supermercado supermercado;
    int escolha;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Inserir um novo produto" << std::endl;
        std::cout << "2. Excluir um produto cadastrado" << std::endl;
        std::cout << "3. Listar todos os produtos" << std::endl;
        std::cout << "4. Consultar o preço de um produto" << std::endl;
        std::cout << "5. Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                supermercado.inserirProduto();
                break;
            case 2:
                supermercado.excluirProduto();
                break;
            case 3:
                supermercado.listarProdutos();
                break;
            case 4:
                supermercado.consultarPreco();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Opcao invalida!" << std::endl;
                break;
        }
    }

    return 0;
}
