#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myhora.h"

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
Node* criaNo(Aluno aluno){
    Node* no = (Node*) malloc(sizeof(Node));
    no->aluno = aluno;
    no->proximo = NULL;
    return no;
}

Node* insereNo(Node* inicio, Aluno aluno){
    Node* no = criaNo(aluno);
    no->proximo = inicio;
    return no;
}

Node* buscaNo(Node* inicio, int id){
    Node* no = inicio;
    while (no != NULL && no->aluno.id != id){
        no = no->proximo;
    }
    return no;
}

void alteraNo(Node* no, Aluno aluno){
    no->aluno = aluno;
}

void listaNos(Node* inicio){
    Node* no = inicio;
    while (no != NULL){
        printf("ID: %d, Nome: %s, Aprovado: %d, Data/Hora: %s\n", no->aluno.id, no->aluno.nome, no->aluno.aprovado, no->aluno.data_hora);
        no = no->proximo;
    }
}

Node* removeNo(Node* inicio, int id){
    Node* ant=NULL;
    Node* p = inicio;

    /* procura aluno por id */
    while (p != NULL && p->aluno.id != id){
        ant = p;
        p = p->proximo;
    }

    /* verifica se achou o aluno */
    if (p == NULL){
        return inicio; /* nao achou, retorna a lista original */
    }

    /* retira elemento */
    if (ant == NULL){
        /* remove elemento do inicio da lista */
        inicio = p->proximo;
    }else{
        /* remove elemento do meio da lista */
        ant->proximo = p->proximo;
    }

    free(p);
    /* retorna a lista atualizada */
    return inicio;
}

void libera_lista(Node* inicio){
    Node* p = inicio;
    Node* t;

    while(p != NULL){
        t = p->proximo; /* guarda referencia para o proximo elemento */
        free(p); /* libera memoria apontada por p */
        p = t; /* faz p apontar para o proximo elemento da lista */
    }
}

/* Ler dados de um aluno */
Aluno ler_aluno(){
    Aluno aluno;

    printf("Digite o ID do aluno: ");
    scanf("%d", &aluno.id);
    getchar();

    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, MAX_NAME, stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

    printf("Aluno aprovado? 1-sim, 0-não: ");
    scanf("%d", &aluno.aprovado);
    getchar();
    
    data_hora_sistema data_hora_atual = pega_data_hora_sistema();
    char* data_hora_str = converte_data_hora_to_string(data_hora_atual);
    strcpy(aluno.data_hora, data_hora_str);
    printf("%s\n", data_hora_str);
    free(data_hora_str); // Free the allocated memory

    return aluno;
}