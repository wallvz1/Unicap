#include <stdio.h>
#include <string.h>
const int MAX = 100;

struct Livro{
    char titulo[30];
    char autor[30];
    char editora[30];
    int anoPublicacao[4];
    int qtdPaginas[1000];
};

void removerQuebraLinha(char str[]) {
    str[strcspn(str, "\n")] = '\0';
}

void preencherVetor(struct Livro livros[], int n){
    for (int i; i < MAX; i++){
      printf("Livro %d: ", i + 1);
      pritnf("Titulo: ");
      fgets(livros[i].titulo, sizeof(livros[i].titulo), stdin);
      quebraLinha(livros[i].titulo);
      
      printf("Autor: ");
      fgets(livros[i].autor, sizeof(livro[i].autor), stdin);
      quebraLinha(livros[i].autor);

      printf("Editora: ");
      fgets(livros[i].editora, sizeof(livros[i].editora), stdin);
      quebraLinha(livros[i].editora);

      printf("Ano de publicação: ");
      scanf("%d", livros[i].anoPublicacao);
      
      printf("Quantidade de páginas: ");
      scanf("%d", livros[i].qtdPaginas);

      getchar();

      printf("\n");
    }
}

void imprimirVetor(struct Livro livros[], int n){
    for (int i = 0; i < n; i++){
        printf("Livro %d: %s | %s | %s | %d | %d páginas", i + 1, livros[i].titulo, livros[i].autor, livros[i].editora, livros[i].anoPublicacao, livros[i].qtdPaginas);
    }
}

int buscarPorTitulo(struct Livros livros[], int n, char tituloBusca[]){
    for (int i = 0, i < n; i ++){
        if (strcmp(livros[i].titulo, tituloBusca) == 0){
            return i;
        }
    }
    return -1;
}

void ordenarPorTitulo(struct Livro livros[], int n){
    int i, fim, pos, troca;
    float chave;

    troca = 1; fim = n - 2; pos = 0;
    while (troca == 1){
        troca = 0;
        for (i = 0; i <= fim; i++){
            if (livros[i] > livros[i + 1]) {
                chave = livros[i];
                livros[i] = livros[i + 1];
                livros[i + 1] = chave;
                pos = i; troca = 1;
            }
        }
        fim = pos - 1;
    }
}

int buscaBinariaPorTitulo(struct Livro livros[], int n, char *x){
    int inicio = 0, fim = n -1, meio;

    while (inicio <= fim){
        meio = (inicio + fim) /2;
        if (strcmp(livros[meio].titulo, x) > 0) {
            fim = meio - 1;
        } else if (strcmp(livros[meio.titulo],x) < 0){
            fim = meio + 1;
        }else{
            return meio;
        }
    }
    return -1;
}

int main(){
    Livro livros[MAX];
    int n;

    printf("Digite a quantidade de livros: ");
    scanf("%d", &n);
    getchar();

    preencherVetor(livros, n);
    printf("- Antes da ordenação -\n");
    imprimirVetor(livros, n);

    ordenarPorTitulo(livros, n);
     printf("- Depois da ordenação -\n");
    imprimirVetor(livros, n);

    char busca[100];
    printf("Digite o nome do livro para busca binaria:");
    fgets(busca, sizeof(busca), stdin);
    removerQuebraLinha(busca);

    int pos =
    buscaBinariaPorTitulo(livros, n, busca);
    if pos(!= 1){
        printf("Livro econtrado na posição %d", pos);
    }else{
        prinf("Livro não encontrado.");
    }

    return 0;
}
