#ifndef USUARIO_H
#define USUARIO_H

#include <time.h>

#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_TELEFONE 50

typedef struct {
    int id;
    char nome[MAX_NOME];
    int idade;
    char email[MAX_EMAIL];
    char telefone[MAX_TELEFONE];
    time_t data_cadastro;
} Usuario;

#endif 