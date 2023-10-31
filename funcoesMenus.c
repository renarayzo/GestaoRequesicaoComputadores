#include "funcoesMenus.h"

int menuPrincipal(int quantidadePortateisExistentes, int quantidadePortateisDisponiveis, int quantidadeTotalRequisicoes, int quantidadeRequesicoesAtivas){
    int opcao = 0;

    printf("\t\t\tBEM VINDO | MENU PRINCIPAL\n");
    printf("---------------------------------------------------------------------------\n");
    printf("Quantidade Portateis Existentes: %d\tQuantidade Portateis Disponiveis: %d\n", quantidadePortateisExistentes, quantidadePortateisDisponiveis);
    printf("Quantidade Total Requisicoes: %d\t\tQuantidade Requisicoes Ativas: %d\n", quantidadeTotalRequisicoes, quantidadeRequesicoesAtivas);
    printf("---------------------------------------------------------------------------\n");
    printf("1 - Sub-Menu Portateis\n");
    printf("2 - Sub-Menu Requisicoes\n");
    printf("3 - Sub-Menu Avarias\n");
    printf("4 - Sub-Menu Estatisticas\n");
    printf("0 - Sair\n");
    printf("---------------------------------------------------------------------------\n");
    opcao = lerInteiro("Opcao ",ZERO, MAX_OPCAO, "Erro!! Opcao Invalida, Introduza Novamente!\n");

    return opcao;
}

int subMenuPortateis(){
    int opcao = 0;

    printf("\n\t\t\tSubMenu Portateis\n");
    printf("-------------------------------------------------------------------\n");
    printf("1 - Registar Informacao Referente aos Portateis\n");
    printf("2 - Listar Informacao Referente aos Portateis\n");
    printf("3 - Alterar Localizacao de Um Portatil\n");
    printf("4 - Guardar Informacao dos Portateis Num Ficheiro Binario\n");
    printf("0 - Voltar ao Menu Principal\n");
    printf("-------------------------------------------------------------------\n");
    opcao = lerInteiro("Opcao ",ZERO, MAX_OPCAO_SUBPORTATEIS, "Erro!! Opcao Invalida, Introduza Novamente!\n");

    return opcao;
}

int subMenuRequesicoes(){
    int opcao = 0;

    printf("\n\t\t\tSubMenu Requisicoes\n");
    printf("-------------------------------------------------------------------\n");
    printf("1 - Registar uma Requisicao de Um Portatil\n");
    printf("2 - Listar Informacao Referente as Requisicoes\n");
    printf("3 - Listar as Informacoes de Uma Determinada Requisicao\n");
    printf("4 - Renovar Uma Determinada Requisicao\n");
    printf("5 - Concluir uma Determinada Requisicao\n");
    printf("6 - Guardar Informacao das Requesicoes Num Ficheiro Binario\n");
    printf("0 - Voltar ao Menu Principal\n");
    printf("-------------------------------------------------------------------\n");
    opcao = lerInteiro("Opcao ",ZERO, MAX_OPCAO_SUBREQUESICOES, "Erro!! Opcao Invalida, Introduza Novamente!\n");

    return opcao;
}

int subMenuAvarias(){
    int opcao = 0;

    printf("\n\t\t\tSubMenu Avarias\n");
    printf("-------------------------------------------------------------------\n");
    printf("1 - Registar uma Avaria de Um Portatil\n");
    printf("2 - Listar Informacao Referente as Avarias\n");
    printf("3 - Alterar Tipo de Avaria\n");
    printf("4 - Concluir Avaria de Um Portatil\n");
    printf("0 - Voltar ao Menu Principal\n");
    printf("-------------------------------------------------------------------\n");
    opcao = lerInteiro("Opcao ",ZERO, MAX_OPCAO_SUBAVARIAS, "Erro!! Opcao Invalida, Introduza Novamente!\n");

    return opcao;
}

int subMenuEstatisticas(){
    int opcao = 0;

    printf("\n\t\t\tSubMenu Dados Estatisticos\n");
    printf("-------------------------------------------------------------------\n");
    printf("1 - Percentagem de Portateis com Cada Tipo de Processador\n");
    printf("2 - Custo Medio de Cada Multa Paga\n");
    printf("3 - Tipos de Utentes com a Menor Quantidade de Requesicoes\n");
    printf("4 - Devolucao(oes) Mais Recente(s)\n");
    printf("0 - Voltar ao Menu Principal\n");
    printf("-------------------------------------------------------------------\n");
    opcao = lerInteiro("Opcao ",ZERO, MAX_OPCAO_ESTATISTICAS, "Erro!! Opcao Invalida, Introduza Novamente!\n");

    return opcao;
}
