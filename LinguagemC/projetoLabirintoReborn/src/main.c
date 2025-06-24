#include "Parametros.h"
#include "Populacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main()
{
    TIndividuoCriaArquivoCSV();
    srand(time(NULL));

    // inicializa as variaveis e cria uma população inicial
    int geracao = 0;
    int sair = 0;
    float melhorFitness = 0, melhorFitnessGeracao = 0;
    TLinkedList *pop = criar_populacao_inicial();

    while (sair != 1 && geracao < 1000)
    {
        printf("Geracao: %d\n", geracao);
        sair = populacao_percorre(pop, &melhorFitnessGeracao);

        if (melhorFitnessGeracao > melhorFitness)
            melhorFitness = melhorFitnessGeracao;

        if (sair == 1)
        {
            printf("\nEncerrou na geracao: %d\n", geracao);
            break;
        }
        else
        {
            pop = lista_quicksort(pop);
            pop = populacao_crossover(pop);
            pop = populacao_substituicao(pop);
        }
        geracao++;
    }
    printf("\nMelhor fitness de todos: %2.f\n", melhorFitness);
    return 0;
}