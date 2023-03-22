#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myalunos.h"
#include "myfiles.h"

int menu(){
    int opcao;
    printf("--- Menu Principal ---\n");
    printf("[1] - Insere aluno\n");
    printf("[2] - Listar alunos\n");
    printf("[3] - Remover aluno\n");
    printf("[4] - Salvar em arquivo\n");
    printf("[0] - SAIR\n");
    printf("Qual a sua opção? ");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
    int opcao;
    Node *lista_alunos = NULL; /* inicia uma lista de alunos vazia */
    Aluno aluno; /* guarda os dados de um aluno */ 
    int id_aluno;

    /* Checa se o arquivo alunos.dat tem conteudo */
    /* carrega dados para a lista de alunos */
    lista_alunos = recupera_alunos("alunos.dat", lista_alunos);
    
    while(opcao != 0){
        opcao = menu();
        switch (opcao)
        {
        case 1:
            /* ler dados de um aluno */
            printf("--- Ler dados do aluno ---\n");
            aluno = ler_aluno();
            if (buscaNo(lista_alunos, aluno.id) == NULL){
                /* Cria um novo no tipo aluno e insere na lista */
                lista_alunos = insereNo(lista_alunos, aluno);
                printf("\nDados do aluno inserido com sucesso!\n");
            }else{
                printf("Id %d já existe! Informe outro id!\n", aluno.id);
            }
            break;
        case 2:
            printf("\n--- Lista dados dos alunos ---\n");
            listaNos(lista_alunos);
            break;
        case 3: 
            printf("\n--- Remove aluno ---\n");
            printf("Qual o id do aluno? ");
            scanf("%d", &id_aluno);
            if (buscaNo(lista_alunos, id_aluno) == NULL){
                printf("Aluno com id: %d não existe!\n", id_aluno);
            }else{
                lista_alunos = removeNo(lista_alunos, id_aluno);
                printf("Aluno com id: %d removido com sucesso!\n", id_aluno);
            }
            break;
        case 4:
            /* Salva dados do aluno em arquivo texto */    
            salvaLista(lista_alunos, "alunos.dat");
            printf("\nDados salvos com sucesso!\n");
            break;
        case 0:
            /* encerra o programa */
            libera_lista(lista_alunos);
            exit(0);
            break;        
        default:
            printf("Opcao invalida!\n");
        }
    }
    return 0;
}