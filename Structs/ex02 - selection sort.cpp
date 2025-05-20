#include <stdio.h>
#include <string.h>

const int TAM = 5;

struct Produto {
    int codigo;
    char nome[50];
    double preco;
};

void removerEspaco(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void selectionSortPreco(struct Produto p[], int n) {
    int i, j, min;
    struct Produto temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (p[j].preco < p[min].preco) {
                min = j;
            }
        }

        if (min != i) {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
    }
}

void imprimirProdutos(struct Produto p[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Codigo: %d\n", p[i].codigo);
        printf("Nome: %s\n", p[i].nome);
        printf("Preco: %.2f\n\n", p[i].preco);
    }
}

int main() {
    struct Produto produtos[TAM];
    int i;

    printf("=== Cadastro de Produtos ===\n");
    for (i = 0; i < TAM; i++) {
        printf("\n- Produto %d -:\n", i + 1);

        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);

        printf("Nome: ");
        getchar(); 
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        removerEspaco(produtos[i].nome);

        printf("Preco: ");
        scanf("%lf", &produtos[i].preco);
    }

    printf("\n--- Produtos antes da ordenacao ---\n");
    imprimirProdutos(produtos, TAM);

    selectionSortPreco(produtos, TAM);

    printf("--- Produtos apos ordenacao por preco (crescente) ---\n");
    imprimirProdutos(produtos, TAM);

    return 0;
}
