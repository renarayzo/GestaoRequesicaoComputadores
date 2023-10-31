#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoesPortateisExistentes.h"
#include "funcoesRequesicoesPortateis.h"
#include "funcoesAvariasReparacoes.h"

void registarInformacaoPortateis(portateisParaRequesicao portateisInfo[MAX_REGISTOS_PORTATEIS], int *quantidadePortateisDisponiveis, int *quantidadePortateisExistentesParaRequesicao){
    int quantidadePortateis = 0, i = 0, verificacaoIdentificacaoPortatil = 0, processadorPortatilInteiro = 0, estadoPortatilInteiro = 0, localizacaoPortatilInteiro = 0;
    char verificacaoCharIdentificacaoPortatil[MAX_NUM_IDENTIFICACAO_PORTATIL];
    portateisParaRequesicao portatil = {0};
    (*quantidadePortateisDisponiveis) = 0;

    printf("\n-------------------------------------------------------------------\n");
    quantidadePortateis = lerInteiro("Quantos Portateis Pretende Introduzir: ",ZERO, MAX_REGISTOS_PORTATEIS, "Quantidade de Portateis Invalida, Introduza Novamente!\n");

    if(quantidadePortateis == 0){
        printf("\n-------------------------------------------------------------------");
        printf("\nNao Foram Adicionados Portateis");
        printf("\n-------------------------------------------------------------------");
    }
    else{
        printf("-------------------------------------------------------------------\n");
        printf("\n\tIntroducao das Informacoes Referentes aos Portateis\n");
        printf("-------------------------------------------------------------------");
        for(i = 0; i < (*quantidadePortateisExistentesParaRequesicao); i++){
            portateisInfo[i] = portatil;
        }

        for(i = 0; i < quantidadePortateis; i++){
            do{
                lerString("\nIntroduza o Numero de Identificacao do Portatil: ", verificacaoCharIdentificacaoPortatil, MAX_NUM_IDENTIFICACAO_PORTATIL);
                verificacaoIdentificacaoPortatil = 0;
                verificacaoIdentificacaoPortatil = procurarPortatilExistente(quantidadePortateis, verificacaoCharIdentificacaoPortatil, portateisInfo);

                if(verificacaoIdentificacaoPortatil != -1){
                    printf("Erro!! Numero de Identificacao Ja foi Introduzido!\n");
                }
            }while(verificacaoIdentificacaoPortatil != -1);
            strcpy(portateisInfo[i].numIdentificacaoPortatil, verificacaoCharIdentificacaoPortatil);

            lerString("\nIntroduza a Designacao do Portatil: ", portateisInfo[i].designacaoPortatil, MAX_NUM_DESIGNACAO_PORTATIL);

            processadorPortatilInteiro = lerInteiro("\nIntroduza se o Processador do Portatil (1)i3 (2)i5 (3)i7 ", MIN_PROCESSADOR_PORTATIL, MAX_PROCESSADOR_PORTATIL, "Erro!! Introduza Uma das Opcoes!");
            switch(processadorPortatilInteiro){
                case 1:
                    strcpy(portateisInfo[i].processadorPortatil, "i3");
                    (*quantidadePortateisDisponiveis)++;
                    break;
                case 2:
                    strcpy(portateisInfo[i].processadorPortatil, "i5");
                    break;
                case 3:
                    strcpy(portateisInfo[i].processadorPortatil, "i7");
                    break;
                default:
                    break;
            }

            portateisInfo[i].memoriaRamPortatil = lerInteiro("\nIntroduza a Memoria RAM do Portatil ", MIN_RAM_PORTATIL, MAX_RAM_PORTATIL, "Erro!! RAM Introduzida Invalida, Introduza Novamente!");

            strcpy(portateisInfo[i].estadoRequesicaoPortatil, "Disponivel");

            localizacaoPortatilInteiro = lerInteiro("\nIntroduza a localizacao do Portatil (1)Residencias (2)Campus1 (3)Campus2 (4)Campus5 ", MIN_ESCOLHA_LOCALIZACAO, MAX_ESCOLHA_LOCALIZACAO, "Erro!! Introduza Uma das Opcoes!");
            switch(localizacaoPortatilInteiro){
                case 1:
                    strcpy(portateisInfo[i].localizacaoPortatil, "Residencias");
                    break;
                case 2:
                    strcpy(portateisInfo[i].localizacaoPortatil, "Campus1");
                    break;
                case 3:
                    strcpy(portateisInfo[i].localizacaoPortatil, "Campus2");
                    break;
                case 4:
                    strcpy(portateisInfo[i].localizacaoPortatil, "Campus5");
                    break;
                default:
                    break;
            }

            if(i == 0){
                portateisInfo[i].dataAquisicaoPortatil = lerData();
            }
            else{
                // A data nova introduzida tem de ser maior que a data do resgisto de portatil anterior
                do{
                    portateisInfo[i].dataAquisicaoPortatil = lerData();
                    if(portateisInfo[i - 1].dataAquisicaoPortatil.ano > portateisInfo[i].dataAquisicaoPortatil.ano){
                        printf("O Ano Introduzido tem de Ser Maior ou Igual ao Ano da Data de de Aquisicao Do Portatil Anterior -> %d\n", portateisInfo[i - 1].dataAquisicaoPortatil.ano);
                    }
                    else{
                        if(portateisInfo[i - 1].dataAquisicaoPortatil.mes > portateisInfo[i].dataAquisicaoPortatil.mes && portateisInfo[i - 1].dataAquisicaoPortatil.ano == portateisInfo[i].dataAquisicaoPortatil.ano){
                            printf("O Mes Introduzido tem de Ser Maior ou Igual ao Mes da Data de de Aquisicao Do Portatil Anterior -> %d\n", portateisInfo[i - 1].dataAquisicaoPortatil.mes);
                        }
                        else{
                            if(portateisInfo[i - 1].dataAquisicaoPortatil.mes == portateisInfo[i].dataAquisicaoPortatil.mes && portateisInfo[i - 1].dataAquisicaoPortatil.ano == portateisInfo[i].dataAquisicaoPortatil.ano)
                            {
                                if(portateisInfo[i - 1].dataAquisicaoPortatil.dia > portateisInfo[i].dataAquisicaoPortatil.dia){
                                    printf("O Dia Introduzido tem de Ser Maior ou Igual ao Dia da Data de Aquisicao Do Portatil Anterior -> %d\n", portateisInfo[i - 1].dataAquisicaoPortatil.dia);
                                }
                            }
                        }
                    }
                }while(portateisInfo[i - 1].dataAquisicaoPortatil.ano > portateisInfo[i].dataAquisicaoPortatil.ano || (portateisInfo[i - 1].dataAquisicaoPortatil.mes > portateisInfo[i].dataAquisicaoPortatil.mes && portateisInfo[i - 1].dataAquisicaoPortatil.ano == portateisInfo[i].dataAquisicaoPortatil.ano) || (portateisInfo[i - 1].dataAquisicaoPortatil.mes == portateisInfo[i].dataAquisicaoPortatil.mes && portateisInfo[i - 1].dataAquisicaoPortatil.ano == portateisInfo[i].dataAquisicaoPortatil.ano && portateisInfo[i - 1].dataAquisicaoPortatil.dia > portateisInfo[i].dataAquisicaoPortatil.dia));
            }

            portateisInfo[i].valorPortatil = lerFloat("\nIntroduza o Valor do Portatil ", MIN_VALOR_PORTATIL, MAX_VALOR_PORTATIL);
            printf("\n-------------------------------------------------------------------");
        }

        *quantidadePortateisExistentesParaRequesicao = quantidadePortateis;
        *quantidadePortateisDisponiveis = quantidadePortateis;
        printf("\nPortateis Adicionados Com Sucesso!");
        printf("\n-------------------------------------------------------------------");
        gravaFicheiroBinarioPortateis(portateisInfo, (*quantidadePortateisExistentesParaRequesicao), (*quantidadePortateisDisponiveis));
    }
}

void listarInformacaoPortateis(int quantidadePortateisExistentesParaRequesicao, portateisParaRequesicao portateisInfo[MAX_REGISTOS_PORTATEIS], int quantidadeTotalRequisicoes, requesicaoPortateis *requesicaoInfosPortateis, int quantidadeTotalAvarias, avariasPortateis *avariasInfosPortateis){
    int i = 0, j = 0, quantidadeRequesicoes = 0, quantidadeAvarias = 0, posicaoRequesicao = 0, quantidadePrazos = 0;

    printf("\n-------------------------------------------------------------------");
    printf("\n\t\tListagem Dos Portateis Existentes\n");
    printf("-------------------------------------------------------------------");

    for(i = 0; i < quantidadePortateisExistentesParaRequesicao; i++){
        quantidadeRequesicoes = quantidadeRequesicoesPorNumIdentificacaoPortatil(quantidadeTotalRequisicoes, portateisInfo[i].numIdentificacaoPortatil, requesicaoInfosPortateis);
        quantidadeAvarias = quantidadeAvariasPorNumIdentificacaoPortatil(quantidadeTotalAvarias, avariasInfosPortateis, quantidadePortateisExistentesParaRequesicao, portateisInfo);

        printf("\nNumero Identificacao do Portatil: %s", portateisInfo[i].numIdentificacaoPortatil);
        printf("\nDesignacao do Portatil: %s", portateisInfo[i].designacaoPortatil);
        printf("\nProcessador do Portatil: %s", portateisInfo[i].processadorPortatil);
        printf("\nMemoria RAM do Portatil: %i GB", portateisInfo[i].memoriaRamPortatil);
        printf("\nEstado Requesicao do Portatil: %s", portateisInfo[i].estadoRequesicaoPortatil);
        printf("\nLocalizacao do Portatil: %s", portateisInfo[i].localizacaoPortatil);
        printf("\nDia da Aquisicao do Portatil: %i", portateisInfo[i].dataAquisicaoPortatil.dia);
        printf("\nMes da Aquisicao do Portatil: %i", portateisInfo[i].dataAquisicaoPortatil.mes);
        printf("\nAno da Aquisicao do Portatil: %i", portateisInfo[i].dataAquisicaoPortatil.ano);
        printf("\nValor do Portatil: %.2f", portateisInfo[i].valorPortatil);

        printf("\nQuantidade de Requesicoes Totais: %i", quantidadeRequesicoes);
        printf("\nQuantidade de Avarias Totais: %i", quantidadeAvarias);
        if(quantidadeRequesicoes == 0){
            //O portatil não tem requesicoes
        }
        else{
            printf("\nTipo de Utente: %s", requesicaoInfosPortateis[posicaoRequesicao].tipoUtenteRequesicao);
            for(j = 0; j < quantidadeTotalRequisicoes; j++){
                if(strcmp(portateisInfo[i].numIdentificacaoPortatil, requesicaoInfosPortateis[j].numIdentificacaoPortatil) == 0){
                    printf("\nPrazo da Requesicao %i: %i Dias", quantidadePrazos + 1, requesicaoInfosPortateis[j].prazoRequesicao);
                    quantidadePrazos++;
                }
            }
        }
        printf("\n-------------------------------------------------------------------");
    }
}

void alteralLocalizacaoUmPortatil(int quantidadePortateisExistentesParaRequesicao, portateisParaRequesicao portateisInfo[MAX_REGISTOS_PORTATEIS]){
    int posicaoDoPortatil = 0, localizacaoPortatilInteiro = 0;
    char numIdentificacaoPortatilParaTrocar[MAX_NUM_IDENTIFICACAO_PORTATIL];

    printf("\n-------------------------------------------------------------------");
    lerString("\nIntroduza o Numero de Identificacao do Portatil que Pretende Alterar a Localizacao: ", numIdentificacaoPortatilParaTrocar, MAX_NUM_IDENTIFICACAO_PORTATIL);
    printf("-------------------------------------------------------------------\n");

    posicaoDoPortatil = procurarPortatilExistente(quantidadePortateisExistentesParaRequesicao, numIdentificacaoPortatilParaTrocar, portateisInfo);

    if(posicaoDoPortatil == -1){
        printf("-------------------------------------------------------------------");
        printf("\nNumero de Identificacao do Portatil Introduzido nao Existe no Sistema!\n");
        printf("-------------------------------------------------------------------");
    }
    else{
        localizacaoPortatilInteiro = lerInteiro("Introduza a localizacao do Portatil (1)Residencias (2)Campus1 (3)Campus2 (4)Campus5: ", MIN_ESCOLHA_LOCALIZACAO, MAX_ESCOLHA_LOCALIZACAO, "Erro!! Introduza Uma das Opcoes\n");
            switch(localizacaoPortatilInteiro){
                case 1:
                    strcpy(portateisInfo[posicaoDoPortatil].localizacaoPortatil, "Residencias");
                    break;
                case 2:
                    strcpy(portateisInfo[posicaoDoPortatil].localizacaoPortatil, "Campus1");
                    break;
                case 3:
                    strcpy(portateisInfo[posicaoDoPortatil].localizacaoPortatil, "Campus2");
                    break;
                case 4:
                    strcpy(portateisInfo[posicaoDoPortatil].localizacaoPortatil, "Campus5");
                    break;
                default:
                    break;
            }

        printf("Localizacao do Portatil com o Numero de Identificacao -> %s, Alterada com Sucesso!\n", numIdentificacaoPortatilParaTrocar);
    }
}

void gravaFicheiroBinarioPortateis(portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS], int quantidadePortateisExistentesParaRequesicao, int quantidadePortateisDisponiveis){
    FILE *ficheiroPortateis;

    ficheiroPortateis = fopen("InfosPortateis.dat", "wb");
    if(ficheiroPortateis == NULL)
    {
        printf("-------------------------------------------------------------------\n");
        printf("Erro ao abrir o ficheiro!\n");
        printf("-------------------------------------------------------------------\n");
    }
    else
    {
        fwrite(&quantidadePortateisExistentesParaRequesicao, sizeof(int), 1, ficheiroPortateis);
        fwrite(&quantidadePortateisDisponiveis, sizeof(int), 1, ficheiroPortateis);
        fwrite(portateisInfos, sizeof(portateisParaRequesicao), quantidadePortateisExistentesParaRequesicao, ficheiroPortateis);
        fclose(ficheiroPortateis);

        printf("\n-------------------------------------------------------------------");
        printf("\nInformacoes dos Portateis Guardadas Com Sucesso!\n");
        printf("-------------------------------------------------------------------");
    }
}

void leFicheiroBinarioPortateis(portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS], int *quantidadePortateisExistentesParaRequesicao, int *quantidadePortateisDisponiveis){
    FILE *ficheiroPortateis;

    ficheiroPortateis = fopen("InfosPortateis.dat", "rb");
    if(ficheiroPortateis == NULL)
    {

    }
    else
    {
        fread(&(*quantidadePortateisExistentesParaRequesicao), sizeof(int), 1, ficheiroPortateis);
        fread(&(*quantidadePortateisDisponiveis), sizeof(int), 1, ficheiroPortateis);
        fread(portateisInfos, sizeof(portateisParaRequesicao), *quantidadePortateisExistentesParaRequesicao, ficheiroPortateis);
        fclose(ficheiroPortateis);
    }
}

int procurarPortatilExistente(int quantidadePortateisExistentesParaRequesicao, char numIdentificacaoPortatil[MAX_NUM_IDENTIFICACAO_PORTATIL], portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS]){
    int i = 0, valido = -1;

    //Se valido = -1 (O portatil nao Existe)
    for(i = 0; i < quantidadePortateisExistentesParaRequesicao; i++){
        if(strcmp(portateisInfos[i].numIdentificacaoPortatil, numIdentificacaoPortatil) == 0){
            valido = i;
        }
    }

    return valido;
}
