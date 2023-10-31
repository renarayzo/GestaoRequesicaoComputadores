#ifndef FUNCOESMENUS_H_INCLUDED
#define FUNCOESMENUS_H_INCLUDED

#include "constantes.h"
#include "funcoesLeitura.h"

int menuPrincipal(int quantidadePortateisExistentes, int quantidadePortateisDisponiveis, int quantidadeTotalRequisicoes, int quantidadeRequesicoesAtivas);
int subMenuPortateis();
int subMenuRequesicoes();
int subMenuAvarias();
int subMenuEstatisticas();

#endif // FUNCOESMENUS_H_INCLUDED
