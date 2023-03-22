#include "myalunos.h"
#include "myfiles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu() {
  int opcao;
  printf("--- Menu Principal ---\n");
  printf("1 - Insere aluno\n");
  printf("2 - Listar alunos\n");
  printf("3 - Salvar em arquivo\n");
  printf("0 - SAIR\n");
  printf("Qual a sua opção? ");
  scanf("%d", &opcao);
  return opcao;
}

int main() {
  int opcao;
  /* inicia uma lista de alunos vazia */
  Node *lista_alunos = NULL;
  /* guarda os dados de um aluno */
  Aluno aluno;

  /* Checa se o arquivo alunos.dat tem conteudo */
  /* carrega dados para a lista de alunos */
  lista_alunos = recupera_alunos("alunos.dat", lista_alunos);

  while (opcao != 0) {
    opcao = menu();
    switch (opcao) {
    case 1:
      /* ler dados de um aluno */
      printf("--- Ler dados do aluno ---\n");
      aluno = ler_aluno();
      /* Cria um novo no tipo aluno e insere na lista */
      lista_alunos = insereNo(lista_alunos, aluno);
      printf("\nDados do aluno inserido com sucesso!\n");
      break;
    case 2:
      printf("\n--- Lista dados dos alunos ---\n");
      listaNos(lista_alunos);
      break;
    case 3:
      /* Salva dados do aluno em arquivo texto */
      salvaLista(lista_alunos, "alunos.dat");
      printf("\nDados salvos com sucesso!\n");
      break;
    case 0:
      /* encerra o programa */
      exit(0);
      break;
    default:
      printf("Opcao invalida!\n");
    }
  }
  return 0;
}