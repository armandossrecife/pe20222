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
data_hora_sistema pega_data_hora_sistema() {
    data_hora_sistema data_hora_atual;

    time_t tempo = time(NULL);
    struct tm data_atual = *localtime(&tempo);

    data_hora_atual.ano = data_atual.tm_year + 1900;
    data_hora_atual.mes = data_atual.tm_mon + 1; 
    data_hora_atual.dia = data_atual.tm_mday; 
    data_hora_atual.hora = data_atual.tm_hour; 
    data_hora_atual.minuto = data_atual.tm_min; 
    data_hora_atual.segundos = data_atual.tm_sec;

    return data_hora_atual;
}

/* Converte o tipo data_hora para string */
char* converte_data_hora_to_string(data_hora_sistema data_hora_atual) {
  char* str = malloc(20 * sizeof(char)); // Allocate memory for the string

  // Format the date and time string
  sprintf(str, "%02d/%02d/%02d %02d:%02d:%02d", data_hora_atual.dia, data_hora_atual.mes, data_hora_atual.ano, data_hora_atual.hora, data_hora_atual.minuto, data_hora_atual.segundos);

    return str;
}