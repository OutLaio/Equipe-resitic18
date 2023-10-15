#include <iostream>
#include <iomanip>
#include "Produto.cpp"
#include "CarrinhoDeCompras.cpp"
#include "Estoque.cpp"
using namespace std;

int main(){
    // Primeiro Teste
    Produto p1("Maçã", 2.5);
    Produto p2("Arroz", 10.0);
    Produto p3("Leite", 4.0);

    Estoque mercado;
    mercado.adicionarProduto(p1, 10);
    mercado.adicionarProduto(p2, 10);
    mercado.adicionarProduto(p3, 10);

    CarrinhoDeCompras carrinho;
    carrinho.adicionarProduto(p1, 3);
    carrinho.adicionarProduto(p2, 2);
    carrinho.adicionarProduto(p3, 1);
    double valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total da compra: " << valorTotal << endl;

    // Segundo Teste
    carrinho.removerProduto(p2, 1);
    valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total após remoção: " << valorTotal << endl;

    // Terceiro Teste
    carrinho.esvaziarCarrinho();
    valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total após esvaziar o carrinho: " << fixed << setprecision(1) << valorTotal << defaultfloat << endl;

    // Quarto Teste
    Produto p4("Chocolate", 3.0);
    
    mercado.adicionarProduto(p4, 5);

    carrinho.adicionarProduto(p4, 10); // Supondo estoque limitado a 5 unidades
    cout << "Quantidade de chocolates no carrinho: " << carrinho.getQuantidadeProduto(p4) << endl;

    carrinho.adicionarProduto(p1, 2);
    carrinho.adicionarProduto(p2, 3);
    carrinho.adicionarProduto(p3, 1);
    carrinho.adicionarProduto(p4, 2);
    
    carrinho.exibirCarrinho();

    return 0;
}