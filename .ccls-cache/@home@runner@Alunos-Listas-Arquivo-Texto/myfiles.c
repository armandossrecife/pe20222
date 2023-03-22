#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myalunos.h"

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

Node* recupera_alunos(char *file_name, Node* lista) {
  Aluno aluno;
  FILE *file;
  int qtd_alunos=0;

  file = fopen(file_name, "r");
  if (file == NULL) {
    printf("O arquivo %s não existe!\n", file_name);
    printf("Será criado um novo arquivo para salvar os dados dos alunos.\n");
    return NULL;
  }
  
  while (fscanf(file, "%d,%[^,],%d,%[^,\n]\n", &aluno.id, aluno.nome, &aluno.aprovado, aluno.data_hora) == 4) {
    //printf("%d,%s,%d,%s\n", aluno.id, aluno.nome, aluno.aprovado, aluno.data_hora);
    lista = insereNo(lista, aluno);
    qtd_alunos = qtd_alunos + 1; 
  }
  
  fclose(file);

  if (qtd_alunos > 0){
    printf("%d aluno(s) recuperado(s) com sucesso!\n", qtd_alunos);
  }

  return lista;
}