/*
Criação, mutação e manejo de um único indivíduo (vetor de movimentos).
*/

#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#define PENALIDADE 400
#include<stdbool.h>
#include <math.h>
#include<string.h>
#include "Mapa.h"

//  MUDAR tamanho fixo de movimentos para tamanho variavel (ver entrega parcial)
#define qtdMovimentosMax 25

typedef struct {
    int id;
    int qtdMovimentos;
    char seqMovimentos[qtdMovimentosMax];
    float fitness;
} TIndividuo;

void TIndividuoImprime(TIndividuo);
void TIndividuoPercorre(TIndividuo);
#endif