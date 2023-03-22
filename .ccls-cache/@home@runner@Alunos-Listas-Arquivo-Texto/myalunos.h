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

/* Funções para manipular a lista encadeada */
Node* criaNo(Aluno aluno);
Node* insereNo(Node* inicio, Aluno aluno);
Node* buscaNo(Node* inicio, int id);
void alteraNo(Node* no, Aluno aluno);
void listaNos(Node* inicio);
Node* removeNo(Node* inicio, int id);
void libera_lista(Node* inicio);
Aluno ler_aluno();