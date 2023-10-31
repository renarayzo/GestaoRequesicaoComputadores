#include "funcoesAvariasReparacoes.h"

avariasPortateis *registarAvariaPortatil(int *quantidadeTotalAvarias, avariasPortateis *avariasInfosPortateis, int quantidadePortateisExistentes, int *quantidadePortateisDisponiveis, portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS]){
    int posicaoPortatil = 0, tipoAvariaInteiro = 0;
    char portatilPretendidoRegistarAvaria[MAX_NUM_DESIGNACAO_PORTATIL];
    avariasPortateis *avariasInfosPortateisBackUp;

    avariasInfosPortateisBackUp = avariasInfosPortateis;

    printf("\n\t\t\tRegistar Avaria\n");
    printf("-------------------------------------------------------------------");
    lerString("\nIntroduza o Numero de Identificacao do Portatil que Pretende Registar Uma Avaria: ", portatilPretendidoRegistarAvaria, MAX_NUM_IDENTIFICACAO_PORTATIL);
    posicaoPortatil = procurarPortatilExistente(quantidadePortateisExistentes, portatilPretendidoRegistarAvaria, portateisInfos);
    printf("-------------------------------------------------------------------\n");

    if(posicaoPortatil == -1){
        printf("\n-------------------------------------------------------------------");
        printf("\nNao Existe Nenhum Portatil Com o Numero de Identificacao Introduzido!");
        printf("\n-------------------------------------------------------------------");
    }
    else{
        if(strcmp(portateisInfos[posicaoPortatil].estadoRequesicaoPortatil, "Avariado") == 0){
            printf("\n-------------------------------------------------------------------");
            printf("\nJa Existe Um Registo de Avaria do Portatil Introduzido!\n");
            printf("-------------------------------------------------------------------");

        }
        else{
            avariasInfosPortateis = realloc(avariasInfosPortateis, (*quantidadeTotalAvarias+1)*sizeof(avariasPortateis));
            avariasInfosPortateis[*quantidadeTotalAvarias].codigoAvaria = *quantidadeTotalAvarias + 1;
            strcpy(avariasInfosPortateis[*quantidadeTotalAvarias].numIdentificacaoPortatil, portatilPretendidoRegistarAvaria);

            tipoAvariaInteiro = lerInteiro("Introduza o Tipo de Avaria Existente (1)Permanente (2)Temporaria ", MIN_ESCOLHA_TIPO_AVARIA, MAX_ESCOLHA_TIPO_AVARIA, "Erro!! Introduza Uma das Duas Opcoes!");
            switch(tipoAvariaInteiro){
                case 1:
                    strcpy(avariasInfosPortateis[*quantidadeTotalAvarias].tipoAvaria, "Permanente");
                    break;
                case 2:
                    strcpy(avariasInfosPortateis[*quantidadeTotalAvarias].tipoAvaria, "Temporaria");
                    break;
                default:
                    break;
            }

            strcpy(avariasInfosPortateis[*quantidadeTotalAvarias].estadoAvaria, "Ativa");

            do{
                avariasInfosPortateis[*quantidadeTotalAvarias].dataAvaria = lerData();
                if(avariasInfosPortateis[*quantidadeTotalAvarias].dataAvaria.ano < portateisInfos[posicaoPortatil].dataAquisicaoPortatil.ano){
                    printf("O Ano Introduzido tem de Ser Maior ou Igual ao Ano da Data de Aquisicao do Portatil -> %d \n", portateisInfos[posicaoPortatil].dataAquisicaoPortatil.ano);
                }
                else{
                    if(avariasInfosPortateis[*quantidadeTotalAvarias].dataAvaria.mes < portateisInfos[posicaoPortatil].dataAquisicaoPortatil.mes){
                        printf("O Mes Introduzido tem de Ser Maior ou Igual ao Mes da Data de Aquisicao do Portatil -> %d \n", portateisInfos[posicaoPortatil].dataAquisicaoPortatil.mes);
                    }
                    else{
                        if(avariasInfosPortateis[*quantidadeTotalAvarias].dataAvaria.mes == portateisInfos[posicaoPortatil].dataAquisicaoPortatil.mes)
                        {
                            if(avariasInfosPortateis[*quantidadeTotalAvarias].dataAvaria.dia < portateisInfos[posicaoPortatil].dataAquisicaoPortatil.dia){
                                printf("\nO Dia Introduzido tem de Ser Maior ou Igual ao Dia da Data de Aquisicao do Portatil -> %d \n", portateisInfos[posicaoPortatil].dataAquisicaoPortatil.dia);
                            }
                        }
                    }
                }
            }while(avariasInfosPortateis[*quantidadeTotalAvarias].dataAvaria.ano < portateisInfos[posicaoPortatil].dataAquisicaoPortatil.ano || (avariasInfosPortateis[*quantidadeTotalAvarias].dataAvaria.mes < portateisInfos[posicaoPortatil].dataAquisicaoPortatil.mes || (avariasInfosPortateis[*quantidadeTotalAvarias].dataAvaria.mes == portateisInfos[posicaoPortatil].dataAquisicaoPortatil.mes && avariasInfosPortateis[*quantidadeTotalAvarias].dataAvaria.dia < portateisInfos[posicaoPortatil].dataAquisicaoPortatil.dia)));

            if(strcmp(avariasInfosPortateis[*quantidadeTotalAvarias].tipoAvaria, "Permanente") == 0){
                //PORTATIL DEIXA DE PUDER SER REQUESITADO POIS É UMA AVARIA PERMANENTE
            }
            else{
                avariasInfosPortateis[*quantidadeTotalAvarias].duracaoAvaria = lerInteiro("\nIntroduza a Duracao da Avaria Em Dias ", MIN_DURACAO_AVARIA, MAX_DURACAO_AVARIA, "Erro!! Introduza Um Valor Valido!");
            }

            strcpy(portateisInfos[posicaoPortatil].estadoRequesicaoPortatil, "Avariado");
            (*quantidadePortateisDisponiveis)--;
            printf("\n-------------------------------------------------------------------\n");
            printf("Avaria Registada Com Sucesso!\n");
            printf("-------------------------------------------------------------------");
            (*quantidadeTotalAvarias)++;
            gravaFicheiroBinarioAvarias((*quantidadeTotalAvarias), avariasInfosPortateis);
            gravaFicheiroBinarioPortateis(portateisInfos, quantidadePortateisExistentes, (*quantidadePortateisDisponiveis));
        }
    }

    return avariasInfosPortateis;
}

void listarAvariasPortateis(int quantidadeTotalAvarias, avariasPortateis *avariasInfosPortateis, int quantidadePortateisExistentes, portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS]){
    int i = 0, posicaoPortatil = 0;

    printf("\n-------------------------------------------------------------------");
    printf("\n\t\tListagem Das Avarias Existentes\n");
    printf("-------------------------------------------------------------------");

    for(i = 0; i < quantidadeTotalAvarias; i++){
        posicaoPortatil = procurarPortatilExistente(quantidadePortateisExistentes, avariasInfosPortateis[i].numIdentificacaoPortatil, portateisInfos);

        printf("\nCodigo Avaria -> %i", avariasInfosPortateis[i].codigoAvaria);
        printf("\n-------------------------------------------------------------------");
        printf("\nNumero Identificacao do Portatil: %s", portateisInfos[posicaoPortatil].numIdentificacaoPortatil);
        printf("\nDesignacao do Portatil: %s", portateisInfos[posicaoPortatil].designacaoPortatil);
        printf("\nProcessador do Portatil: %s", portateisInfos[posicaoPortatil].processadorPortatil);
        printf("\nMemoria RAM do Portatil: %i GB", portateisInfos[posicaoPortatil].memoriaRamPortatil);
        printf("\nEstado Requesicao do Portatil: %s", portateisInfos[posicaoPortatil].estadoRequesicaoPortatil);
        printf("\nLocalizacao do Portatil: %s", portateisInfos[posicaoPortatil].localizacaoPortatil);
        printf("\nDia da Aquisicao do Portatil: %i", portateisInfos[posicaoPortatil].dataAquisicaoPortatil.dia);
        printf("\nMes da Aquisicao do Portatil: %i", portateisInfos[posicaoPortatil].dataAquisicaoPortatil.mes);
        printf("\nAno da Aquisicao do Portatil: %i", portateisInfos[posicaoPortatil].dataAquisicaoPortatil.ano);
        printf("\nValor do Portatil: %.2f", portateisInfos[i].valorPortatil);
        printf("\nTipo de Avaria: %s", avariasInfosPortateis[i].tipoAvaria);
        printf("\nEstado Avaria: %s", avariasInfosPortateis[i].estadoAvaria);
        printf("\nTempo de Duracao Avaria: %i", avariasInfosPortateis[i].duracaoAvaria);
        printf("\n-------------------------------------------------------------------");
    }
}

void alterarTipoAvaria(int quantidadeTotalAvarias, avariasPortateis *avariasInfosPortateis){
    int codigoAvariaPretendidoConcluir = 0, posicaoAvaria = 0, tipoAvariaInteiro = 0;

    printf("\n\tAlterar Tipo Avaria Avaria\n");
    printf("-------------------------------------------------------------------");
    codigoAvariaPretendidoConcluir = lerInteiro("\nIntroduza o Codigo de Avaria que Pretende Alterar o Tipo De Avaria ", MIN_CODIGO_AVARIA, quantidadeTotalAvarias, "Erro! Codigo de Avaria Invalido!\n");
    posicaoAvaria = procurarAvariaExistente(quantidadeTotalAvarias, codigoAvariaPretendidoConcluir, avariasInfosPortateis);
    printf("-------------------------------------------------------------------\n");


    tipoAvariaInteiro = lerInteiro("Introduza o Tipo de Avaria Existente (1)Permanente (2)Temporaria ", MIN_ESCOLHA_TIPO_AVARIA, MAX_ESCOLHA_TIPO_AVARIA, "Erro!! Introduza Uma das Duas Opcoes!");
    switch(tipoAvariaInteiro){
        case 1:
            strcpy(avariasInfosPortateis[posicaoAvaria].tipoAvaria, "Permanente");
            avariasInfosPortateis[posicaoAvaria].duracaoAvaria = 0;
            break;
        case 2:
            strcpy(avariasInfosPortateis[posicaoAvaria].tipoAvaria, "Temporaria");
            avariasInfosPortateis[posicaoAvaria].duracaoAvaria = lerInteiro("\nIntroduza a Duracao da Avaria Em Dias ", MIN_DURACAO_AVARIA, MAX_DURACAO_AVARIA, "Erro!! Introduza Um Valor Valido!");
            break;
        default:
            break;
    }
    printf("\n-------------------------------------------------------------------\n");
    printf("Tipo de Avaria Alterada Com Sucesso!\n");
    printf("-------------------------------------------------------------------");
}

void concluirAvariaPortatil(int quantidadeTotalAvarias, avariasPortateis *avariasInfosPortateis, int quantidadePortateisExistentes, int *quantidadePortateisDisponiveis, portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS]){
    int posicaoPortatil = 0, codigoAvariaPretendidoConcluir = 0, posicaoAvaria = 0;

    printf("\n\t\tConcluir Avaria\n");
    printf("-------------------------------------------------------------------");
    codigoAvariaPretendidoConcluir = lerInteiro("\nIntroduza o Codigo de Avaria que Pretende Concluir ", MIN_CODIGO_AVARIA, quantidadeTotalAvarias, "Erro! Codigo de Avaria Invalido!\n");
    posicaoAvaria = procurarAvariaExistente(quantidadeTotalAvarias, codigoAvariaPretendidoConcluir, avariasInfosPortateis);
    posicaoPortatil = procurarPortatilExistente(quantidadePortateisExistentes, avariasInfosPortateis[posicaoAvaria].numIdentificacaoPortatil, portateisInfos);
    printf("-------------------------------------------------------------------\n");

    if(strcmp(avariasInfosPortateis[posicaoAvaria].tipoAvaria, "Permanente") == 0){
        printf("\n-------------------------------------------------------------------\n");
        printf("Erro!! Avaria Impossivel de Concluir Pois Esta e Permanente!\n");
        printf("-------------------------------------------------------------------");
    }
    else{
        if(strcmp(avariasInfosPortateis[posicaoAvaria].estadoAvaria, "Concluida") == 0){
            printf("\n-------------------------------------------------------------------\n");
            printf("Erro!! A Avaria Introduzida Ja foi Concluida Anteriormente!\n");
            printf("-------------------------------------------------------------------");
        }
        else{
            strcpy(portateisInfos[posicaoPortatil].estadoRequesicaoPortatil, "Disponivel");
            strcpy(avariasInfosPortateis[posicaoAvaria].estadoAvaria, "Concluida");
            printf("\n-------------------------------------------------------------------\n");
            printf("Avaria Concluida Com Sucesso!\n");
            printf("-------------------------------------------------------------------");
            (*quantidadePortateisDisponiveis)++;
            gravaFicheiroBinarioAvarias(quantidadeTotalAvarias, avariasInfosPortateis);
            gravaFicheiroBinarioPortateis(portateisInfos, quantidadePortateisExistentes, (*quantidadePortateisDisponiveis));
        }
    }
}

void gravaFicheiroBinarioAvarias(int quantidadeTotalAvarias, avariasPortateis *avariasInfosPortateis){
    FILE *ficheiroAvarias;

    ficheiroAvarias = fopen("InfosAvarias.dat", "wb");
    if(ficheiroAvarias == NULL)
    {
        printf("-------------------------------------------------------------------\n");
        printf("Erro ao abrir o ficheiro!\n");
        printf("-------------------------------------------------------------------\n");
    }
    else
    {
        fwrite(&quantidadeTotalAvarias, sizeof(int), 1, ficheiroAvarias);
        fwrite(avariasInfosPortateis, sizeof(avariasPortateis), quantidadeTotalAvarias, ficheiroAvarias);
        fclose(ficheiroAvarias);
    }
}

avariasPortateis *leFicheiroBinarioAvarias(int *quantidadeTotalAvarias, avariasPortateis *avariasInfosPortateis){
    FILE *ficheiroAvarias;
    avariasPortateis *avariasInfosPortateisBackUp;

    ficheiroAvarias = fopen("InfosAvarias.dat", "rb");
    if(ficheiroAvarias == NULL)
    {

    }
    else
    {
        fread(&(*quantidadeTotalAvarias), sizeof(int), 1, ficheiroAvarias);
        avariasInfosPortateis = realloc(avariasInfosPortateis, (*quantidadeTotalAvarias)*sizeof(avariasPortateis));
        if(avariasInfosPortateis == NULL && *quantidadeTotalAvarias != 0){
            printf("\n-------------------------------------------------------------------\n");
            printf("Erro ao Reservar Espaço na Memória!\n");
            printf("\n-------------------------------------------------------------------");
        }
        else{
            fread(avariasInfosPortateis, sizeof(avariasPortateis), *quantidadeTotalAvarias, ficheiroAvarias);
        }
        fclose(ficheiroAvarias);
    }

    return avariasInfosPortateis;
}

int procurarAvariaExistente(int quantidadeTotalAvarias, int codigoAvariaPretendido, avariasPortateis *avariasInfosPortateis){
    int i = 0, valido = -1;

    //Se valido = -1 (A avaria nao Existe)
    for(i = 0; i < quantidadeTotalAvarias; i++){
        if(avariasInfosPortateis[i].codigoAvaria == codigoAvariaPretendido){
            valido = i;
        }
    }

    return valido;
}

int quantidadeAvariasPorNumIdentificacaoPortatil(int quantidadeTotalAvarias,  avariasPortateis *avariasInfosPortateis, int quantidadePortateisExistentes, portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS]){
    int i = 0, quantidadeAvariasPorPortatil = 0, posicaoPortatil = 0;

    for(i = 0; i < quantidadeTotalAvarias; i++){
        posicaoPortatil = procurarPortatilExistente(quantidadePortateisExistentes, avariasInfosPortateis[i].numIdentificacaoPortatil, portateisInfos);
        if(strcmp(avariasInfosPortateis[i].numIdentificacaoPortatil, portateisInfos[posicaoPortatil].numIdentificacaoPortatil) == 0){
            quantidadeAvariasPorPortatil++;
        }
    }

    return quantidadeAvariasPorPortatil;
}

