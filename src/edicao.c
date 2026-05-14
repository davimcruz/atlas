#include "edicao.h"
#include "pessoa.h"
#include "cadastrar.h"
#include "salvar.h"
#include <stdio.h>
#include <string.h>

void editar_pessoa(Pessoa pessoas[], int total) {
    int id;
    int indice = -1;

    printf("\nID para editar: ");
    scanf("%d", &id);
    limpar_buffer_entrada();

    for (int i = 0; i < total; i++) {
        if (pessoas[i].id == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\nNao encontrado.\n");
        return;
    }

    Pessoa *p = &pessoas[indice];
    char buf[100];

    printf("\nNovo nome (Enter para manter '%s'): ", p->nome);
    fgets(buf, sizeof(buf), stdin);
    if (buf[0] != '\n') {
        buf[strcspn(buf, "\n")] = '\0';
        strcpy(p->nome, buf);
    }

    do {
        printf("Novo email (Enter para manter '%s'): ", p->email);
        fgets(buf, sizeof(buf), stdin);
        if (buf[0] == '\n') {
            break;
        }
        
        buf[strcspn(buf, "\n")] = '\0';
        if (email_valido(buf)) {
            strcpy(p->email, buf);
            break;
        }
        printf("Email invalido.\n");
    } while (1);

    do {
        printf("Novo telefone (Enter para manter '%s'): ", p->telefone);
        fgets(buf, sizeof(buf), stdin);
        if (buf[0] == '\n') {
            break;
        }

        buf[strcspn(buf, "\n")] = '\0';
        if (telefone_valido(buf)) {
            strcpy(p->telefone, buf);
            break;
        }
        printf("Telefone invalido.\n");
    } while (1);

    salvar_pessoas_em_binario(pessoas, total);
    printf("\nAtualizado com sucesso.\n");
}
