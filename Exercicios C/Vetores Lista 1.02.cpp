#include <stdio.h>

#define TAM 1000

void preencherContagem(int cont[]) {
    int num, i;
    for (i = 0; i < TAM; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &num);
        cont[num % 10]++; 
    }
}

void exibirTabela(int cont[]) {
    int i;
    printf("\nDígito final | Quantidade\n");
    printf("------------------------\n");
    for (i = 0; i < 10; i++) {
        printf("     %d      |    %d\n", i, cont[i]);
    }
}

int main() {
    int cont[10] = {0}; 

    preencherContagem(cont);
    exibirTabela(cont);

    return 0;
}
