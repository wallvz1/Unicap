#include <stdio.h>

void gerarProgressaoAritmetica(int inicio, int incremento, int termos) {
    int valor = inicio;
    
    printf("\nProgressão Aritmética: ");
    for (int i = 0; i < termos; i++) {
        printf("%d ", valor);
        valor += incremento;
    }
    printf("\n");
}

int main() {
    int inicio, incremento, termos;

    printf("Informe o valor inicial: ");
    scanf("%d", &inicio);

    printf("Informe o fator de incremento: ");
    scanf("%d", &incremento);

    printf("Informe a quantidade de termos: ");
    scanf("%d", &termos);

    if (termos <= 0) {
        printf("Erro: A quantidade de termos deve ser maior que zero.\n");
        return 1;
    }

    gerarProgressaoAritmetica(inicio, incremento, termos);

    return 0;
}
