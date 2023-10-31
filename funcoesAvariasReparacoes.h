#ifndef FUNCOESAVARIASREPARACOES_H_INCLUDED
#define FUNCOESAVARIASREPARACOES_H_INCLUDED

#include "constantes.h"
#include "funcoesLeitura.h"
#include "estruturas.h"

avariasPortateis *registarAvariaPortatil(int *quantidadeTotalAvarias, avariasPortateis *avariasInfosPortateis, int quantidadePortateisExistentes, int *quantidadePortateisDisponiveis, portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS]);
void listarAvariasPortateis(int quantidadeTotalAvarias, avariasPortateis *avariasInfosPortateis, int quantidadePortateisExistentes, portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS]);
void alterarTipoAvaria(int quantidadeTotalAvarias, avariasPortateis *avariasInfosPortateis);
void concluirAvariaPortatil(int quantidadeTotalAvarias, avariasPortateis *avariasInfosPortateis, int quantidadePortateisExistentes, int *quantidadePortateisDisponiveis, portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS]);
void gravaFicheiroBinarioAvarias(int quantidadeTotalAvarias, avariasPortateis *avariasInfosPortateis);
avariasPortateis *leFicheiroBinarioAvarias(int *quantidadeTotalAvarias, avariasPortateis *avariasInfosPortateis);
int procurarAvariaExistente(int quantidadeTotalAvarias, int codigoRequesicaoPretendido, avariasPortateis *avariasInfosPortateis);
int quantidadeAvariasPorNumIdentificacaoPortatil(int quantidadeTotalAvarias,  avariasPortateis *avariasInfosPortateis, int quantidadePortateisExistentes, portateisParaRequesicao portateisInfos[MAX_REGISTOS_PORTATEIS]);

#endif // FUNCOESAVARIASREPARACOES_H_INCLUDED
