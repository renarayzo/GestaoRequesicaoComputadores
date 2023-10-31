#ifndef FUNCOESLEITURA_H_INCLUDED
#define FUNCOESLEITURA_H_INCLUDED

#include "constantes.h"

typedef struct
{
    int dia;
    int mes;
    int ano;
} estruturaData;

estruturaData lerData();
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo, char mensagemErro[MAX_STRING]);
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
void limpaBufferStdin(void);

#endif // FUNCOESLEITURA_H_INCLUDED
