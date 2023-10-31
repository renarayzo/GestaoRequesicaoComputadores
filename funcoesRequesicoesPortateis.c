#include "funcoesRequesicoesPortateis.h"

requesicaoPortateis *registarInformacaoRequesicoes(int *quantidadeTotalRequisicoes, int *quantidadeRequesicoesAtivas, requesicaoPortateis *requesicaoInfosPortateis, int quantidadePortateisExistentes, int *quantidadePortateisDisponiveis, portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS]){
    int i = 0, validacaoCodigo = 0, posicaoPortatil = 0, tipoUtenteRequesicaoInteiro = 0;
    char portatilPretendidoParaRequesitar[MAX_NUM_DESIGNACAO_PORTATIL];
    requesicaoPortateis *requesicaoInfosPortateisBackUp;

    requesicaoInfosPortateisBackUp = requesicaoInfosPortateis;

    printf("\n\t\t\tRegistar Requesicao\n");
    printf("-------------------------------------------------------------------");
    lerString("\nIntroduza o Numero de Identificacao do Portatil que Pretende Requisitar: ", portatilPretendidoParaRequesitar, MAX_NUM_IDENTIFICACAO_PORTATIL);
    posicaoPortatil = procurarPortatilExistente(quantidadePortateisExistentes, portatilPretendidoParaRequesitar, portateisInfos);
    printf("-------------------------------------------------------------------\n");

    if(posicaoPortatil == -1){
        printf("\n-------------------------------------------------------------------\n");
        printf("Nao Existe Nenhum Portatil Com o Numero de Identificacao Introduzido!");
        printf("\n-------------------------------------------------------------------");
    }
    else{
        if(strcmp("Disponivel", portateisInfos[posicaoPortatil].estadoRequesicaoPortatil) == 0){
            requesicaoInfosPortateis = realloc(requesicaoInfosPortateis, (*quantidadeTotalRequisicoes+1)*sizeof(requesicaoPortateis));

            if(requesicaoInfosPortateis == NULL)
            {
                printf("Erro ao Reservar Espaço na Memória!\n");
                requesicaoInfosPortateis = requesicaoInfosPortateisBackUp;
            }
            else{
                do{
                    validacaoCodigo = 0;
                    lerString("Introduza o Codigo da Requisicao: ", requesicaoInfosPortateis[*quantidadeTotalRequisicoes].codigoRequesicao, MAX_CODIGO_REQUESICAO);
                    strcpy(requesicaoInfosPortateis[*quantidadeTotalRequisicoes].numIdentificacaoPortatil, portatilPretendidoParaRequesitar);
                    for(i = 0; i < *quantidadeTotalRequisicoes; i++){
                        if(strcmp(requesicaoInfosPortateis[*quantidadeTotalRequisicoes].codigoRequesicao, requesicaoInfosPortateis[i].codigoRequesicao) == 0){
                            validacaoCodigo = 1;
                            printf("Erro!! Codigo Introduzido Ja Existe!\n\n");
                        }
                    }
                }while(validacaoCodigo == 1);

                lerString("\nIntroduza o Nome do Utente que Pretende Requisitar o Portatil: ", requesicaoInfosPortateis[*quantidadeTotalRequisicoes].nomeUtenteRequesicao, MAX_NOME_UTENTE);

                tipoUtenteRequesicaoInteiro = lerInteiro("\nIntroduza o Tipo de Utente (1)Estudante (2)Docente (3)Tecnico Administrativo ", MIN_ESCOLHA_TIPO_UTENTE, MAX_ESCOLHA_TIPO_UTENTE, "Erro!! Introduza Uma das Opcoes!");
                switch(tipoUtenteRequesicaoInteiro){
                    case 1:
                        strcpy(requesicaoInfosPortateis[*quantidadeTotalRequisicoes].tipoUtenteRequesicao, "Estudante");
                        break;
                    case 2:
                        strcpy(requesicaoInfosPortateis[*quantidadeTotalRequisicoes].tipoUtenteRequesicao, "Docente");
                        break;
                    case 3:
                        strcpy(requesicaoInfosPortateis[*quantidadeTotalRequisicoes].tipoUtenteRequesicao, "Tecnico Administrativo");
                        break;
                    default:
                        break;
                }

                if(*quantidadeTotalRequisicoes == 0){
                    do{
                        requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao = lerData();
                        if(portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.ano > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano){
                            printf("O Ano Introduzido tem de Ser Maior ou Igual ao Ano da Data de Aquisicao Do Portatil -> %d\n", portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.ano);
                        }
                        else{
                            if(portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.mes > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.mes && portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.ano == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano){
                                printf("O Mes Introduzido tem de Ser Maior ou Igual ao Mes da Data de Aquisicao Do Portatil -> %d\n", portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.mes);
                            }
                            else{
                                if(portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.mes == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.mes && portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.ano == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano)
                                {
                                    if(portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.dia > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.dia){
                                        printf("O Dia Introduzido tem de Ser Maior ou Igual ao Dia da Data de Aquisicao Do Portatil -> %d\n", portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.dia);
                                    }
                                }
                            }
                        }
                    }while(portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.ano > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano || (portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.mes > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.mes && portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.ano == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano) || (portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.ano == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano && portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.mes == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.mes && portateisInfos[quantidadePortateisExistentes - 1].dataAquisicaoPortatil.dia > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.dia));
                }
                else{
                    if(strcmp(requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].estadoRequesicao, "Ativa") == 0){
                        do{
                            requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao = lerData();
                            if(requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.ano > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano){
                                printf("O Ano Introduzido tem de Ser Maior ou Igual ao Ano da Data da Requesicao Anterior -> %d\n", requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.ano);
                            }
                            else{
                                if(requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.mes > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.mes && requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.ano == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano){
                                    printf("O Mes Introduzido tem de Ser Maior ou Igual ao Mes da Data da Requesicao Anterior -> %d\n", requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.mes);
                                }
                                else{
                                    if(requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.mes == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.mes && requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.ano == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano)
                                    {
                                        if(requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.dia > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.dia){
                                            printf("O Dia Introduzido tem de Ser Maior ou Igual ao Dia da Data da Requesicao Anterior -> %d\n", requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.dia);
                                        }
                                    }
                                }
                            }
                        }while(requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.ano > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano || (requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.mes > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.mes && requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.ano == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano) || (requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.ano == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano && requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.mes == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.mes && requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataRequesicao.dia > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.dia));
                    }
                    else{
                        do{
                            requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao = lerData();
                            if(requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.ano > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano){
                                printf("O Ano Introduzido tem de Ser Maior ou Igual ao Ano da Data da Requesicao Anterior -> %d\n", requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.ano);
                            }
                            else{
                                if(requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.mes > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.mes && requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.ano == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano){
                                    printf("O Mes Introduzido tem de Ser Maior ou Igual ao Mes da Data da Requesicao Anterior -> %d\n", requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.mes);
                                }
                                else{
                                    if(requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.mes == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.mes && requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.ano == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano)
                                    {
                                        if(requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.dia > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.dia){
                                            printf("O Dia Introduzido tem de Ser Maior ou Igual ao Dia da Data da Requesicao Anterior -> %d\n", requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.dia);
                                        }
                                    }
                                }
                            }
                        }while(requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.ano > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano || (requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.mes > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.mes && requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.ano == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano) || (requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.mes == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.mes && requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.ano == requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.ano && requesicaoInfosPortateis[*quantidadeTotalRequisicoes - 1].dataDevolucaoRequesicao.dia > requesicaoInfosPortateis[*quantidadeTotalRequisicoes].dataRequesicao.dia));
                    }
                }

                requesicaoInfosPortateis[*quantidadeTotalRequisicoes].prazoRequesicao = lerInteiro("\nIntroduza o Prazo de Requisicao do Portatil ", MIN_PRAZO_REQUESICAO, MAX_PRAZO_REQUESICAO, "Introduza o Prazo da Requisicao Entre 7 a 30 Dias!");

                strcpy(requesicaoInfosPortateis[*quantidadeTotalRequisicoes].estadoRequesicao, "Ativa");
                strcpy(portateisInfos[posicaoPortatil].estadoRequesicaoPortatil, "Requisitado");
                (*quantidadeTotalRequisicoes)++;
                (*quantidadeRequesicoesAtivas)++;
                (*quantidadePortateisDisponiveis)--;
                gravaFicheiroBinarioRequesicoes((*quantidadeTotalRequisicoes), (*quantidadeTotalRequisicoes), requesicaoInfosPortateis);
                gravaFicheiroBinarioPortateis(portateisInfos, quantidadePortateisExistentes, (*quantidadePortateisDisponiveis));
            }
        }
        else{
            printf("Erro!! O Portatil nao esta Disponivel para Requisicao Devido a estar -> %s", portateisInfos[posicaoPortatil].estadoRequesicaoPortatil);
            printf("\n-------------------------------------------------------------------");
        }
    }

    return requesicaoInfosPortateis;
}

void listarRequesicoesPortateis(int quantidadeTotalRequisicoes, requesicaoPortateis *requesicaoInfosPortateis){
    int i = 0;

    printf("\n\t\tListagem Das Requisicoes Efetuadas\n");
    printf("-------------------------------------------------------------------");

    for(i = 0; i < quantidadeTotalRequisicoes; i++){
        printf("\nCodigo Requisicao: %s", requesicaoInfosPortateis[i].codigoRequesicao);
        printf("\nNumero de Identificacao do Portatil Requisitado: %s", requesicaoInfosPortateis[i].numIdentificacaoPortatil);
        printf("\nNome do Utente que Requisitou o Portatil: %s", requesicaoInfosPortateis[i].nomeUtenteRequesicao);
        printf("\nTipo de Utente: %s", requesicaoInfosPortateis[i].tipoUtenteRequesicao);
        printf("\nDia da Requisicao do Portatil: %i", requesicaoInfosPortateis[i].dataRequesicao.dia);
        printf("\nMes da Requisicao do Portatil: %i", requesicaoInfosPortateis[i].dataRequesicao.mes);
        printf("\nAno da Requisicao do Portatil: %i", requesicaoInfosPortateis[i].dataRequesicao.ano);
        printf("\nPrazo da Requesicao: %i Dias", requesicaoInfosPortateis[i].prazoRequesicao);
        printf("\nEstado da Requisicao: %s", requesicaoInfosPortateis[i].estadoRequesicao);
        if(strcmp("Concluida", requesicaoInfosPortateis[i].estadoRequesicao) == 0){
            printf("\nDia da Devolucao do Portatil: %i", requesicaoInfosPortateis[i].dataDevolucaoRequesicao.dia);
            printf("\nMes da Devolucao do Portatil: %i", requesicaoInfosPortateis[i].dataDevolucaoRequesicao.mes);
            printf("\nAno da Devolucao do Portatil: %i", requesicaoInfosPortateis[i].dataDevolucaoRequesicao.ano);
            printf("\nLocal de Devolucao do Portatil: %s", requesicaoInfosPortateis[i].localDevolucaoRequesicao);
            printf("\nValor de Multa a Pagar: %i", requesicaoInfosPortateis[i].valorMultaRequesicao);
        }
        printf("\n-------------------------------------------------------------------");
    }
}

void listarUmaRequesicao(int quantidadeTotalRequisicoes, requesicaoPortateis *requesicaoInfosPortateis, portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS]){
    int posicaoRequesicao = 0;
    char codigoRequesicaoValidacao[MAX_CODIGO_REQUESICAO];

    printf("\n-------------------------------------------------------------------\n");
    lerString("Introduza o Codigo de Requesicao que Pretende Concluir: ", codigoRequesicaoValidacao, MAX_CODIGO_REQUESICAO);
    posicaoRequesicao = procurarRequesicaoExistente(quantidadeTotalRequisicoes, codigoRequesicaoValidacao, requesicaoInfosPortateis);
    printf("-------------------------------------------------------------------");

    if(posicaoRequesicao == -1){
        printf("\nCodigo de Requesicao Introduzido nao Existe no Sistema!\n");
        printf("-------------------------------------------------------------------");
    }
    else{
        printf("\n\t\tListagem Da Requesicao com o Codigo -> %s\n", codigoRequesicaoValidacao);
        printf("-------------------------------------------------------------------");
        printf("\nCodigo Requisicao: %s", requesicaoInfosPortateis[posicaoRequesicao].codigoRequesicao);
        printf("\nNumero de Identificacao do Portatil Requisitado: %s", requesicaoInfosPortateis[posicaoRequesicao].numIdentificacaoPortatil);
        printf("\nNome do Utente que Requisitou o Portatil: %s", requesicaoInfosPortateis[posicaoRequesicao].nomeUtenteRequesicao);
        printf("\nTipo de Utente: %s", requesicaoInfosPortateis[posicaoRequesicao].tipoUtenteRequesicao);
        printf("\nDia da Requisicao do Portatil: %i", requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.dia);
        printf("\nMes da Requisicao do Portatil: %i", requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.mes);
        printf("\nAno da Requisicao do Portatil: %i", requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.ano);
        printf("\nEstado da Requisicao: %s", requesicaoInfosPortateis[posicaoRequesicao].estadoRequesicao);
        if(strcmp("Concluida", requesicaoInfosPortateis[posicaoRequesicao].estadoRequesicao) == 0){
            printf("\nDia da Devolucao do Portatil: %i", requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.dia);
            printf("\nMes da Devolucao do Portatil: %i", requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.mes);
            printf("\nAno da Devolucao do Portatil: %i", requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.ano);
            printf("\nLocal de Devolucao do Portatil: %s", requesicaoInfosPortateis[posicaoRequesicao].localDevolucaoRequesicao);
            printf("\nValor de Multa a Pagar: %i", requesicaoInfosPortateis[posicaoRequesicao].valorMultaRequesicao);
        }
        else{
            printf("\nSem Informacoes da Devolucao, Local de Devolucao e Valor da Multa pois a Requesicao Ainda Está Ativa!");
        }
        printf("\nDesignacao do Portatil: %s", portateisInfos[posicaoRequesicao].designacaoPortatil);
        printf("\nQuantidade Total de Dias Requesitado: %i Dias", requesicaoInfosPortateis[posicaoRequesicao].prazoRequesicao);
        printf("\n-------------------------------------------------------------------");
    }
}

void renovarRequesicao(int quantidadeTotalRequisicoes, requesicaoPortateis *requesicoesInfosPortateis){
    int posicaoRequesicao = 0;
    char codigoRequesicaoValidacao[MAX_CODIGO_REQUESICAO];

    printf("\n-------------------------------------------------------------------\n");
    lerString("Introduza o Codigo de Requisicao que Pretende Renovar: ", codigoRequesicaoValidacao, MAX_CODIGO_REQUESICAO);
    posicaoRequesicao = procurarRequesicaoExistente(quantidadeTotalRequisicoes, codigoRequesicaoValidacao, requesicoesInfosPortateis);
    printf("-------------------------------------------------------------------\n");

    if(posicaoRequesicao == -1){
        printf("-------------------------------------------------------------------");
        printf("\n\tCodigo de Requisicao Introduzido nao Existe no Sistema!\n");
        printf("-------------------------------------------------------------------");
    }
    else{
        if(requesicoesInfosPortateis[posicaoRequesicao].prazoRequesicao < 30){
            printf("\n-------------------------------------------------------------------\n");
            printf("Podera Renovar No Maximo Mais %i Dias", 30 - requesicoesInfosPortateis[posicaoRequesicao].prazoRequesicao);
            requesicoesInfosPortateis[posicaoRequesicao].prazoRequesicao = requesicoesInfosPortateis[posicaoRequesicao].prazoRequesicao + lerInteiro("\nIntroduza o Numero de Dias que Pretende Adicionar ao Prazo ", MIN_PRAZO_REQUESICAO, 30 - requesicoesInfosPortateis[posicaoRequesicao].prazoRequesicao, "Erro!! Introduza um Valor Dentro do Intervalo!");
        }
        else{
            printf("-------------------------------------------------------------------\n");
            printf("Erro!! Prazo de Requisicao No Maximo, Tera de Efetuar Uma Nova Requisicao!\n");
        }
    }
    printf("-------------------------------------------------------------------");
}

void concluirRequesicao(int quantidadeTotalRequisicoes, int *quantidadeRequesicoesAtivas, requesicaoPortateis *requesicaoInfosPortateis, int quantidadePortateisExistentes, int *quantidadePortateisDisponiveis, portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS]){
    int posicaoRequesicao = 0, posicaoPortatil = 0, localizacaoPortatilInteiro = 0, i = 0;
    int diasDeMultaPagar = 0;
    char codigoRequesicaoValidacao[MAX_CODIGO_REQUESICAO];
    requesicaoPortateis *requesicaoInfosPortateisBackUp;
    FILE *ficheiroRequesicoesConcluidas = NULL;

    requesicaoInfosPortateisBackUp = requesicaoInfosPortateis;

    printf("\n-------------------------------------------------------------------\n");
    lerString("Introduza o Codigo de Requesicao que Pretende Concluir: ", codigoRequesicaoValidacao, MAX_CODIGO_REQUESICAO);
    posicaoRequesicao = procurarRequesicaoExistente(quantidadeTotalRequisicoes, codigoRequesicaoValidacao, requesicaoInfosPortateis);
    posicaoPortatil = procurarPortatilExistente(quantidadePortateisExistentes, requesicaoInfosPortateis[posicaoRequesicao].numIdentificacaoPortatil, portateisInfos);
    printf("-------------------------------------------------------------------\n");

    if(posicaoRequesicao == -1){
        printf("\n-------------------------------------------------------------------");
        printf("\nCodigo de Requesicao Introduzido nao Existe no Sistema!\n");
    }
    else{
        if(strcmp(requesicaoInfosPortateis[posicaoRequesicao].estadoRequesicao, "Concluida") == 0){
            printf("A Requisicao Introduzida Ja Foi Concluida!\n");
            printf("-------------------------------------------------------------------");
        }
        else{
            do{
                requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao = lerData();
                if(requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.ano > requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.ano){
                    printf("O Ano Introduzido tem de Ser Maior ou Igual ao Ano da Data de Requesicao -> %d\n", requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.ano);
                }
                else{
                    if(requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.mes > requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.mes && requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.ano == requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.ano){
                        printf("O Mes Introduzido tem de Ser Maior ou Igual ao Mes da Data de Requesicao -> %d\n", requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.mes);
                    }
                    else{
                        if(requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.mes == requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.mes && requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.ano == requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.ano)
                        {
                            if(requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.dia > requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.dia){
                                printf("O Dia Introduzido tem de Ser Maior ou Igual ao Dia da Data de Requesicao -> %d\n", requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.dia);
                            }
                        }
                    }
                }
            }while(requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.ano > requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.ano || (requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.mes > requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.mes && requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.ano == requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.ano) || (requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.ano == requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.ano && requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.mes == requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.mes && requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.dia > requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.dia));

            localizacaoPortatilInteiro = lerInteiro("\nIntroduza a Localizacao da Devolucao (1)Residencias (2)Campus1 (3)Campus2 (4)Campus5 ", MIN_ESCOLHA_LOCALIZACAO, MAX_ESCOLHA_LOCALIZACAO, "Erro!! Introduza Uma das Opcoes!");
            switch(localizacaoPortatilInteiro){
                case 1:
                    strcpy(requesicaoInfosPortateis[posicaoRequesicao].localDevolucaoRequesicao, "Residencias");
                    break;
                case 2:
                    strcpy(requesicaoInfosPortateis[posicaoRequesicao].localDevolucaoRequesicao, "Campus1");
                    break;
                case 3:
                    strcpy(requesicaoInfosPortateis[posicaoRequesicao].localDevolucaoRequesicao, "Campus2");
                    break;
                case 4:
                    strcpy(requesicaoInfosPortateis[posicaoRequesicao].localDevolucaoRequesicao, "Campus5");
                    break;
                default:
                    break;
            }

            diasDeMultaPagar = converteDataDias(requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao) - converteDataDias(requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao) - requesicaoInfosPortateis[posicaoRequesicao].prazoRequesicao;
            if(diasDeMultaPagar > 0){
                requesicaoInfosPortateis[posicaoRequesicao].valorMultaRequesicao = diasDeMultaPagar * 10;
            }
            else{
                requesicaoInfosPortateis[posicaoRequesicao].valorMultaRequesicao = 0;
            }

            ficheiroRequesicoesConcluidas = fopen("ficheiroRequesicoesConcluidas.txt", "a");
            if(ficheiroRequesicoesConcluidas == NULL)
            {
                printf("-------------------------------------------------------------------\n");
                printf("Erro ao abrir o ficheiro!\n");
                printf("-------------------------------------------------------------------\n");
            }
            else
            {
                fprintf(ficheiroRequesicoesConcluidas, "Codigo de Requesicao: %s", requesicaoInfosPortateis[posicaoRequesicao].codigoRequesicao);
                fprintf(ficheiroRequesicoesConcluidas, "\nNumero de Identificacao do Portatil Requisitado: %s", requesicaoInfosPortateis[posicaoRequesicao].numIdentificacaoPortatil);
                fprintf(ficheiroRequesicoesConcluidas, "\nNome do Utente que Requisitou o Portatil: %s", requesicaoInfosPortateis[posicaoRequesicao].nomeUtenteRequesicao);
                fprintf(ficheiroRequesicoesConcluidas, "\nTipo de Utente: %s", requesicaoInfosPortateis[posicaoRequesicao].tipoUtenteRequesicao);
                fprintf(ficheiroRequesicoesConcluidas, "\nDia da Requisicao do Portatil: %i", requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.dia);
                fprintf(ficheiroRequesicoesConcluidas, "\nMes da Requisicao do Portatil: %i", requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.mes);
                fprintf(ficheiroRequesicoesConcluidas, "\nAno da Requisicao do Portatil: %i", requesicaoInfosPortateis[posicaoRequesicao].dataRequesicao.ano);
                fprintf(ficheiroRequesicoesConcluidas, "\nPrazo da Requesicao: %i Dias", requesicaoInfosPortateis[posicaoRequesicao].prazoRequesicao);
                fprintf(ficheiroRequesicoesConcluidas, "\nEstado da Requisicao: %s", requesicaoInfosPortateis[posicaoRequesicao].estadoRequesicao);
                fprintf(ficheiroRequesicoesConcluidas, "\nDia da Devolucao do Portatil: %i", requesicaoInfosPortateis[posicaoRequesicao].prazoRequesicao);
                fprintf(ficheiroRequesicoesConcluidas, "\nMes da Devolucao do Portatil: %i", requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.dia);
                fprintf(ficheiroRequesicoesConcluidas, "\nPrazo da Requesicao: %i Dias", requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.mes);
                fprintf(ficheiroRequesicoesConcluidas, "\nAno da Devolucao do Portatil: %i", requesicaoInfosPortateis[posicaoRequesicao].dataDevolucaoRequesicao.ano);
                fprintf(ficheiroRequesicoesConcluidas, "\nLocal de Devolucao do Portatil: %s", requesicaoInfosPortateis[posicaoRequesicao].localDevolucaoRequesicao);
                fprintf(ficheiroRequesicoesConcluidas, "\nValor de Multa a Pagar: %i", requesicaoInfosPortateis[posicaoRequesicao].valorMultaRequesicao);
                fprintf(ficheiroRequesicoesConcluidas, "\nProcessador do Portatil: %s", portateisInfos[posicaoPortatil].processadorPortatil);
                fprintf(ficheiroRequesicoesConcluidas, "\nMemoria RAM do Portatil: %i GB", portateisInfos[posicaoPortatil].memoriaRamPortatil);
                fprintf(ficheiroRequesicoesConcluidas, "\n-------------------------------------------------------------------\n");
                fclose(ficheiroRequesicoesConcluidas);

                printf("\n-------------------------------------------------------------------");
                printf("\nRequesicao Concluida com Sucesso!\n");
                printf("-------------------------------------------------------------------");
            }
            strcpy(portateisInfos[posicaoPortatil].estadoRequesicaoPortatil, "Disponivel");
            strcpy(requesicaoInfosPortateis[posicaoRequesicao].estadoRequesicao, "Concluida");
            (*quantidadeRequesicoesAtivas)--;
            (*quantidadePortateisDisponiveis)++;
            gravaFicheiroBinarioRequesicoes(quantidadeTotalRequisicoes, (*quantidadeRequesicoesAtivas), requesicaoInfosPortateis);
            gravaFicheiroBinarioPortateis(portateisInfos, quantidadePortateisExistentes, (*quantidadePortateisDisponiveis));
        }
    }
}

void gravaFicheiroBinarioRequesicoes(int quantidadeTotalRequesicoes, int quantidadeRequesicoesAtivas, requesicaoPortateis *requesicaoInfosPortateis){
    FILE *ficheiroRequesicoes;

    ficheiroRequesicoes = fopen("InfosRequesicoes.dat", "wb");
    if(ficheiroRequesicoes == NULL)
    {
        printf("-------------------------------------------------------------------\n");
        printf("Erro ao abrir o ficheiro!\n");
        printf("-------------------------------------------------------------------\n");
    }
    else
    {
        fwrite(&quantidadeTotalRequesicoes, sizeof(int), 1, ficheiroRequesicoes);
        fwrite(&quantidadeRequesicoesAtivas, sizeof(int), 1, ficheiroRequesicoes);
        fwrite(requesicaoInfosPortateis, sizeof(requesicaoPortateis), quantidadeTotalRequesicoes, ficheiroRequesicoes);
        fclose(ficheiroRequesicoes);

        printf("\n-------------------------------------------------------------------");
        printf("\nInformacoes das Requisicoes Guardadas Com Sucesso!\n");
        printf("-------------------------------------------------------------------");
    }
}


requesicaoPortateis *leFicheiroBinarioRequesicoes(int *quantidadeTotalRequesicoes, int *quantidadeRequesicoesAtivas, requesicaoPortateis *requesicaoInfosPortateis){
    FILE *ficheiroRequesicoes;
    requesicaoPortateis *requesicaoInfosPortateisBackUp;

    requesicaoInfosPortateisBackUp = requesicaoInfosPortateis;

    ficheiroRequesicoes = fopen("InfosRequesicoes.dat", "rb");
    if(ficheiroRequesicoes == NULL)
    {

    }
    else
    {
        fread(&(*quantidadeTotalRequesicoes), sizeof(int), 1, ficheiroRequesicoes);
        fread(&(*quantidadeRequesicoesAtivas), sizeof(int), 1, ficheiroRequesicoes);
        requesicaoInfosPortateis = realloc(requesicaoInfosPortateis, (*quantidadeTotalRequesicoes)*sizeof(requesicaoPortateis));
        if(requesicaoInfosPortateis == NULL && *quantidadeTotalRequesicoes != 0){
            printf("\n-------------------------------------------------------------------\n");
            printf("Erro ao Reservar Espaço na Memória!\n");
            printf("\n-------------------------------------------------------------------");
            requesicaoInfosPortateis = requesicaoInfosPortateisBackUp;
        }
        else{
            fread(requesicaoInfosPortateis, sizeof(requesicaoPortateis), *quantidadeTotalRequesicoes, ficheiroRequesicoes);
        }
        fclose(ficheiroRequesicoes);
    }

    return requesicaoInfosPortateis;
}

int converteDataDias(estruturaData data){
    int totalDias = 0, anosDias = 0, mesesDias = 0, i = 0;

    anosDias = (data.ano - MIN_ANO_DATA) * 365; /* Converte em dias os anos anteriores */
    for (i = MIN_ANO_DATA; i < data.ano; i++){
        if((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0)){
            anosDias++; /* Ano bissexto */
        }
    }

    mesesDias = 0; /* Converte em dias os meses decorridos(do ano da data) */
    for (i = 1; i < data.mes; i++){
        switch (i) {
            case 2:
                mesesDias += 28;
                if((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0)){
                    mesesDias++; /* Ano bissexto */
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                mesesDias += 30;
                break;
            default: mesesDias += 31;
        }
    }

    totalDias = anosDias + mesesDias + data.dia;
    return totalDias;
}

int procurarRequesicaoExistente(int quantidadeTotalRequisicoes, char codigoRequesicaoPretendido[MAX_CODIGO_REQUESICAO], requesicaoPortateis *requesicaoInfosPortateis){
    int i = 0, valido = -1;

    //Se valido = -1 (A requesicao nao Existe)
    for(i = 0; i < quantidadeTotalRequisicoes; i++){
        if(strcmp(requesicaoInfosPortateis[i].codigoRequesicao, codigoRequesicaoPretendido) == 0){
            valido = i;
        }
    }

    return valido;
}

int quantidadeRequesicoesPorNumIdentificacaoPortatil(int quantidadeTotalRequisicoes, char numIdentificacaoPretendido[MAX_CODIGO_REQUESICAO], requesicaoPortateis *requesicaoInfosPortateis){
    int i = 0, quantidadeRequesicoesPorPortatil = 0;

    for(i = 0; i < quantidadeTotalRequisicoes; i++){
        if(strcmp(requesicaoInfosPortateis[i].numIdentificacaoPortatil, numIdentificacaoPretendido) == 0){
            quantidadeRequesicoesPorPortatil++;
        }
    }

    return quantidadeRequesicoesPorPortatil;
}
