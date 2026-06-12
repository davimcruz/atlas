# Atlas — Sistema de Cadastramento de Pessoas


## O que é o projeto

O Atlas é um sistema feito em C que serve para cadastrar pessoas. A ideia é simples: você consegue adicionar pessoas com nome, CPF, idade, email e telefone, e essas informações ficam salvas mesmo depois que o programa fecha. Também dá pra listar todo mundo cadastrado, buscar por nome ou ID, editar os dados de alguém e excluir registros.

Uma coisa legal que tem no sistema é o backup automático. Toda vez que você exclui alguém, o sistema salva o estado anterior antes de remover, então se você excluir por engano dá pra desfazer. Mas se quiser excluir de vez, tem essa opção também — só que aí não tem como voltar atrás.

Os dados ficam guardados em um arquivo binário chamado `pessoas.bin`. Se esse arquivo não existir ainda, o sistema começa do zero normalmente.

---

## Como rodar o projeto

**Opção 1 — Via Docker (recomendado, sem instalar dependências)**

```bash
# 1. Fazer o build da imagem
docker build -t atlas-app .

# 2. Executar o container em modo interativo
docker run -it --rm atlas-app
```

**Opção 2 — Via Makefile (requer gcc instalado)**

```bash
# Compilar
make

# Executar
./programa
```

Quando o programa abrir, vai aparecer o menu com todas as opções disponíveis:

```
=====================================
         SISTEMA ATLAS - v1.0
=====================================
1. Cadastrar pessoa
2. Listar pessoas
3. Buscar por ID
4. Buscar por nome
5. Editar pessoa
6. Excluir pessoa (backup preservado)
7. Excluir permanentemente
8. Restaurar backup
0. Sair
=====================================
```

É só digitar o número da opção e pressionar Enter. Depois de cada ação o sistema espera você pressionar Enter de novo antes de voltar pro menu.

---

## As funções do sistema

### Cadastro — `cadastrar.c`

Esse módulo cuida de tudo relacionado a cadastrar uma pessoa nova. Quando você escolhe a opção 1 no menu, ele pede cada informação uma por vez e vai validando conforme você digita. Se você errar alguma coisa, ele avisa e pede de novo — não deixa passar dado inválido.

- **`cadastrar_pessoa`** — é a função principal do módulo. Ela pede nome, CPF, idade, email e telefone, valida tudo e monta a estrutura da pessoa com um ID novo e a data e hora do cadastro.

- **`cpf_valido`** — verifica se o CPF que foi digitado tem exatamente 11 números. Se tiver letra ou tiver mais ou menos que 11 dígitos, ela retorna que é inválido.

- **`email_valido`** — só verifica se tem um @ no email. Simples assim.

- **`telefone_valido`** — igual ao CPF, verifica se tem exatamente 11 números.

- **`idade_valida`** — verifica se a idade está entre 0 e 100. Se você digitar um número negativo ou maior que 100, ele rejeita.

- **`texto_possui_apenas_numeros`** — função auxiliar que verifica se um texto tem só números, sem letras ou símbolos. É usada pelo CPF e telefone.

- **`limpar_buffer_entrada`** — toda vez que você usa `scanf` pra ler um número, fica um Enter sobrando no buffer. Essa função limpa isso pra não atrapalhar a próxima leitura.

---

### Listagem e busca — `listar.c`

Esse módulo tem as funções de exibir e encontrar registros.

- **`listar_todos`** — percorre todo o array de pessoas e imprime os dados de cada uma no terminal, separadas por uma linha. Se não tiver ninguém cadastrado, avisa que a lista está vazia.

- **`buscar_por_id`** — recebe um ID e procura no array até achar alguém com aquele ID. Se achar, retorna um ponteiro pra essa pessoa. Se não achar, retorna NULL.

- **`buscar_por_nome`** — funciona parecido, mas busca por nome. Você pode digitar só um pedaço do nome que ele já encontra. Não diferencia maiúscula de minúscula, então "ana" e "ANA" dão o mesmo resultado.

---

### Edição — `edicao.c`

- **`editar_pessoa`** — você informa o ID de quem quer editar. O sistema mostra o valor atual de cada campo e pergunta se você quer mudar. Se você só pressionar Enter sem digitar nada, o campo fica como estava. Se digitar algo novo, ele valida antes de salvar — mesmas regras do cadastro.

---

### Exclusão — `excluir.c`

Tem duas formas de excluir no sistema:

- **`excluir_pessoa`** — exclui o registro mas salva um backup antes. O sistema mostra o nome e CPF da pessoa encontrada e pede confirmação antes de remover. Se você confirmar, ele faz o backup do estado atual e depois remove. Dá pra desfazer usando a opção 8 do menu.

- **`excluir_permanente`** — exclui de vez, sem chance de recuperar. Ele remove do arquivo principal e do backup também. Tem um aviso bem claro antes de confirmar justamente por isso.

Nos dois casos, a remoção é feita deslocando todos os registros seguintes uma posição pra trás no array, sobrescrevendo o que foi removido.

---

### Salvamento — `salvar.c`

Esse módulo é responsável por tudo que envolve gravar e ler dados em arquivo.

- **`salvar_pessoas_em_binario`** — antes de salvar, faz uma cópia do arquivo atual como backup. Depois grava os dados atualizados no arquivo principal.

- **`salvar_sem_backup`** — grava direto no arquivo principal sem fazer backup. Usada na exclusão com backup, porque o backup já foi feito antes.

- **`fazer_backup`** — simplesmente copia o arquivo `pessoas.bin` para `pessoas.bak`.

- **`restaurar_backup`** — copia o `pessoas.bak` de volta pro `pessoas.bin` e recarrega os dados na memória. Pede confirmação antes de fazer isso porque substitui os dados atuais.

- **`salvar_em_arquivo`** — função base usada pelas outras. Abre o arquivo no caminho informado e grava primeiro o número total de registros e depois os dados de cada pessoa.

---

### Inicialização — `main.c`

É onde o programa começa. Quando executa, ele tenta abrir o arquivo `pessoas.bin` e carrega tudo que tiver salvo. Também percorre os registros pra descobrir qual é o maior ID existente, assim o próximo cadastro sempre recebe um ID novo sem repetir.

Depois disso entra no loop do menu, que fica rodando até você escolher a opção 0 pra sair.

---

## Arquivos gerados

| Arquivo | O que é |
|---|---|
| `pessoas.bin` | Arquivo principal com todos os dados cadastrados |
| `pessoas.bak` | Backup gerado automaticamente antes de salvar ou excluir |

---

## Observações

- O sistema aguenta no máximo 100 pessoas cadastradas ao mesmo tempo.
- Os IDs são gerados automaticamente e nunca se repetem, mesmo depois de exclusões.
- A opção 6 exclui com backup — dá pra desfazer pela opção 8.
- A opção 7 exclui permanentemente — não tem como recuperar depois.
