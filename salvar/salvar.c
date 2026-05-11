#include "salvar.h"
#include <stdio.h>

void salvar_pessoas_em_binario(Pessoa pessoas[], int total) {
    FILE *arquivo;

    arquivo = fopen("pessoas.bin", "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    fwrite(&total, sizeof(int), 1, arquivo);
    fwrite(pessoas, sizeof(Pessoa), total, arquivo);

    fclose(arquivo);

    printf("Pessoas salvas em binario com sucesso.\n");
}