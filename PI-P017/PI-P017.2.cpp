#include <iostream>
#include <string>
#include <vector>

class Produto {
public:
    Produto(int codigo, const std::string& nome, double preco)
        : codigo(codigo), nome(nome), preco(preco) {}

    int getCodigo() const { return codigo; }
    std::string getNome() const { return nome; }
    double getPreco() const { return preco; }

private:
    int codigo;
    std::string nome;
    double preco;
};

class Estoque {

private:
    vector<Produto> estoque;

public:
    void adicionarProduto(const Produto& produto, int quantidade) {
        estoque[produto.getCodigo()] += quantidade;
    }

    void removerProduto(const Produto& produto, int quantidade) {
        if (estoque.find(produto.getCodigo()) != estoque.end()) {
            estoque[produto.getCodigo()] -= quantidade;
            if (estoque[produto.getCodigo()] < 0) {
                estoque[produto.getCodigo()] = 0;
            }
        }
    }

    int getQuantidade(const Produto& produto) const {
        if (estoque.find(produto.getCodigo()) != estoque.end()) {
            return estoque.at(produto.getCodigo());
        }
        return 0;
    }

};

class CarrinhoDeCompras {
public:
    void adicionarProduto(const Produto& produto, int quantidade) {
        carrinho.push_back(std::make_pair(produto, quantidade));
    }

    void removerProduto(const Produto& produto, int quantidade) {
        for (auto it = carrinho.begin(); it != carrinho.end();) {
            if (it->first.getCodigo() == produto.getCodigo()) {
                if (it->second > quantidade) {
                    it->second -= quantidade;
                    break;
                } else {
                    it = carrinho.erase(it);
                }
            } else {
                ++it;
            }
        }
    }

    double calcularValorTotal() const {
        double total = 0.0;
        for (const auto& item : carrinho) {
            total += item.first.getPreco() * item.second;
        }
        return total;
    }

    void exibirConteudo() const {
        std::cout << "Carrinho de Compras:\n";
        for (const auto& item : carrinho) {
            std::cout << "Produto: " << item.first.getNome()
                      << " | Preço unitário: " << item.first.getPreco()
                      << " | Quantidade: " << item.second << "\n";
        }
        std::cout << "Valor Total: " << calcularValorTotal() << "\n";
    }

private:
    std::vector<std::pair<Produto, int>> carrinho;
};

int main() {
    Produto p1(1, "Arroz", 5.99);
    Produto p2(2, "Feijão", 3.99);

    Estoque estoque;
    estoque.adicionarProduto(p1, 50);
    estoque.adicionarProduto(p2, 30);

    CarrinhoDeCompras carrinho;
    carrinho.adicionarProduto(p1, 3);
    carrinho.adicionarProduto(p2, 2);

    carrinho.exibirConteudo();

    return 0;
}
