#ifndef CADASTRAR_H
#define CADASTRAR_H

#include "pessoa.h"

void limpar_buffer_entrada();
int email_valido(char email[]);
int telefone_valido(char telefone[]);
Pessoa cadastrar_pessoa(int proximo_id);

#endif