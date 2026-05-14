#include "edicao.h"
#include "pessoa.h"
#include "cadastrar.h"
#include <stdio.h>
#include <string.h>

extern void limpar_buffer_entrada();
extern int email_valido(char email[]);
extern int telefone_valido(char telefone[]);

void editar_pessoa() {
    FILE *arquivo;
    Pessoa pessoa;
    int id_procurado;
    int pessoa_encontrada = 0;

    arquivo = fopen("pessoas.bin", "rb+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("\nDigite o ID da pessoa que deseja editar: ");
    scanf("%d", &id_procurado);
    limpar_buffer_entrada();

    fseek(arquivo, sizeof(int), SEEK_SET);

    while (fread(&pessoa, sizeof(Pessoa), 1, arquivo)) {
        if (pessoa.id == id_procurado) {
            pessoa_encontrada = 1;

            printf("\nNovo nome: ");
            fgets(pessoa.nome, MAX_NOME, stdin);
            pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';

            do {
                printf("Novo email: ");
                scanf("%49s", pessoa.email);
                if (!email_valido(pessoa.email))
                    printf("Email invalido.\n");
            } while (!email_valido(pessoa.email));

            do {
                printf("Novo telefone: ");
                scanf("%11s", pessoa.telefone);
                if (!telefone_valido(pessoa.telefone))
                    printf("Telefone invalido.\n");
            } while (!telefone_valido(pessoa.telefone));

            fseek(arquivo, -(long)sizeof(Pessoa), SEEK_CUR);
            fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);

            printf("\nPessoa editada com sucesso.\n");
            break;
        }
    }

    if (!pessoa_encontrada)
        printf("\nPessoa nao encontrada.\n");

    fclose(arquivo);
}
