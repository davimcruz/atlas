#include "cadastrar.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void limpar_buffer_entrada() {
    int caractere;

    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}

int texto_possui_apenas_numeros(char texto[]) {
    int tamanho_texto = strlen(texto);

    for (int indice = 0; indice < tamanho_texto; indice++) {
        if (!isdigit(texto[indice])) {
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
    Pessoa nova_pessoa;

    nova_pessoa.id = proximo_id;
    nova_pessoa.data_cadastro = time(NULL);

    do {
    printf("\nDigite o nome: ");
    fgets(nova_pessoa.nome, MAX_NOME, stdin);

    if (strchr(nova_pessoa.nome, '\n') == NULL) {
        printf("Nome invalido. Digite no maximo 50 caracteres.\n");

        limpar_buffer_entrada();

        nova_pessoa.nome[0] = '\0';
    } else {
        nova_pessoa.nome[strcspn(nova_pessoa.nome, "\n")] = '\0';
    }

} while (strlen(nova_pessoa.nome) == 0);
    do {
        printf("Digite o CPF: ");
        scanf("%11s", nova_pessoa.cpf);

        if (!cpf_valido(nova_pessoa.cpf)) {
            printf("CPF invalido.\n");
        }

    } while (!cpf_valido(nova_pessoa.cpf));

    do {
        printf("Digite a idade: ");
        scanf("%d", &nova_pessoa.idade);

        if (!idade_valida(nova_pessoa.idade)) {
            printf("Idade invalida.\n");
        }

    } while (!idade_valida(nova_pessoa.idade));

    do {
        printf("Digite o email: ");
        scanf("%49s", nova_pessoa.email);

        if (!email_valido(nova_pessoa.email)) {
            printf("Email invalido.\n");
        }

    } while (!email_valido(nova_pessoa.email));

    do {
        printf("Digite o telefone: ");
        scanf("%11s", nova_pessoa.telefone);

        if (!telefone_valido(nova_pessoa.telefone)) {
            printf("Telefone invalido.\n");
        }

    } while (!telefone_valido(nova_pessoa.telefone));

    limpar_buffer_entrada();

    return nova_pessoa;
}
