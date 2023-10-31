#include "funcoesLeitura.h"

estruturaData lerData()
{

    estruturaData data;
    int diasMes;

    printf("\n");
    data.ano = lerInteiro("Introduza o Ano ", MIN_ANO_DATA, MAX_ANO_DATA, "Erro!! Ano Introduzido Invalido, Introduza Novamente!\n");
    printf("\n");
    data.mes = lerInteiro("Introduza o Mes ", MIN_MES_DATA, MAX_MES_DATA, "Erro!! Mes Introduzido Invalido, Introduza Novamente!\n");
    switch(data.mes)
    {
        case 2:
            if((data.ano) % 400 == 0 || (data.ano % 4 == 0 && data.ano % 100 != 0))  //Ano Bissexto
            {
                diasMes = 29;
            }
            else
            {
                diasMes = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            diasMes = 30;
            break;
        default:
            diasMes = 31;
            break;
    }
    printf("\n");
    data.dia = lerInteiro("Introduza o Dia ", MIN_MES_DATA, diasMes, "Erro!! Dia Introduzido Invalido, Introduza Novamente!\n");
    return data;
}

//Funções Auxiliares
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo, char mensagemErro[MAX_STRING])
{
    int numero, controlo;
    do
    {
        printf("%s(%d a %d): ", mensagem, minimo, maximo);
        controlo = scanf ("%d", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();     //limpa todos os caracteres do buffer stdin (nomeadamente o \n)

        if (controlo == 0)
        {
            printf("Erro!! Devera Introduzir um Numero Inteiro Dentro do Intervalo!\n\n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("%s\n",mensagemErro);
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo)
{
    float numero;
    int controlo;
    do
    {
        printf("%s (%.2f a %.2f): ", mensagem, minimo, maximo);
        controlo = scanf ("%f", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();

        if (controlo == 0)
        {
            printf("Erro!! Devera Introduzir um Numero Decimal(Float)!\n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Erro!! Numero invalido. Introduza um Valor Dentro do Intervalo!\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres)
{
    int tamanhoString;

    do 			// Repete leitura caso sejam obtidas strings vazias
    {
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);

        tamanhoString = strlen(vetorCaracteres);

        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n");  // apenas faz sentido limpar buffer se a ficarem caracteres
        }

    }
    while (tamanhoString == 1);

    if(vetorCaracteres[tamanhoString-1] != '\n')  // ficaram caracteres no buffer....
    {
        limpaBufferStdin();  // apenas faz sentido limpar buffer se a ficarem caracteres
    }
    else
    {
        vetorCaracteres[tamanhoString-1] = '\0'; 	//Elimina o \n da string armazenada em vetor
    }

}

void limpaBufferStdin(void)
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}
