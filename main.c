#include "usuario.h"
#include <stdio.h>
#include <string.h>

int main() {
  Usuario usuario;
  
  usuario.id = 1;
  strncpy(usuario.nome, "João da Silva", MAX_NOME);
  usuario.idade = 30;
  strncpy(usuario.email, "joao@dasilva.com", MAX_EMAIL);
  strncpy(usuario.telefone, "1234567890", MAX_TELEFONE);
  usuario.data_cadastro = time(NULL);
  printf("Usuario: %s, %d, %s, %s, %s\n", usuario.nome, usuario.idade,
         usuario.email, usuario.telefone, ctime(&usuario.data_cadastro));
  return 0;
}