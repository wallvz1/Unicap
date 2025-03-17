#include <stdio.h>

float descontoCategoria(int categoria) {
    switch (categoria) {
        case 1: return 10;
        case 2: return 15;
        case 3: return 8;
        default: return 0;
    }
}

float descontoQuantidade(int quantidade) {
    if (quantidade <= 2) {
        return 2;
    } else if (quantidade <= 10) {
        return 5;
    } else {
        return 10;
    }
}

float calcularPrecoTotal(float preco_unitario, int quantidade) {
    return preco_unitario * quantidade;
}

float calcularPrecoFinal(float preco_total, float desconto_total) {
    return preco_total * (1 - desconto_total / 100);
}

// Função principal
int main() {
    int categoria, quantidade;
    float preco_unitario, preco_total, desconto_cat, desconto_qtd, desconto_total, preco_final;

    printf("Informe a categoria do produto (1, 2 ou 3): ");
    scanf("%d", &categoria);

    if (categoria < 1 || categoria > 3) {
        printf("Erro: Categoria inválida! Deve ser 1, 2 ou 3.\n");
        return 1;
    }

    printf("Informe o preço do produto: ");
    scanf("%f", &preco_unitario);

    printf("Informe a quantidade comprada: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Erro: A quantidade deve ser maior que zero.\n");
        return 1;
    }

    desconto_cat = descontoCategoria(categoria);
    desconto_qtd = descontoQuantidade(quantidade);
    desconto_total = desconto_cat + desconto_qtd;

    preco_total = calcularPrecoTotal(preco_unitario, quantidade);
    preco_final = calcularPrecoFinal(preco_total, desconto_total);

    printf("\nPreço total sem desconto: R$ %.2f\n", preco_total);
    printf("Desconto aplicado: %.2f%%\n", desconto_total);
    printf("Valor economizado: R$ %.2f\n", preco_total - preco_final);
    printf("Valor final a pagar: R$ %.2f\n", preco_final);

    return 0;
}
