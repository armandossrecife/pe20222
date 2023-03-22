#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_DATA_HORA 20

/* Cria um tipo para armazenar dados de um aluno */
typedef struct aluno{
    int id;
    char nome[MAX_NAME];
    int aprovado;
    char data_hora[MAX_DATA_HORA];
} Aluno;

/* Criar uma estrutura para manipular alunos */
typedef struct node{
    Aluno aluno;
    struct node *proximo;
} Node;

void salvaLista(Node* inicio, char* arquivo){
    FILE* fp = fopen(arquivo, "w");
    Node* no = inicio;

    if (fp == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    while (no != NULL){
        fprintf(fp, "%d,%s,%d,%s\n", no->aluno.id, no->aluno.nome, no->aluno.aprovado, no->aluno.data_hora);
        no = no->proximo;
    }
    fclose(fp);
}

Node* recupera_alunos(char *file_name) {
  Aluno aluno;
  Node* lista=NULL;
  FILE *file;

  file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Erro: não pode abrir o arquivo.\n");
    exit(1); // encerra o programa
  }
  
while (fscanf(file, "%d,%[^,],%d,%[^,\n]\n", &aluno.id, aluno.nome, &aluno.aprovado, aluno.data_hora) == 4) {
    printf("%d,%s,%d,%s\n", aluno.id, aluno.nome, aluno.aprovado, aluno.data_hora);
    lista = insereNo(lista, aluno);
  }
  fclose(file);
  return lista;
}