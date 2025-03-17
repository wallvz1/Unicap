#include <stdio.h>

#define TAM 100

void preencherVetor(int v[]) {
    for (int i = 0; i < TAM; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &v[i]);
    }
}

int somaPares(int v[]) {
    int soma = 0;
    for (int i = 0; i < TAM; i++) {
        if (v[i] % 2 == 0) {
            soma += v[i];
        }
    }
    return soma;
}

int produtoImpares(int v[]) {
    int produto = 1;
    int encontrouImpar = 0;
    for (int i = 0; i < TAM; i++) {
        if (v[i] % 2 != 0) {
            produto *= v[i];
            encontrouImpar = 1;
        }
    }
    return encontrouImpar ? produto : 0;
}

int menorValor(int v[]) {
    int menor = v[0];
    for (int i = 1; i < TAM; i++) {
        if (v[i] < menor) {
            menor = v[i];
        }
    }
    return menor;
}

int main() {
    int vet[TAM];

    preencherVetor(vet);

    printf("\nSomatório dos valores pares: %d \n", somaPares(vet));
    printf("Produtório dos valores ímpares: %lld \n", produtoImpares(vet));
    printf("Menor valor do vetor: %d \n", menorValor(vet));

    return 0;
}
