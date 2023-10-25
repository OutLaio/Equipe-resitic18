#include <iostream>
using namespace std;

double celsiusParaFahrenheit(double temperaturaCelsius) {
    return (temperaturaCelsius * 9.0 / 5.0) + 32.0;
}

void converterTemperatura() {
    double temperaturaCelsius;
    
    cout << "Digite a temperatura em Celsius: ";
    cin >> temperaturaCelsius;
    
    double temperaturaFahrenheit = celsiusParaFahrenheit(temperaturaCelsius);
    
    cout << "A temperatura em Fahrenheit eh: " << temperaturaFahrenheit << " F" << endl;
}

int main() {
    converterTemperatura();
    
    return 0;
}