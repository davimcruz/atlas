#ifndef PESSOA_H
#define PESSOA_H

#include <time.h>

#define MAX_NOME 51
#define MAX_EMAIL 50
#define MAX_TELEFONE 50
#define MAX_CPF 14

typedef struct {
    int id;
    char cpf[MAX_CPF];
    char nome[MAX_NOME];
    int idade;
    char email[MAX_EMAIL];
    char telefone[MAX_TELEFONE];
    time_t data_cadastro;
} Pessoa;

#endif 