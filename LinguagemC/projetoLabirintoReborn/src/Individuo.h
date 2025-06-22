/*
Criação, mutação e manejo de um único indivíduo (vetor de movimentos).
*/

#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#define PENALIDADE 400
#define porcentagemMutacao 5
#include<stdbool.h>
#include <math.h>
#include<string.h>
#include<stdlib.h>
#include "Mapa.h"

//  MUDAR tamanho fixo de movimentos para tamanho variavel (ver entrega parcial)
#define qtdMovimentosMax 30

typedef struct {
    int id;
    int qtdMovimentos;
    char seqMovimentos[qtdMovimentosMax];
    float fitness;
} TIndividuo;

TIndividuo TIndividuoCriar();
void TIndividuoImprime(TIndividuo);
int TIndividuoPercorre(TIndividuo *ti);
TIndividuo TIndividuoCrossover(TIndividuo *pai1, TIndividuo *pai2);
#endif