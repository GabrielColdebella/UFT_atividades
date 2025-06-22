#include "Populacao.h"
#include "Utilitario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main()
{
    srand(time(NULL));

    int geracao = 0;
    int sair = 0;
    TLinkedList *pop = criar_populacao_inicial();

    // && geracao < 2
    while (sair != 1)
    {
        printf("Geracao: %d\n", geracao);
        sair = populacao_percorre(pop);

        if (sair == 1)
        {
            printf("Encerrou na geracao: %d\n", geracao);
            // lista_imprime(pop);
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

    return 0;
}