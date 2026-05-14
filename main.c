#include <stdio.h>
#include <string.h>
#include "pessoa.h"
#include "cadastrar.h"
#include "listar.h"
#include "edicao.h"
#include "salvar.h"

#define MAX_PESSOAS 100

void aguardar_enter() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

void carregar_pessoas(Pessoa pessoas[], int *total) {
    FILE *arquivo;

    arquivo = fopen("pessoas.bin", "rb");

    if (arquivo == NULL) {
        *total = 0;
        return;
    }

    fread(total, sizeof(int), 1, arquivo);
    fread(pessoas, sizeof(Pessoa), *total, arquivo);

    fclose(arquivo);
}

int main() {
    Pessoa pessoas[MAX_PESSOAS];
    int total = 0;
    int opcao;

    carregar_pessoas(pessoas, &total);

    do {
        printf("\n=====================================\n");
        printf("         SISTEMA ATLAS - v1.0        \n");
        printf("=====================================\n");
        printf("1. Cadastrar pessoa\n");
        printf("2. Listar pessoas\n");
        printf("3. Buscar por ID\n");
        printf("4. Buscar por nome\n");
        printf("5. Editar pessoa\n");
        printf("6. Excluir pessoa\n");
        printf("0. Sair\n");
        printf("=====================================\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            opcao = -1;
        } else {
            getchar();
        }

        switch (opcao) {
            case 1:
                if (total >= MAX_PESSOAS) {
                    printf("Limite de cadastro atingido.\n");
                } else {
                    pessoas[total] = cadastrar_pessoa(total + 1);
                    total++;
                    salvar_pessoas_em_binario(pessoas, total);
                }
                aguardar_enter();
                break;
            case 2:
                listar_todos(pessoas, total);
                aguardar_enter();
                break;
            case 3: {
                int id;
                Pessoa *p;
                printf("Digite o ID: ");
                scanf("%d", &id);
                getchar();
                p = buscar_por_id(pessoas, total, id);
                if (p != NULL) {
                    printf("ID: %d\n", p->id);
                    printf("Nome: %s\n", p->nome);
                    printf("CPF: %s\n", p->cpf);
                    printf("Idade: %d\n", p->idade);
                    printf("Email: %s\n", p->email);
                    printf("Telefone: %s\n", p->telefone);
                } else {
                    printf("Pessoa nao encontrada.\n");
                }
                aguardar_enter();
                break;
            }
            case 4: {
                char nome[MAX_NOME];
                Pessoa *p;
                printf("Digite o nome: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                p = buscar_por_nome(pessoas, total, nome);
                if (p != NULL) {
                    printf("ID: %d\n", p->id);
                    printf("Nome: %s\n", p->nome);
                    printf("CPF: %s\n", p->cpf);
                    printf("Idade: %d\n", p->idade);
                    printf("Email: %s\n", p->email);
                    printf("Telefone: %s\n", p->telefone);
                } else {
                    printf("Pessoa nao encontrada.\n");
                }
                aguardar_enter();
                break;
            }
            case 5:
                editar_pessoa();
                carregar_pessoas(pessoas, &total);
                aguardar_enter();
                break;
            case 6:
                printf("Funcao inativa no momento.\n");
                aguardar_enter();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                aguardar_enter();
        }

    } while (opcao != 0);

    return 0;
}
