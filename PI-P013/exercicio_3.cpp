#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// Definicao da estrutura Produto
struct Produto {
    string codigo;
    string nome;
    double preco;
};

// Funcao para inserir um novo produto
bool inserirProduto(vector<Produto>& produtos, const Produto& novoProduto) {
    // Verificar se ja existe um produto com o mesmo codigo ou nome
    for (const Produto& produto : produtos) {
        if (produto.codigo == novoProduto.codigo || produto.nome == novoProduto.nome) {
            cout << "Produto com codigo ou nome duplicado. Nao e possivel inserir." << endl;
            system("pause");
            return false;
        }
    }

    // Se nao ha duplicatas, insira o novo produto
    produtos.push_back(novoProduto);
    cout << "Produto inserido com sucesso." << endl;
    system("pause");
    return true;
}

// Funcao para excluir um produto pelo codigo
bool excluirProduto(vector<Produto>& produtos, const string& codigo) {
    for (size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i].codigo == codigo) {
            produtos.erase(produtos.begin() + i);
            cout << "Produto excluido com sucesso." << endl;
            system("pause");
            return true;
        }
    }
    cout << "Produto nao encontrado." << endl;
    system("pause");
    return false;
}

// Funcao para listar todos os produtos
void listarProdutos(const vector<Produto>& produtos) {
    system("cls");
    cout << "Lista de produtos:" << endl;
    for (const Produto& produto : produtos) {
        cout << "Codigo: " << produto.codigo << " | Nome: " << produto.nome << " | Preco: R$" << fixed << setprecision(2) << produto.preco << endl;
    }
    system("pause");
}

// Funcao para consultar o preco de um produto pelo codigo
void consultarPreco(const vector<Produto>& produtos, const string& codigo) {
    for (const Produto& produto : produtos) {
        if (produto.codigo == codigo) {
            cout << "Preco de " << produto.nome << ": R$" << fixed << setprecision(2) << produto.preco << endl;
            system("pause");
            return;
        }
    }
    cout << "Produto nao encontrado." << endl;
    system("pause");
}

void op1(vector<Produto> *produtos){
    Produto novoProduto;
    system("cls");
    cout << "Codigo do produto (13 caracteres): ";
    cin.ignore();
    getline(cin, novoProduto.codigo);
    cout << "Nome do produto (ate 20 caracteres): ";
    getline(cin, novoProduto.nome);
    cout << "Preco do produto (com duas casas decimais): R$";
    cin >> novoProduto.preco;
    inserirProduto(*produtos, novoProduto);
}

void op2(vector<Produto> *produtos){
    string codigoExclusao;
    system("cls");
    cout << "Digite o codigo do produto a ser excluido: ";
    cin.ignore();
    getline(cin, codigoExclusao);
    excluirProduto(*produtos, codigoExclusao);
}

void op4(vector<Produto> *produtos){
    string codigoConsulta;
    system("cls");
    cout << "Digite o codigo do produto para consultar o preco: ";
    cin.ignore();
    getline(cin, codigoConsulta);
    consultarPreco(*produtos, codigoConsulta);
}

int main() {
    vector<Produto> produtos;
    char opcao;

    while (true) {
        system("cls");
        cout << "Menu:" << endl;
        cout << "1. Inserir um novo produto" << endl;
        cout << "2. Excluir um produto cadastrado" << endl;
        cout << "3. Listar todos os produtos" << endl;
        cout << "4. Consultar o preco de um produto" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case '1':
                op1(&produtos);
                break;
            case '2':
                op2(&produtos);
                break;
            case '3':
                listarProdutos(produtos);
                break;
            case '4':
                op4(&produtos);
                break;
            case '5':
                cout << "Encerrando o programa." << endl;
                return 0;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}