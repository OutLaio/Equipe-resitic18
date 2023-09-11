#include <iostream>
using namespace std;

double celsiusFahrenheit(double temperaturaCelsius);
void recebeTemp();

int main() {

    recebeTemp();

    return 0;
}

double celsiusFahrenheit(double temperaturaCelsius) {
    return (temperaturaCelsius * 9.0 / 5.0) + 32.0;
}
void recebeTemp() {
    double tempCelsius;
    double tempFahrenheit;
    
    cout << "Digite a temperatura em Celsius (C): ";
    cin >> tempCelsius;
    
    tempFahrenheit = celsiusFahrenheit(tempCelsius);
    
    cout << tempCelsius << "°C em Fahrenheit é: " << tempFahrenheit << "F" << endl;
}