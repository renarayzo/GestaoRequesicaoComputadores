#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

typedef struct
{
    char numIdentificacaoPortatil[MAX_NUM_IDENTIFICACAO_PORTATIL];
    char designacaoPortatil[MAX_NUM_DESIGNACAO_PORTATIL];
    char processadorPortatil[MAX_PROCESSADOR_PORTATIL];
    int memoriaRamPortatil;
    char estadoRequesicaoPortatil[MAX_ESTADO_REQUESICAO];
    char localizacaoPortatil[MAX_LOCALIZACAO_PORTATIL];
    estruturaData dataAquisicaoPortatil;
    float valorPortatil;
} portateisParaRequesicao;

typedef struct
{
    char codigoRequesicao[MAX_CODIGO_REQUESICAO];
    char numIdentificacaoPortatil[MAX_NUM_IDENTIFICACAO_PORTATIL];
    char nomeUtenteRequesicao[MAX_NOME_UTENTE];
    char tipoUtenteRequesicao[MAX_TIPO_UTENTE];
    estruturaData dataRequesicao;
    int prazoRequesicao;
    char estadoRequesicao[MAX_ESTADO_REQUESICAO];
    estruturaData dataDevolucaoRequesicao;
    char localDevolucaoRequesicao[MAX_LOCALIZACAO_PORTATIL];
    int valorMultaRequesicao;
} requesicaoPortateis;

typedef struct
{
    int codigoAvaria;
    char numIdentificacaoPortatil[MAX_NUM_IDENTIFICACAO_PORTATIL];
    char tipoAvaria[MAX_TIPO_AVARIA];
    char estadoAvaria[MAX_TIPO_AVARIA];
    estruturaData dataAvaria;
    int duracaoAvaria;
} avariasPortateis;

#endif // ESTRUTURAS_H_INCLUDED
