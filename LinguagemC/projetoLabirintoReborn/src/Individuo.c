#include "Individuo.h"
#include <stdio.h>

TIndividuo TIndividuoCriar()
{
    char movimentos[4] = {'C', 'B', 'D', 'E'};
    int static idIndividuo = 0;

    TIndividuo ti;
    ti.id = idIndividuo++;
    ti.qtdMovimentos = qtdMovimentosMax;
    ti.fitness = 0;

    for (int i = 0; i < qtdMovimentosMax; i++)
        ti.seqMovimentos[i] = movimentos[rand() % 4 + 0];

    return ti;
}

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

int TIndividuoPercorre(TIndividuo *ti)
{
    char matriz[MAPHEI][MAPHEI];
    int coordenadaEntSai[2][2];
    mapaImportar(matriz, coordenadaEntSai);

    int posAtual[2];
    posAtual[0] = coordenadaEntSai[0][0];
    posAtual[1] = coordenadaEntSai[0][1];

    for (int i = 0; i < ti->qtdMovimentos; i++)
    {

        if (ti->seqMovimentos[i] == 'C' && matriz[posAtual[0] - 1][posAtual[1]] != '#')
        {
            if (matriz[posAtual[0]][posAtual[1]] == ' ')
            {
                matriz[posAtual[0]][posAtual[1]] = '.';
            }
            posAtual[0] = posAtual[0] - 1;
        }
        else if (ti->seqMovimentos[i] == 'B' && matriz[posAtual[0] + 1][posAtual[1]] != '#')
        {
            if (matriz[posAtual[0]][posAtual[1]] == ' ')
            {
                matriz[posAtual[0]][posAtual[1]] = '.';
            }
            posAtual[0] = posAtual[0] + 1;
        }
        else if (ti->seqMovimentos[i] == 'D' && matriz[posAtual[0]][posAtual[1] + 1] != '#')
        {
            if (matriz[posAtual[0]][posAtual[1]] == ' ')
            {
                matriz[posAtual[0]][posAtual[1]] = '.';
            }
            posAtual[1] = posAtual[1] + 1;
        }
        else if (ti->seqMovimentos[i] == 'E' && matriz[posAtual[0]][posAtual[1] - 1] != '#')
        {
            if (matriz[posAtual[0]][posAtual[1]] == ' ')
            {
                matriz[posAtual[0]][posAtual[1]] = '.';
            }
            posAtual[1] = posAtual[1] - 1;
        }

        if ((posAtual[0] == coordenadaEntSai[1][0] && posAtual[1] == coordenadaEntSai[1][1]) || matriz[posAtual[0]][posAtual[1]] == 'S')
        {
            ti->fitness = 1000;
            return 1;
        }
        else
        {
            ti->fitness = 1000 - sqrt(pow((posAtual[0] - coordenadaEntSai[1][0]), 2) + pow((posAtual[1] - coordenadaEntSai[1][1]), 2)) * 10 - 300;
            break;
        }
    }
    return 0;
}

TIndividuo TIndividuoCrossover(TIndividuo *pai1, TIndividuo *pai2)
{
    TIndividuo filho = TIndividuoCriar();

    // escolhe o ponto de separação entre 25% e 75% da sequencia de movimentos
    int pontoCorte = rand() % (qtdMovimentosMax / 2 + 1) + qtdMovimentosMax / 4;
    // escolhe aleatoriamente de qual pai vai ser a primeira parte do genes
    int genesInicial = rand() % 2;

    //gera uma mutação em um lugar aleatorio
    int mutacaoComeco;
    //coloca um fim na mutação em algum lugar apos o começo
    int mutacaoFinal;
    char movimentos[4] = {'C', 'B', 'D', 'E'};

    for (int j = 0; j < qtdMovimentosMax; j++)
    {
        if (j < pontoCorte)
        {
            if (genesInicial == 0)
            {
                filho.seqMovimentos[j] = pai1->seqMovimentos[j];
            }
            else
            {
                filho.seqMovimentos[j] = pai2->seqMovimentos[j];
            }
        }
        else
        {
            if (genesInicial == 0)
            {
                filho.seqMovimentos[j] = pai2->seqMovimentos[j];
            }
            else
            {
                filho.seqMovimentos[j] = pai1->seqMovimentos[j];
            }
        }
    }

    //mutação
    //altera em um lugar e quantidade aleatoria o genes do filho
    if (rand() % 100 < porcentagemMutacao){
        mutacaoComeco = rand() % qtdMovimentosMax;
        mutacaoFinal = mutacaoComeco + rand() % (qtdMovimentosMax - mutacaoComeco);

        for (int i = mutacaoComeco; i < mutacaoFinal; i++)
        {
            filho.seqMovimentos[i] = movimentos[rand() % 4 + 0];
        }
    }

    return filho;
}