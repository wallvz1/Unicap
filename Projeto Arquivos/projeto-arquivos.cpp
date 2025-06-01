#include <stdio.h>
#include <string.h>

#define MAX_VIDEOS 100
#define MAX_USUARIOS 100
#define MAX_FAVS 10

struct Video{
    int id;
    char titulo[100];
    char genero[50];
    int duracao;
};

struct Usuario{
    int id;
    char nome[100];
    int ids_favoritos[MAX_FAVS];
    int total_favoritos;
};

const char *ARQ_VIDEOS = "videos.dat";
const char *ARQ_USUARIOS = "usuarios.dat";

int gerar_id_video() {
    FILE *f = fopen(ARQ_VIDEOS, "rb");
    if (!f) return 1;
    Video v;
    int maior_id = 0;
    while (fread(&v, sizeof(Video), 1, f)) {
        if (v.id > maior_id) maior_id = v.id;
    }
    fclose(f);
    return maior_id + 1;
}

int gerar_id_usuario() {
    FILE *f = fopen(ARQ_USUARIOS, "rb");
    if (!f) return 1;
    Usuario u;
    int maior_id = 0;
    while (fread(&u, sizeof(Usuario), 1, f)) {
        if (u.id > maior_id) maior_id = u.id;
    }
    fclose(f);
    return maior_id + 1;
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// parte do video
void cadastrar_video() {
    FILE *f = fopen(ARQ_VIDEOS, "ab");
    if (!f) return;
    Video v;
    v.id = gerar_id_video();
    printf("\nTitulo: "); limpar_buffer(); fgets(v.titulo, 100, stdin);
    printf("Genero: "); fgets(v.genero, 50, stdin);
    printf("Duracao (min): "); scanf("%d", &v.duracao);
    fwrite(&v, sizeof(Video), 1, f);
    printf("Video cadastrado com ID: %d\n", v.id);
    fclose(f);
}

void listar_videos() {
    FILE *f = fopen(ARQ_VIDEOS, "rb");
    if (!f) return;
    Video v;
    printf("\n--- Lista de Videos ---\n");
    while (fread(&v, sizeof(Video), 1, f)) {
        printf("ID: %d | Titulo: %s | Genero: %s | Duracao: %d min\n",
               v.id, strtok(v.titulo, "\n"), strtok(v.genero, "\n"), v.duracao);
    }
    fclose(f);
}

void atualizar_video() {
    FILE *f = fopen(ARQ_VIDEOS, "rb+");
    if (!f) return;
    int id;
    printf("ID do video a atualizar: "); scanf("%d", &id);
    Video v;
    while (fread(&v, sizeof(Video), 1, f)) {
        if (v.id == id) {
            printf("Novo titulo: "); limpar_buffer(); fgets(v.titulo, 100, stdin);
            printf("Novo genero: "); fgets(v.genero, 50, stdin);
            printf("Nova duracao: "); scanf("%d", &v.duracao);
            fseek(f, -sizeof(Video), SEEK_CUR);
            fwrite(&v, sizeof(Video), 1, f);
            break;
        }
    }
    fclose(f);
}

void remover_video() {
    FILE *orig = fopen(ARQ_VIDEOS, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!orig || !temp) return;
    int id;
    printf("ID do video a remover: "); scanf("%d", &id);
    Video v;
    while (fread(&v, sizeof(Video), 1, orig)) {
        if (v.id != id) fwrite(&v, sizeof(Video), 1, temp);
    }
    fclose(orig); fclose(temp);
    remove(ARQ_VIDEOS);
    rename("temp.dat", ARQ_VIDEOS);
}

// parte do usuario
void cadastrar_usuario() {
    FILE *f = fopen(ARQ_USUARIOS, "ab");
    if (!f) return;
    Usuario u;
    u.id = gerar_id_usuario();
    printf("\nNome: "); limpar_buffer(); fgets(u.nome, 100, stdin);
    printf("Quantos favoritos (max %d): ", MAX_FAVS);
    scanf("%d", &u.total_favoritos);
    for (int i = 0; i < u.total_favoritos; i++) {
        printf("ID do video favorito %d: ", i+1);
        scanf("%d", &u.ids_favoritos[i]);
    }
    fwrite(&u, sizeof(Usuario), 1, f);
    printf("Usuario cadastrado com ID: %d\n", u.id);
    fclose(f);
}

void listar_usuarios() {
    FILE *f = fopen(ARQ_USUARIOS, "rb");
    if (!f) return;
    Usuario u;
    printf("\n--- Lista de Usuarios ---\n");
    while (fread(&u, sizeof(Usuario), 1, f)) {
        printf("ID: %d | Nome: %s | Favoritos: %d\n", u.id, strtok(u.nome, "\n"), u.total_favoritos);
    }
    fclose(f);
}

void atualizar_usuario() {
    FILE *f = fopen(ARQ_USUARIOS, "rb+");
    if (!f) return;
    int id;
    printf("ID do usuário a atualizar: "); scanf("%d", &id);
    Usuario u;
    while (fread(&u, sizeof(Usuario), 1, f)) {
        if (u.id == id) {
            printf("Novo nome: "); limpar_buffer(); fgets(u.nome, 100, stdin);
            printf("Nova quantidade de favoritos (max %d): ", MAX_FAVS); scanf("%d", &u.total_favoritos);
            for (int i = 0; i < u.total_favoritos; i++) {
                printf("ID do novo video favorito %d: ", i+1);
                scanf("%d", &u.ids_favoritos[i]);
            }
            fseek(f, -sizeof(Usuario), SEEK_CUR);
            fwrite(&u, sizeof(Usuario), 1, f);
            break;
        }
    }
    fclose(f);
}

void remover_usuario() {
    FILE *orig = fopen(ARQ_USUARIOS, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!orig || !temp) return;
    int id;
    printf("ID do usuário a remover: "); scanf("%d", &id);
    Usuario u;
    while (fread(&u, sizeof(Usuario), 1, orig)) {
        if (u.id != id) fwrite(&u, sizeof(Usuario), 1, temp);
    }
    fclose(orig); fclose(temp);
    remove(ARQ_USUARIOS);
    rename("temp.dat", ARQ_USUARIOS);
}

void relatorio_favoritos() {
    FILE *fu = fopen(ARQ_USUARIOS, "rb");
    FILE *fv = fopen(ARQ_VIDEOS, "rb");
    if (!fu || !fv) return;
    Usuario u;
    Video videos[MAX_VIDEOS];
    int total_v = 0;
    while (fread(&videos[total_v], sizeof(Video), 1, fv)) total_v++;
    rewind(fu);
    printf("\n--- Relatorio de Favoritos ---\n");
    while (fread(&u, sizeof(Usuario), 1, fu)) {
        printf("Usuario: %s\n", strtok(u.nome, "\n"));
        for (int i = 0; i < u.total_favoritos; i++) {
            for (int j = 0; j < total_v; j++) {
                if (videos[j].id == u.ids_favoritos[i]) {
                    printf("  - %s\n", strtok(videos[j].titulo, "\n"));
                    break;
                }
            }
        }
    }
    fclose(fu);
    fclose(fv);
}

int main() {
    int opcao;
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Cadastrar Video\n");
        printf("2. Listar Videos\n");
        printf("3. Atualizar Video\n");
        printf("4. Remover Video\n");
        printf("5. Cadastrar Usuario\n");
        printf("6. Listar Usuarios\n");
        printf("7. Atualizar Usuário\n");
        printf("8. Relatorio de Favoritos\n");
        printf("9. Remover Usuario\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadastrar_video(); break;
            case 2: listar_videos(); break;
            case 3: atualizar_video(); break;
            case 4: remover_video(); break;
            case 5: cadastrar_usuario(); break;
            case 6: listar_usuarios(); break;
            case 7: atualizar_usuario(); break;
            case 8: relatorio_favoritos(); break;
            case 9: remover_usuario(); break;
        }

    } while (opcao != 0);

    //Toda vez que fechar o código eu vou apagar os registros.
    remove(ARQ_VIDEOS);
    remove(ARQ_USUARIOS);

    return 0;
}
