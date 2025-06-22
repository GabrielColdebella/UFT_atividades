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

    char sair = 'n';
    int geracao = 0;
    TLinkedList *pop = criar_populacao_inicial();

    while (sair != 's')
    {
        printf("Geracao: %d\n", geracao);
        if (populacao_percorre(pop) == 1)
        {
            lista_imprime(pop);
            printf("Encerrou na geracao: %d\n", geracao);
            break;
        }
        else
        {
            pop = lista_quicksort(pop);
            pop = populacao_crossover(pop);
            populacao_substituicao(pop);
        }
        
        // if (geracao % 25 == 0)
        //     scanf("%c", &sair);
        
        geracao++;
    }
    lista_imprime(pop);

    return 0;
}