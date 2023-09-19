#include <iostream>
#include <vector>
using namespace std;

struct PRODUTO {
    string codigo;
    string nome;
    float preco;
};

// Variáveis Globais
vector<PRODUTO> produtosMercado;
size_t maximoProdutos = 300;
int maximoNome = 20;
int maximoCodigo = 13;

int menuPrincipal();
void pause();
bool existeCodigo(string codigoNovo);
void inserirProduto();
void excluirProduto();
void listarProdutos();
void consultarProduto();

int main(){
    int escolhaUsuario;
    do{
        escolhaUsuario = menuPrincipal();
        switch(escolhaUsuario){
            case 1:
                inserirProduto();
                break;
            case 2:
                excluirProduto();
                break;
            case 3:
                listarProdutos();
                break;
            case 4:
                consultarProduto();
                break;
            case 5:
                cout << "Encerrando sistema..." << endl;
                break;
            default:
                break;
        }
    }while(escolhaUsuario != 5);

    return 0;
}
int menuPrincipal(){
    int opcao = 0;
    do{
        system("clear");
        cout << endl << "1. Inserir um novo produto" << endl;
        cout << "2. Excluir um produto cadastrado" << endl;
        cout << "3. Listar todos os produtos" << endl;
        cout << "4. Consultar o preço de um produto" << endl;
        cout << "5. Encerrar sistema" << endl;
        cout << "> ";

        cin >> opcao;

        if(opcao > 5 || opcao < 1){
            cout << endl << "Digite uma opção existente!" << endl;
            pause();
        }

    }while(opcao > 5 || opcao < 1);

    return opcao;
}
void pause(){
    system("read -p \"Aperte ENTER para voltar...\" saindo");
}
void inserirProduto(){
    if(produtosMercado.size() < maximoProdutos){
        PRODUTO p;
        bool codigoExistente = false;
    
        system("clear");
        cout << "== CADASTRO DE PRODUTO ==" << endl;

        do{
            cout << endl << "Código do produto (XXXXXXXXXXXXX): ";
            cin >> p.codigo;

            if(existeCodigo(p.codigo)){
                codigoExistente = true;
                cout << endl << "AVISO: Já existe um produto registrado com esse código." << endl;
                pause();
            }
            if(p.codigo.length() != 13){
                cout << endl << "AVISO: O código precisa ter 13 caracteres!" << endl;
                pause();
            }
        }while(p.codigo.length() != 13 || codigoExistente);

        do{
            cout << "Nome do produto (até 20 caracteres): ";
            cin >> p.nome;
            if(p.nome.length() > 20){
                cout << endl << "AVISO: O nome só pode ter até 20 caracteres!" << endl;
                pause();
            }
        }while(p.codigo.length() > 20);

        cout << "Preço do produto (XX.XX): ";
        cin >> p.preco;

        produtosMercado.push_back(p);
        
        cout << "Produto cadastrado com sucesso!" << endl;
        pause();
    } else{
        cout << "Muitos produtos cadastrados -> " << produtosMercado.size() << "/" << maximoProdutos << endl;
        pause();
    }
}
bool existeCodigo(string codigoNovo){
    for(PRODUTO p : produtosMercado){
        if(p.codigo == codigoNovo){
            return true;
        }
    }
    return false;
}
void excluirProduto(){
    if(produtosMercado.size() > 0){
        string codigoExcluir;
        bool codigoEncontrado = false;

        cout << "== EXCLUIR UM PRODUTO ==" << endl;
        cout << "Digite o código: ";
        cin >> codigoExcluir;
        
        for(size_t i=0; i<produtosMercado.size(); i++){
            if(produtosMercado.at(i).codigo == codigoExcluir){
                codigoEncontrado = true;
                produtosMercado.erase(produtosMercado.begin() + i);
            }
        }
        if(codigoEncontrado){
            cout << endl << "Produto excluido com sucesso!" << endl;
            pause();
        } else{
            cout << endl << "Produto não encontrado! Verifique se digitou o código corretamente." << endl;
            pause();
        }
    } else {
        cout << "Nenhum produto cadastrado!" << endl;
        pause();
    }
}
void listarProdutos(){
    if(produtosMercado.size() > 0){
        cout << endl << "== LISTA DE PRODUTOS ==" << endl;
        cout << "CODIGO\t\t" << "NOME\t\t\t" << "PREÇO" << endl;
        for(PRODUTO p : produtosMercado){
            cout << p.codigo << "\t";
            if(p.nome.length() < 10) cout << p.nome << "\t\t\t";
            else if(p.nome.length() < 15) cout << p.nome << "\t\t";
            else cout << p.nome << "\t";
            cout << p.preco << endl;
        }
        pause();
    } else {
        cout << "Nenhum produto cadastrado!" << endl;
        pause();
    }
}
void consultarProduto(){
    if(produtosMercado.size() > 0){
        string codigoConsultar;
        bool codigoEncontrado = false;

        cout << "== CONSULTAR UM PRODUTO ==" << endl;
        cout << "Digite o código: ";
        cin >> codigoConsultar;

        for(size_t i=0; i<produtosMercado.size(); i++){
            if(produtosMercado.at(i).codigo == codigoConsultar){
                codigoEncontrado = true;
                cout << "CODIGO\t\t" << "NOME\t\t\t" << "PREÇO" << endl;
                cout << produtosMercado.at(i).codigo << "\t";
                if(produtosMercado.at(i).nome.length() < 10) cout << produtosMercado.at(i).nome << "\t\t\t";
                else if(produtosMercado.at(i).nome.length() < 15) cout << produtosMercado.at(i).nome << "\t\t";
                else cout << produtosMercado.at(i).nome << "\t";
                cout << produtosMercado.at(i).preco << endl;
                pause();
            }
        }
        if(!codigoEncontrado) cout << endl << "Produto não encontrado! Verifique se digitou o código corretamente." << endl;
    } else {
        cout << "Nenhum produto cadastrado!" << endl;
        pause();
    }
}