#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <vector>

bool ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool dataValida(int dia, int mes, int ano) {
    if (ano < 1 || mes < 1 || mes > 12 || dia < 1)
        return false;

    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (ehBissexto(ano))
        diasNoMes[2] = 29;

    return dia <= diasNoMes[mes];
}

void imprimeDataPorExtenso(int dia, int mes, int ano) {
    char *nomesDosMeses[] = {
        "Janeiro", "Fevereiro", "Março", "Abril",
        "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    printf("%d de %s de %d\n", dia, nomesDosMeses[mes - 1], ano);
}

int main() {
    char data[20];
    printf("Digite uma data no formato dd/mm/aaaa: ");
    scanf("%s", data);

    char *token = strtok(data, "/");
    int i = 0;
    char *partes[3];

    while (token != NULL) {
        partes[i++] = token;
        token = strtok(NULL, "/");
    }

    if (i < 3) {
        printf("Formato de data inválido.\n");
        return 1;
    }

    int dia = atoi(partes[0]);
    int mes = atoi(partes[1]);
    int ano = atoi(partes[2]);

    if (dataValida(dia, mes, ano)) {
        imprimeDataPorExtenso(dia, mes, ano);
    } else {
        printf("Data inválida.\n");
    }

    return 0;
}
