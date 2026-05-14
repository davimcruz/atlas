#include "excluir.h"
#include "salvar.h"
#include <stdio.h>
#include <string.h>

void excluir_pessoa(Pessoa pessoas[], int *total) {
    int id;
    int idx = -1;

    printf("\nID para excluir: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    for (int i = 0; i < *total; i++) {
        if (pessoas[i].id == id) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Nao encontrado.\n");
        return;
    }

    for (int i = idx; i < *total - 1; i++) {
        pessoas[i] = pessoas[i + 1];
    }

    (*total)--;
    salvar_pessoas_em_binario(pessoas, *total);

    printf("Excluido com sucesso.\n");
}
