#ifndef Produto_cpp
#define Produto_cpp

#include <iostream>

using namespace std;

class Produto{
    private:
        string nome;
        string codigo;
        double preco;
    public:
        Produto(string _nome, double _preco){
            this->nome = _nome;
            this->preco = _preco;
            this->codigo = to_string(rand() % 1000);
        }
        string getNome(){
            return this->nome;
        }
        string getCodigo(){
            return this->codigo;
        }
        double getPreco(){
            return this->preco;
        }
};
#endif