#include <stdlib.h>
#include <stdio.h>
#include "Parametros.h"

// void resgatarParametros()
// {
//     FILE *fptr = fopen("..\\..\\projetoLabirintoReborn\\dados\\parametros.txt", "r");

//     fscanf(fptr, "mapa_altura=%d\n", &MAPHEI);
//     fscanf(fptr, "mapa_largura=%d\n", &MAPWID);
//     fscanf(fptr, "penalidade_fitness=%d\n", &PENALIDADE);
//     fscanf(fptr, "porcentagem_mutacao=%d\n", &porcentagemMutacao);
//     fscanf(fptr, "quantidade_maxima_movimentos=%d\n", &qtdMovimentosMax);
//     fscanf(fptr, "populacao_maxima=%d\n", &maxPopulacao);
//     fscanf(fptr, "porcentagem_melhores=%d\n", &porcentagemMelhores);

//     printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t", MAPHEI,
//            MAPWID,
//            PENALIDADE,
//            porcentagemMutacao,
//            qtdMovimentosMax,
//            maxPopulacao,
//            porcentagemMelhores);

//     fclose(fptr);
//     return 1;
// }