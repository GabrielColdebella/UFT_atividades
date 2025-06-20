#include "Populacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main()
{
    srand(time(NULL));
    printf("Hello World!");

    TLinkedList *pop = criar_populacao_inicial();
    // lista_imprime(pop);

    printf("\n\n\n");

    populacao_percorre(pop);
    return 0;
}