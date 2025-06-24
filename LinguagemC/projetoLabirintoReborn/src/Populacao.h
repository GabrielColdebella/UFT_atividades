#ifndef POPULACAO_H
#define POPULACAO_H
#include <stdbool.h>
#include "Individuo.h"

typedef struct _no TNo;
typedef struct _list TLinkedList;

/**
 * Cria instâncias da lista simplesmente encadeada.
 * @return TLinkedList* ponteiro para a lista alocada
 * */
TLinkedList *lista_criar();

/**
 * Tenta fazer a inserção no início da lista.
 * Por exemplo, se a sequência de inserção for 1, 2, 3,
 * a lista será [3] -> [2] -> [1]
 * @param TLinkedList* ponteiro para uma instância da lista
 * @param TIndividuo informação a ser armazenada na lista
 * @return bool informando o sucesso da operação
 */
bool lista_insere_comeco(TLinkedList *, TIndividuo);

/**
 * Tenta fazer a inserção no fim da lista.
 * Por exemplo, se a sequência de inserção for 1, 2, 3,
 * a lista será [1] -> [2] -> [3]
 * @param TLinkedList* ponteiro para uma instância da lista
 * @param TIndividuo informação a ser armazenada na lista
 * @return bool informando o sucesso da operação
 */
bool lista_insere_fim(TLinkedList *, TIndividuo);

/**
 * Imprime a lista no terminal.
 * @param TLinkedList* ponteiro para uma instância da lista
 */
void lista_imprime(TLinkedList *);

/**
 * Concatena duas listas.
 * @param l1 - primeira lista
 * @param l2 - segunda lista
 * @return TLinkedList - Ambas as listas juntas
 */
TLinkedList *lista_concatenar(TLinkedList *l1, TLinkedList *l2);

/**
 * Ordena a lista de acordo com o fitness, de forma decrescente.
 * @param lista
 * @return TLinkedList - Retorna lista organizada
 */
TLinkedList *lista_quicksort(TLinkedList *lista);

/**
 * Cria uma população inicial de individuos.
 * @return TLinkedList - A população
 */
TLinkedList *criar_populacao_inicial();

/**
 * Faz os individuos de uma população percorrerem o labirinto
 * @param lista
 * @return bool informando o sucesso da operação
 */
int populacao_percorre(TLinkedList *lista, float *melhorFitnessGeracao);

/**
 * Pega os primeiros individuos de uma lista e gera filhos
 * @param lista
 * @return TLinkedList - nova lista com os filhos inseridos
 */
TLinkedList *populacao_crossover(TLinkedList *lista);

/**
 * Substitui os individuos que já percorreram o labirinto anteriormente
 * @param lista
 * @return TLinkedList - nova lista com novos individuos (sem pais)
 */
TLinkedList *populacao_substituicao(TLinkedList *lista);
#endif