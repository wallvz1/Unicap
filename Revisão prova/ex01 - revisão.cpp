#include <stdio.h>
#include <string.h>
#define TAM 50

char frase[TAM];
int contaVogal(char str[]);
void maiusculaLetra(char str[]);

int main(){
    printf("Digite uma frase: \n");
    fgets(frase, sizeof(frase), stdin);

    printf("A frase digitada é: %s", frase);

    int vogais = contaVogal(frase);
    printf("A quantidade de vogais é: %d\n", vogais);
    
    maiusculaLetra(frase);
    printf("Frase nova: %s", frase);

    return 0;
}

int contaVogal(char str[]){
    int cont = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
            str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
            str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
            str[i] == 'U') {
            cont++;
        }
    }
    return cont;
}

void maiusculaLetra(char str[]){
    if (str[0] >= 'a' && str[0] <= 'z'){
        str[0] = str[0] - 32;
    }

    for(int i = 1; str[i] != '\0'; i++){
        if (str[i - 1] == ' ' && str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }
}
