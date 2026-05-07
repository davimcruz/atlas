#include "pessoa.h"
#include <stdio.h>
#include <string.h>

int main() {
  Pessoa pessoa;
  
  pessoa.id = 1;
  strncpy(pessoa.nome, "João da Silva", MAX_NOME);
  pessoa.idade = 30;
  strncpy(pessoa.email, "joao@dasilva.com", MAX_EMAIL);
  strncpy(pessoa.telefone, "1234567890", MAX_TELEFONE);
  pessoa.data_cadastro = time(NULL);
  printf("Pessoa: %s, %d, %s, %s, %s\n", pessoa.nome, pessoa.idade,
         pessoa.email, pessoa.telefone, ctime(&pessoa.data_cadastro));
  return 0;
}