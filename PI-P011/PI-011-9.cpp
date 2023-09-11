#include <iostream>

float calc_serie(int N) {
    float S = 0.0;

    for (int i = 1; i <= N; i++) {
        S += static_cast<float>(i) / (N - 1);
    }

    return S;
}

int main() {
    int N;
    std::cout << "Digite o valor de N: ";
    std::cin >> N;

    if (N < 2) {
        std::cout << "N deve ser maior ou igual a 2." << std::endl;
    } else {
        float resultado = calc_serie(N);
        std::cout << "O valor da serie S é: " << resultado << std::endl;
    }

    return 0;
}
