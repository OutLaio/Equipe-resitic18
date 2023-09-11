#include <iostream>
using namespace std;

// Função para converter temperatura de Celsius para Fahrenheit
double converterCelsiusParaFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

int main() {
    // Teste da função de conversão com diferentes valores
    double celsius1 = 0.0;
    double celsius2 = 25.0;
    double celsius3 = -10.0;

    // Realiza as conversões e exibe os resultados
    cout << "0 graus Celsius equivale a " << converterCelsiusParaFahrenheit(celsius1) << " graus Fahrenheit." << endl;
    cout << "25 graus Celsius equivale a " << converterCelsiusParaFahrenheit(celsius2) << " graus Fahrenheit." << endl;
    cout << "-10 graus Celsius equivale a " << converterCelsiusParaFahrenheit(celsius3) << " graus Fahrenheit." << endl;

    return 0;
}
