#include "salvar.h"
#include <stdio.h>

void salvar_pessoas_em_binario(Pessoa pessoas[], int total) {
    FILE *f = fopen(DB_PATH, "wb");

    if (f == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    fwrite(&total, sizeof(int), 1, f);
    
    if (total > 0) {
        fwrite(pessoas, sizeof(Pessoa), total, f);
    }

    fclose(f);
    printf("Dados salvos.\n");
}