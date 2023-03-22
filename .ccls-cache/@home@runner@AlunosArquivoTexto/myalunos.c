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

    printf("Data/hora da operação: (dd/mm/aaaa hh:mm:ss): ");
    fgets(aluno.data_hora, MAX_DATA_HORA, stdin);
    aluno.data_hora[strcspn(aluno.data_hora, "\n")] = '\0';

    return aluno;
}