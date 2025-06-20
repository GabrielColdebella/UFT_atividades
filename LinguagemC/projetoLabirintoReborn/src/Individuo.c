#include "Individuo.h"
#include <stdio.h>

void TIndividuoImprime(TIndividuo ti)
{
    printf("id: %d\t%d\t", ti.id, ti.qtdMovimentos);
    for (int i = 0; i < qtdMovimentosMax; i++)
    {
        if (i == qtdMovimentosMax - 1)
        {
            printf("%c ", ti.seqMovimentos[i]);
        }
        else
        {
            printf("%c, ", ti.seqMovimentos[i]);
        }
    }
    printf("\t");
    printf("Fitness: %f\n", ti.fitness);
}

void TIndividuoPercorre(TIndividuo ti)
{
    char matriz[MAPHEI][MAPHEI];
    int coordenadaEntSai[2][2];
    mapaImportar(matriz, coordenadaEntSai);

    int posAtual[2];
    posAtual[0] = coordenadaEntSai[0][0];
    posAtual[1] = coordenadaEntSai[0][1];

    printf("\nid: %d\t", ti.id);
    for (int j = 0; j < ti.qtdMovimentos; j++)
    {
        printf("%c ", ti.seqMovimentos[j]);
    }
    printf("\t");

    for (int i = 0; i < ti.qtdMovimentos; i++)
    {

        if (ti.seqMovimentos[i] == 'C' && matriz[posAtual[0] - 1][posAtual[1]] != '#')
        {
            if (matriz[posAtual[0]][posAtual[1]] == ' ')
            {
                matriz[posAtual[0]][posAtual[1]] = '.';
            }
            posAtual[0] = posAtual[0] - 1;
        }
        else if (ti.seqMovimentos[i] == 'B' && matriz[posAtual[0] + 1][posAtual[1]] != '#')
        {
            if (matriz[posAtual[0]][posAtual[1]] == ' ')
            {
                matriz[posAtual[0]][posAtual[1]] = '.';
            }
            posAtual[0] = posAtual[0] + 1;
        }
        else if (ti.seqMovimentos[i] == 'D' && matriz[posAtual[0]][posAtual[1] + 1] != '#')
        {
            if (matriz[posAtual[0]][posAtual[1]] == ' ')
            {
                matriz[posAtual[0]][posAtual[1]] = '.';
            }
            posAtual[1] = posAtual[1] + 1;
        }
        else if (ti.seqMovimentos[i] == 'E' && matriz[posAtual[0]][posAtual[1] - 1] != '#')
        {
            if (matriz[posAtual[0]][posAtual[1]] == ' ')
            {
                matriz[posAtual[0]][posAtual[1]] = '.';
            }
            posAtual[1] = posAtual[1] - 1;
        }

        if ((posAtual[0] == coordenadaEntSai[1][0] && posAtual[1] == coordenadaEntSai[1][1]) || matriz[posAtual[0]][posAtual[1]] == 'S')
        {
            ti.fitness = 1000;
            printf("\nChegou na saida!\tid: %d", ti.id);
        }
        else
        {
            ti.fitness = 1000 - sqrt(pow((posAtual[0] - coordenadaEntSai[1][0]), 2) + pow((posAtual[1] - coordenadaEntSai[1][1]), 2)) - PENALIDADE;
            printf("Posicao de parada: %d e %d\tfit: %f", posAtual[0], posAtual[1], ti.fitness);
            break;
        }
    }

    // mapaVisualizar(matriz);
}