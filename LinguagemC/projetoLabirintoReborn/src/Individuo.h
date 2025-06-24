#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "Mapa.h"

typedef struct
{
    int id;
    char seqMovimentos[qtdMovimentosMax];
    float fitness;
} TIndividuo;

/**
 * Monta o individuo, inserindo:
 * static id para tornar cada individuo unico
 * fitness para mostrar a eficiencia
 * seqMovimentos de forma aleatoria
 * @return TIndividuo
 */
TIndividuo TIndividuoCriar();

/**
 * Tem como objetivo imprimir todos os dados do individuo.
 * @param TIndividuo
 */
void TIndividuoImprime(TIndividuo);

/**
 * Faz o individuo percorrer o labirinto.
 * Insere um fitness baseado na distancia que falta até a saída.
 * @param TIndividuo
 * @return int - se a operação foi um sucesso ou não.
 */
int TIndividuoPercorre(TIndividuo *ti, char const *argv);

/**
 * Gera um filho com os genes de ambos os pais.
 * Há possibilidade de nascer com mutação
 * @param pai1
 * @param pai2
 * @return TIndividuo - o filho
 */
TIndividuo TIndividuoCrossover(TIndividuo *pai1, TIndividuo *pai2);

/**
 * Gera um filho com os genes de ambos os pais.
 * Há possibilidade de nascer com mutação
 * @param TIndividuo
 * @return int - A verificação se o individuo chegou mesmo na saída.
 */
int TIndividuoVisualizarSeqMovimentos(TIndividuo *ti, char const *argv);

bool TIndividuoCriaArquivoCSV();

bool TIndividuoGuardaFitnessCSV(TIndividuo *ti, int id);
#endif