#ifndef Estoque_cpp
#define Estoque_cpp

#include <iostream>
#include <vector>
#include "Produto.cpp"
using namespace std;

class Estoque{
    private:
        vector<Produto> produtosMercado;
        vector<int> quantidadeProdutos;
    public:
        Estoque(){}
        void setQuantidadeDeProdutos(Produto p, int novaQuantidade){
            for(size_t i=0; i<this->produtosMercado.size(); i++){
                if(this->produtosMercado[i].getCodigo() == p.getCodigo()){
                    this->quantidadeProdutos[i] = novaQuantidade;
                }
            }
        }
        vector<int> getQuantidadeDeProdutos(){
            return this->quantidadeProdutos;
        }
        void adicionarProduto(Produto p, int quantidade){
            this->produtosMercado.push_back(p);
            this->quantidadeProdutos.push_back(quantidade);
        }
};
#endif