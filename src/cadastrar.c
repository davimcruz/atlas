#include "cadastrar.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void limpar_buffer_entrada() {
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF);
}

int texto_possui_apenas_numeros(char texto[]) {
    int tamanho = strlen(texto);

    for (int i = 0; i < tamanho; i++) {
        if (!isdigit(texto[i])) {
            return 0;
        }
    }

    return 1;
}

int cpf_valido(char cpf[]) {
    return strlen(cpf) == 11 && texto_possui_apenas_numeros(cpf);
}

int email_valido(char email[]) {
    return strchr(email, '@') != NULL;
}

int telefone_valido(char telefone[]) {
    return strlen(telefone) == 11 && texto_possui_apenas_numeros(telefone);
}

int idade_valida(int idade) {
    return idade >= 0 && idade <= 100;
}

Pessoa cadastrar_pessoa(int proximo_id) {
    Pessoa p;

    p.id = proximo_id;
    p.data_cadastro = time(NULL);

    printf("\nDigite o nome: ");
    fgets(p.nome, MAX_NOME, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';

    do {
        printf("Digite o CPF (11 digitos): ");
        scanf("%11s", p.cpf);
        if (!cpf_valido(p.cpf)) {
            printf("CPF invalido.\n");
        }
    } while (!cpf_valido(p.cpf));

    do {
        printf("Digite a idade: ");
        if (scanf("%d", &p.idade) != 1) {
            printf("Idade invalida.\n");
            limpar_buffer_entrada();
            p.idade = -1;
        } else {
            limpar_buffer_entrada();
            if (!idade_valida(p.idade)) {
                printf("Idade invalida.\n");
            }
        }
    } while (!idade_valida(p.idade));

    do {
        printf("Digite o email: ");
        scanf("%49s", p.email);
        if (!email_valido(p.email)) {
            printf("Email invalido.\n");
        }
    } while (!email_valido(p.email));

    do {
        printf("Digite o telefone (11 digitos): ");
        scanf("%11s", p.telefone);
        if (!telefone_valido(p.telefone)) {
            printf("Telefone invalido.\n");
        }
    } while (!telefone_valido(p.telefone));

    limpar_buffer_entrada();

    return p;
}
