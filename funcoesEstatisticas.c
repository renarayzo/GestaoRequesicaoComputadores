#include "funcoesEstatisticas.h"

void percentagensCadaTipoProcessador(int quantidadeTotalPortateis, portateisParaRequesicao portateisInfo[MAX_REGISTOS_PORTATEIS]){
    int i = 0, quantidadeI3 = 0, quantidadeI5 = 0, quantidadeI7 = 0;
    float mediaI3 = 0, mediaI5 = 0, mediaI7 = 0;

    for(i = 0; i < quantidadeTotalPortateis; i++){
        if(strcmp(portateisInfo[i].processadorPortatil, "i3") == 0){
            quantidadeI3++;
        }
        else{
            if(strcmp(portateisInfo[i].processadorPortatil, "i5") == 0){
                quantidadeI5++;
            }
            else{
                if(strcmp(portateisInfo[i].processadorPortatil, "i7") == 0){
                    quantidadeI7++;
                }
            }
        }
    }

    mediaI3 = ((float) quantidadeI3 / quantidadeTotalPortateis) * 100;
    mediaI5 = ((float) quantidadeI5 / quantidadeTotalPortateis) * 100;
    mediaI7 = ((float) quantidadeI7 / quantidadeTotalPortateis) * 100;

    printf("\n\t\tPercentagens de Cada Tipo de Processador");
    printf("\n-------------------------------------------------------------------\n");
    printf("Percentagem de Processadores I3: %.2f%%", mediaI3);
    printf("\nPercentagem de Processadores I5: %.2f%%", mediaI5);
    printf("\nPercentagem de Processadores I7: %.2f%%", mediaI7);
    printf("\n-------------------------------------------------------------------");
}

float mediaMultasPagas(int quantidadeTotalRequesicoes, int quantidadeRequesicoesAtivas, requesicaoPortateis *requesicaoInfosPortateis){
    int i = 0, somaMultas = 0;
    float mediaMultas = 0;

    for(i = 0; i < quantidadeTotalRequesicoes; i++){
        if(strcmp(requesicaoInfosPortateis[i].estadoRequesicao, "Concluida") == 0){
            somaMultas = somaMultas + requesicaoInfosPortateis[i].valorMultaRequesicao;
        }
    }

    mediaMultas = (float) somaMultas / (quantidadeTotalRequesicoes - quantidadeRequesicoesAtivas);

    return mediaMultas;
}

void tiposUtentesMenorQuantRequesicoes(int quantidadeTotalRequesicoes, requesicaoPortateis *requesicaoInfosPortateis){
    int i = 0, quantDocente = 0, quantEstudante = 0, quantTecnico = 0;

    for(i = 0; i < quantidadeTotalRequesicoes; i++){
        if(strcmp(requesicaoInfosPortateis[i].tipoUtenteRequesicao, "Docente") == 0){
            quantDocente++;
        }
        else{
            if(strcmp(requesicaoInfosPortateis[i].tipoUtenteRequesicao, "Estudante") == 0){
                quantEstudante++;
            }
            else{
                if(strcmp(requesicaoInfosPortateis[i].tipoUtenteRequesicao, "Tecnico Administrativo") == 0){
                    quantTecnico++;
                }
            }
        }
    }


    printf("\n-------------------------------------------------------------------\n");
    if(quantDocente < quantEstudante && quantDocente < quantTecnico){
        printf("Tipo(s) de Utente com Menor Requesicoes: Docente");
    }
    else{
        if(quantEstudante < quantDocente && quantEstudante < quantTecnico){
            printf("Tipo(s) de Utente com Menor Requesicoes: Estudante");
        }
        else{
            if(quantTecnico < quantDocente && quantTecnico < quantEstudante){
                printf("Tipo(s) de Utente com Menor Requesicoes: Tecnico Administrativo");
            }
            else{
                if(quantDocente == quantEstudante){
                    printf("Tipo(s) de Utente com Menor Requesicoes: Docente e Estudante");
                }
                if(quantEstudante == quantTecnico){
                    printf("Tipo(s) de Utente com Menor Requesicoes: Estudante e Tecnico Administrativo");
                }
                if(quantDocente == quantTecnico){
                    printf("Tipo(s) de Utente com Menor Requesicoes: Docente e Tecnico Administrativo");
                }
            }
        }
    }
    printf("\n-------------------------------------------------------------------");
}

void devolucoesMaisRecentes(int quantidadeTotalRequesicoes, requesicaoPortateis *requesicaoInfosPortateis){
    int i = 0;
    estruturaData ultimaDevolucaoData;

    ultimaDevolucaoData.ano = requesicaoInfosPortateis[quantidadeTotalRequesicoes - 1].dataDevolucaoRequesicao.ano;
    ultimaDevolucaoData.mes = requesicaoInfosPortateis[quantidadeTotalRequesicoes - 1].dataDevolucaoRequesicao.mes;
    ultimaDevolucaoData.dia = requesicaoInfosPortateis[quantidadeTotalRequesicoes - 1].dataDevolucaoRequesicao.dia;

    printf("\n\t\tDevolucao(oes) Mais Recente(s)");
    printf("\n-------------------------------------------------------------------");

    for(i = 0; i < quantidadeTotalRequesicoes; i++){
        if(ultimaDevolucaoData.ano == requesicaoInfosPortateis[i].dataDevolucaoRequesicao.ano){
            if(ultimaDevolucaoData.mes == requesicaoInfosPortateis[i].dataDevolucaoRequesicao.mes){
                if(ultimaDevolucaoData.dia == requesicaoInfosPortateis[i].dataDevolucaoRequesicao.dia){
                    printf("\nCodigo Requisicao: %s", requesicaoInfosPortateis[i].codigoRequesicao);
                    printf("\nNumero de Identificacao do Portatil Requisitado: %s", requesicaoInfosPortateis[i].numIdentificacaoPortatil);
                    printf("\nNome do Utente que Requisitou o Portatil: %s", requesicaoInfosPortateis[i].nomeUtenteRequesicao);
                    printf("\nTipo de Utente: %s", requesicaoInfosPortateis[i].tipoUtenteRequesicao);
                    printf("\nDia da Requisicao do Portatil: %i", requesicaoInfosPortateis[i].dataRequesicao.dia);
                    printf("\nMes da Requisicao do Portatil: %i", requesicaoInfosPortateis[i].dataRequesicao.mes);
                    printf("\nAno da Requisicao do Portatil: %i", requesicaoInfosPortateis[i].dataRequesicao.ano);
                    printf("\nEstado da Requisicao: %s", requesicaoInfosPortateis[i].estadoRequesicao);
                    printf("\nDia da Devolucao do Portatil: %i", requesicaoInfosPortateis[i].dataDevolucaoRequesicao.dia);
                    printf("\nMes da Devolucao do Portatil: %i", requesicaoInfosPortateis[i].dataDevolucaoRequesicao.mes);
                    printf("\nAno da Devolucao do Portatil: %i", requesicaoInfosPortateis[i].dataDevolucaoRequesicao.ano);
                    printf("\nLocal de Devolucao do Portatil: %s", requesicaoInfosPortateis[i].localDevolucaoRequesicao);
                    printf("\nValor de Multa a Pagar: %i", requesicaoInfosPortateis[i].valorMultaRequesicao);
                    printf("\n-------------------------------------------------------------------");
                }
            }
        }
    }
}
