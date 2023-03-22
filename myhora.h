#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define uma estrutura para guardar dados de data e hora do sistema */
typedef struct minha_data_hora {
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundos;
} data_hora_sistema;

/* Pega a hora corrrente do sistema usando o time.h */
data_hora_sistema pega_data_hora_sistema();

/* Converte o tipo data_hora para string */
char* converte_data_hora_to_string(data_hora_sistema data_hora_atual);