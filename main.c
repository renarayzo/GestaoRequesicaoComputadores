#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "constantes.h"
#include "funcoesMenus.c"
#include "funcoesPortateisExistentes.c"
#include "funcoesRequesicoesPortateis.c"
#include "funcoesAvariasReparacoes.c"
#include "funcoesEstatisticas.c"
#include "funcoesLeitura.c"

int main()
{
    int opcao = 0, opcaoSubMenu = 0, quantidadePortateisExistentesParaRequesicao = 0, quantidadePortateisDisponiveis = 0, quantidadeTotalRequisicoes = 0, quantidadeRequesicoesAtivas = 0, quantidadeTotalAvarias = 0;
    float mediaMultas = 0;
    portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS];
    requesicaoPortateis *requesicaoInfosPortateis = NULL;
    avariasPortateis *avariasInfosPortateis = NULL;


    //Leitura do Ficheiro InfosPortateis
    leFicheiroBinarioPortateis(portateisInfos, &quantidadePortateisExistentesParaRequesicao, &quantidadePortateisDisponiveis);
    requesicaoInfosPortateis = leFicheiroBinarioRequesicoes(&quantidadeTotalRequisicoes, &quantidadeRequesicoesAtivas, requesicaoInfosPortateis);
    avariasInfosPortateis = leFicheiroBinarioAvarias(&quantidadeTotalAvarias, avariasInfosPortateis);

    do{
        opcao = menuPrincipal(quantidadePortateisExistentesParaRequesicao, quantidadePortateisDisponiveis, quantidadeTotalRequisicoes, quantidadeRequesicoesAtivas);

        switch(opcao){
            case 1:
                do{
                    opcaoSubMenu = subMenuPortateis();
                    switch(opcaoSubMenu){
                        case 1:
                            registarInformacaoPortateis(portateisInfos, &quantidadePortateisDisponiveis, &quantidadePortateisExistentesParaRequesicao);
                            break;
                        case 2:
                            if(quantidadePortateisExistentesParaRequesicao == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Portateis Para Listar!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                listarInformacaoPortateis(quantidadePortateisExistentesParaRequesicao, portateisInfos, quantidadeTotalRequisicoes, requesicaoInfosPortateis, quantidadeTotalAvarias, avariasInfosPortateis);
                            }
                            break;
                        case  3:
                            if(quantidadePortateisExistentesParaRequesicao == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Portateis Para Alterar a Localizacao!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                alteralLocalizacaoUmPortatil(quantidadePortateisExistentesParaRequesicao, portateisInfos);
                            }
                            break;
                        case 4:
                            if(quantidadePortateisExistentesParaRequesicao == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Informacoes Sobre os Portateis!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                gravaFicheiroBinarioPortateis(portateisInfos, quantidadePortateisExistentesParaRequesicao, quantidadePortateisDisponiveis);
                            }
                            break;
                        default:
                            break;
                    }
                    printf("\n");
                }while(opcaoSubMenu != 0);

                break;
            case 2:
                do{
                    opcaoSubMenu = subMenuRequesicoes();
                    switch(opcaoSubMenu){
                        case 1:
                            if(quantidadePortateisExistentesParaRequesicao == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Portateis Para Efetuar Uma Requisicao!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                requesicaoInfosPortateis = registarInformacaoRequesicoes(&quantidadeTotalRequisicoes, &quantidadeRequesicoesAtivas, requesicaoInfosPortateis, quantidadePortateisExistentesParaRequesicao, &quantidadePortateisDisponiveis, portateisInfos);
                            }
                            break;
                        case 2:
                            if(quantidadeTotalRequisicoes == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Requisicoes Para Listar!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                listarRequesicoesPortateis(quantidadeTotalRequisicoes, requesicaoInfosPortateis);
                            }
                            break;
                        case 3:
                            if(quantidadeTotalRequisicoes == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Requisicoes Para Listar!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                listarUmaRequesicao(quantidadeTotalRequisicoes, requesicaoInfosPortateis, portateisInfos);
                            }
                            break;
                        case 4:
                            if(quantidadeRequesicoesAtivas == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Requisicoes Ativas Para Renovar!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                renovarRequesicao(quantidadeTotalRequisicoes, requesicaoInfosPortateis);
                            }
                            break;
                        case 5:
                            if(quantidadeTotalRequisicoes == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Requisicoes Para Concluir!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                concluirRequesicao(quantidadeTotalRequisicoes, &quantidadeRequesicoesAtivas, requesicaoInfosPortateis, quantidadePortateisExistentesParaRequesicao, &quantidadePortateisDisponiveis, portateisInfos);
                            }
                            break;
                        case 6:
                            if(quantidadeTotalRequisicoes == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Requisicoes Para Serem Guardadas!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                gravaFicheiroBinarioRequesicoes(quantidadeTotalRequisicoes, quantidadeRequesicoesAtivas, requesicaoInfosPortateis);
                            }
                            break;
                        default:
                            break;
                    }
                    printf("\n");
                }while(opcaoSubMenu != 0);

                break;
            case 3:
                do{
                    opcaoSubMenu = subMenuAvarias();
                    switch(opcaoSubMenu){
                        case 1:
                            if(quantidadePortateisExistentesParaRequesicao == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Portateis Para Registar Alguma Avaria!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                avariasInfosPortateis = registarAvariaPortatil(&quantidadeTotalAvarias, avariasInfosPortateis, quantidadePortateisExistentesParaRequesicao, &quantidadePortateisDisponiveis, portateisInfos);
                            }
                            break;
                        case 2:
                            if(quantidadeTotalAvarias == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Avarias Para Listar!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                listarAvariasPortateis(quantidadeTotalAvarias, avariasInfosPortateis, quantidadePortateisExistentesParaRequesicao, portateisInfos);
                            }
                            break;
                        case 3:
                            if(quantidadeTotalAvarias == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Avarias No Sistema!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                alterarTipoAvaria(quantidadeTotalAvarias, avariasInfosPortateis);
                            }
                            break;
                        case 4:
                            if(quantidadeTotalAvarias == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Avarias No Sistema!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                concluirAvariaPortatil(quantidadeTotalAvarias, avariasInfosPortateis, quantidadePortateisExistentesParaRequesicao, &quantidadePortateisDisponiveis, portateisInfos);
                            }
                        default:
                            break;
                    }
                    printf("\n");
                }while(opcaoSubMenu != 0);
                break;
            case 4:
                do{
                    opcaoSubMenu = subMenuEstatisticas();
                    switch(opcaoSubMenu){
                        case 1:
                            if(quantidadePortateisExistentesParaRequesicao == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Portateis No Sistema!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                percentagensCadaTipoProcessador(quantidadePortateisExistentesParaRequesicao, portateisInfos);
                            }
                            break;
                        case 2:
                            if(quantidadeTotalRequisicoes == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Requesicoes Para Calcular a Media das Multas!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                mediaMultas = mediaMultasPagas(quantidadeTotalRequisicoes, quantidadeRequesicoesAtivas, requesicaoInfosPortateis);
                                printf("\n-------------------------------------------------------------------");
                                printf("\nMedia das Multas Pagas: %.2f\n", mediaMultas);
                                printf("-------------------------------------------------------------------");
                            }
                            break;
                        case 3:
                            if(quantidadeTotalRequisicoes == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Requesicoes Para Calcular o Tipo de Utente com Mais Requesicoes!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                tiposUtentesMenorQuantRequesicoes(quantidadeTotalRequisicoes, requesicaoInfosPortateis);
                            }
                            break;
                        case 4:
                            if(quantidadeTotalRequisicoes == 0){
                                printf("\n-------------------------------------------------------------------");
                                printf("\nNao Existem Requesicoes Para Apresentar a(s) Devolucao(oes) Mais Recente(s)!\n");
                                printf("-------------------------------------------------------------------");
                            }
                            else{
                                devolucoesMaisRecentes(quantidadeTotalRequisicoes, requesicaoInfosPortateis);
                            }
                            break;
                        default:
                            break;
                    }
                    printf("\n");
                }while(opcaoSubMenu != 0);
                break;
            default:
                break;
        };

    }while(opcao != 0);

    free(requesicaoInfosPortateis);
    free(avariasInfosPortateis);
    return 0;
}
