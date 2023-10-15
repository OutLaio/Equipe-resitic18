#ifndef CarrinhDeCompras_cpp
#define CarrinhoDeCompras_cpp

#include <iostream>
#include <vector>
#include "Produto.cpp"
#include "Estoque.cpp"

using namespace std;

class CarrinhoDeCompras : Estoque{
    private:
        vector<Produto> carrinhoProdutos;
        vector<int> quantidadeProdutos;
    public:
        CarrinhoDeCompras(){}
        int getQuantidadeProduto(Produto p){
            for(size_t i=0; i<this->carrinhoProdutos.size(); i++){
                if(this->carrinhoProdutos[i].getCodigo() == p.getCodigo()){
                    return quantidadeProdutos[i];
                }
            }
            cout << "Produto não encontrado" << endl;
            return 0;
        }
        void adicionarProduto(Produto p, int quantidade){
            int quantidadeProdutoEstoque = getQuantidadeDeProdutos()[posicaoProduto(p)];

            this->carrinhoProdutos.push_back(p);

            if(quantidade > quantidadeProdutoEstoque){
                this->quantidadeProdutos.push_back(quantidadeProdutoEstoque);
            } else this->quantidadeProdutos.push_back(quantidade);
        }
        void removerProduto(Produto p, int quantidade){
            for(size_t i=0; i<this->carrinhoProdutos.size(); i++){
                if(this->carrinhoProdutos[i].getCodigo() == p.getCodigo()){
                    if(quantidadeProdutos[i] == 1){
                        if(quantidade > 1) cout << "A quantidade pedida é maior que a quantidade no carrinho." << endl;
                        carrinhoProdutos.erase(carrinhoProdutos.begin()+i);
                        quantidadeProdutos.erase(quantidadeProdutos.begin()+i);
                    } else if(quantidadeProdutos[i] > 1){
                        quantidadeProdutos[i]--;
                    }
                }
            }
        }
        void esvaziarCarrinho(){
            carrinhoProdutos.erase(carrinhoProdutos.begin(), carrinhoProdutos.end());
            quantidadeProdutos.erase(quantidadeProdutos.begin(), quantidadeProdutos.end());
        }
        double calcularValorTotal(){
            double valorTotal = 0.0;
            for(size_t i=0; i<this->carrinhoProdutos.size(); i++){
                valorTotal += carrinhoProdutos[i].getPreco() * quantidadeProdutos[i];
            }
            return valorTotal;
        }
        int posicaoProduto(Produto p){
            for(size_t i=0; i<this->carrinhoProdutos.size(); i++){
                if(this->carrinhoProdutos[i].getCodigo() == p.getCodigo()){
                    return i;
                }
            }
        }
        void exibirCarrinho(){
            cout << "Carrinho de Compras: " << endl;
            for(size_t i=0; i<carrinhoProdutos.size(); i++){
                cout << "- " << carrinhoProdutos[i].getNome() 
                     << " (" << carrinhoProdutos[i].getPreco()
                     << ") x " << quantidadeProdutos[i] << endl;
            }
        }
};
#endif