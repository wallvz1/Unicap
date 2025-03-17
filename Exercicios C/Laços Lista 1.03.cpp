#include <stdio.h>

void lerDados(char *sexo, int *idade, float *peso) {
    printf("\nInforme o sexo (M/F): ");
    scanf(" %c", sexo);
    
    printf("Informe a idade: ");
    scanf("%d", idade);
    
    printf("Informe o peso (kg): ");
    scanf("%f", peso);
}

void calcularEstatisticas(int total_pessoas) {
    int idade_mais_pesada = 0, total_mulheres = 0, mulheres_menos_50kg = 0;
    float soma_peso_homens = 0;
    int homens_menos_30 = 0;
    float maior_peso = 0;

    for (int i = 0; i < total_pessoas; i++) {
        char sexo;
        int idade;
        float peso;

        lerDados(&sexo, &idade, &peso);

        if (peso >= maior_peso) {
            maior_peso = peso;
            idade_mais_pesada = idade;
        }

        if (sexo == 'M' || sexo == 'm') {
            if (idade < 30) {
                soma_peso_homens += peso;
                homens_menos_30++;
            }
        }

        if (sexo == 'F' || sexo == 'f') {
            total_mulheres++;
            if (peso < 50) {
                mulheres_menos_50kg++;
            }
        }
    }

    float media_peso_homens = (homens_menos_30 > 0) ? (soma_peso_homens / homens_menos_30) : 0;  
    float percentual_mulheres = (total_mulheres > 0) ? ((mulheres_menos_50kg * 100.0) / total_mulheres) : 0;

    printf("\nIdade da pessoa mais pesada: %d anos\n", idade_mais_pesada);
    printf("Média de peso dos homens com menos de 30 anos: %.2f kg\n", media_peso_homens);
    printf("Percentual de mulheres com menos de 50 kg: %.2f%%\n", percentual_mulheres);
}

int main() {
    int total_pessoas;

    printf("Informe a quantidade de pessoas: ");
    scanf("%d", &total_pessoas);

    if (total_pessoas <= 0) {
        printf("Erro: O número de pessoas deve ser maior que zero.\n");
        return 1;
    }

    calcularEstatisticas(total_pessoas);

    return 0;
}
