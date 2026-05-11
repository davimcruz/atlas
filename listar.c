#include "listar.h"
#include <stdio.h>
#include <string.h>

void listar_todos(Pessoa pessoas[], int total) {
    int i;

    if (total == 0) {
        printf("Nenhuma pessoa cadastrada.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        printf("ID: %d\n", pessoas[i].id);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("CPF: %s\n", pessoas[i].cpf);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Email: %s\n", pessoas[i].email);
        printf("Telefone: %s\n", pessoas[i].telefone);
        printf("---\n");
    }
}

Pessoa* buscar_por_id(Pessoa pessoas[], int total, int id) {
    int i;

    for (i = 0; i < total; i++) {
        if (pessoas[i].id == id)
            return &pessoas[i];
    }

    return NULL;
}

Pessoa* buscar_por_nome(Pessoa pessoas[], int total, const char* nome) {
    int i;

    for (i = 0; i < total; i++) {
        if (strstr(pessoas[i].nome, nome) != NULL)
            return &pessoas[i];
    }

    return NULL;
}
