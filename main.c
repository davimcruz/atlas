/******************************************************************************
Menu do projeto 
*******************************************************************************/
#include <stdio.h>
#include <string.h>
typedef struct {
int id;
char nome[100];
char cpf[12];
char email[100];
char telefone[15];
int ativo;
} Pessoa;
// Cadastro
void cadastrarPessoa(Pessoa pessoas[], int *quantidade) {
if (*quantidade >= 100) {
printf("Limite de cadastro atingido!\n");
return;
}
printf("\n--- Cadastro de Pessoa ---\n");
printf("Nome: ");
scanf(" %[^\n]", pessoas[*quantidade].nome);
printf("CPF: ");
scanf(" %[^\n]", pessoas[*quantidade].cpf);
printf("Email: ");
scanf(" %[^\n]", pessoas[*quantidade].email);
printf("Telefone: ");
scanf(" %[^\n]", pessoas[*quantidade].telefone);
printf("Status (1-Ativo / 0-Inativo): ");
scanf("%d", &pessoas[*quantidade].ativo);
pessoas[*quantidade].id = *quantidade + 1;
(*quantidade)++;
printf("Pessoa cadastrada com sucesso!\n");
}
// Listagem
void listarPessoas(Pessoa pessoas[], int quantidade) {
printf("\n--- Lista de Pessoas ---\n");
if (quantidade == 0) {
printf("Nenhuma pessoa cadastrada.\n");
return;
}
for (int i = 0; i < quantidade; i++) {
printf("\nPessoa %d\n", i + 1);
printf("Nome: %s\n", pessoas[i].nome);
printf("CPF: %s\n", pessoas[i].cpf);
printf("Email: %s\n", pessoas[i].email);
printf("Telefone: %s\n", pessoas[i].telefone);
if (pessoas[i].ativo == 1)
printf("Status: Ativo\n");
else
printf("Status: Inativo\n");
}
}
// Menu
int main() {
Pessoa pessoas[100];
int quantidade = 0;
int opcao;
do {
printf("\n--- MENU ---\n");
printf("Pessoas cadastradas: %d\n", quantidade);
printf("1 - Cadastrar Pessoa\n");
printf("2 - Listar Pessoas\n");
printf("0 - Sair\n");
printf("Escolha uma opcao: ");
/* Verifica se a entrada é um número inteiro */
if (scanf("%d", &opcao) != 1) {

    while (getchar() != '\n');  /* Limpa o buffer até o final da linha */

    opcao = -1;

} else {

    getchar();  /* Consome o '\n' deixado pelo scanf */

}
switch (opcao) {
case 1:
cadastrarPessoa(pessoas, &quantidade);
break;
case 2:
listarPessoas(pessoas, quantidade);
break;
case 0:
printf("Saindo...\n");
break;
default:
printf("Opcao invalida!\n");
}
} while (opcao != 0);
return 0;
}
