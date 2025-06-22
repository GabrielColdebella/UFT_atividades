/*
Lista encadeada da população; seleção e substituição.
*/

#ifndef POPULACAO_H
#define POPULACAO_H
#define maxPopulacao 100
#define porcentagemMelhores 25
#include<stdbool.h>
#include "Individuo.h"

typedef struct _no TNo;
typedef struct _list TLinkedList;

/**
 * Cria instâncias da lista simplesmente encadeada.
 * @return TLinkedList* ponteiro para a lista alocada
 * */
TLinkedList* lista_criar();
/**
 * Tenta fazer a inserção no início da lista. 
 * Por exemplo, se a sequência de inserção for 1, 2, 3, 
 * a lista será [3] -> [2] -> [1]
 * @param TLinkedList* ponteiro para uma instância da lista
 * @param TIndividuo informação a ser armazenada na lista
 * @return bool informando o sucesso da operação
 */
bool lista_insere_comeco(TLinkedList*, TIndividuo);
/**
 * Tenta fazer a inserção no fim da lista. 
 * Por exemplo, se a sequência de inserção for 1, 2, 3, 
 * a lista será [1] -> [2] -> [3]
 * @param TLinkedList* ponteiro para uma instância da lista
 * @param TIndividuo informação a ser armazenada na lista
 * @return bool informando o sucesso da operação
 */
bool lista_insere_fim(TLinkedList*, TIndividuo);
/**
 * Faz a impressão da lista para checagem.
 * @param TLinkedList* ponteiro para uma instância da lista
 */

 /**
 * Tenta deletar o elemento do início. 
 * Por exemplo, se a lista é [1] -> [2] -> [3], apos a chamada, 
 * a Lista se tornará [2] -> [3]
 * @param TLinkedList* ponteiro para uma instância da lista
 * @return bool informando o sucesso da operação
 */
bool list_delete_begin(TLinkedList*);
void lista_imprime(TLinkedList*);

TLinkedList *criar_populacao_inicial();
int populacao_percorre(TLinkedList* lista);
bool criar_populacao_crossover(TLinkedList*);

TLinkedList* lista_concatenar(TLinkedList* l1, TLinkedList* l2);
TLinkedList *lista_quicksort(TLinkedList *lista);
TLinkedList *populacao_crossover(TLinkedList *lista);
TLinkedList *populacao_substituicao(TLinkedList *lista);
#endif