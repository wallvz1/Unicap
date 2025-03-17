#include <stdio.h>

float calcularMulta(float valor_conta, float multa) {
    return (multa / 100) * valor_conta;
}

float calcularJuros(float valor_conta, float juros_mensal, int dias_atraso) {
    return (juros_mensal / 100) * (dias_atraso / 30.0) * valor_conta;
}

float calcularValorFinal(float valor_conta, float multa, float juros_mensal, int dias_atraso) {
    float valor_multa = calcularMulta(valor_conta, multa);
    float valor_juros = calcularJuros(valor_conta, juros_mensal, dias_atraso);
    return valor_conta + valor_multa + valor_juros;
}

// Função principal
int main() {
    float valor_conta, multa, juros_mensal, valor_final;
    int dias_atraso;

    printf("Informe o valor da conta: ");
    scanf("%f", &valor_conta);

    printf("Informe o percentual da multa: ");
    scanf("%f", &multa);

    printf("Informe o percentual dos juros mensais: ");
    scanf("%f", &juros_mensal);

    printf("Informe a quantidade de dias em atraso (máximo 45): ");
    scanf("%d", &dias_atraso);

    if (dias_atraso < 0 || dias_atraso > 45) {
        printf("Erro: A quantidade de dias em atraso deve estar entre 0 e 45.\n");
        return 1;
    }

    valor_final = calcularValorFinal(valor_conta, multa, juros_mensal, dias_atraso);
    printf("\nValor final a pagar: R$ %.2f\n", valor_final);

    return 0;
}
