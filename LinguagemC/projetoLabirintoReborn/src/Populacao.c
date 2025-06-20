#include "Populacao.h"
#include <stdlib.h>
#include <stdio.h>
#include<stdbool.h>


typedef struct _no{
    TIndividuo conteudo;
    struct _no *prox;
}TNo;
TNo* TNo_criaEPreenche(TIndividuo);

typedef struct _list{
    TNo* inicio;
}TLinkedList;


TLinkedList* lista_criar(){
    TLinkedList* nova = malloc(sizeof(TLinkedList));
    if(nova){
        nova->inicio = NULL;
    }
    return nova;
}


bool lista_insere_comeco(TLinkedList* lista, TIndividuo conteudo){
    TNo* novo = TNo_criaEPreenche(conteudo);
    if(novo == NULL) return false;
    if(lista->inicio != NULL)
        novo->prox = lista->inicio;
    lista->inicio = novo;
    return true;
}

bool lista_insere_fim(TLinkedList* lista, TIndividuo conteudo){
    TNo* novo = TNo_criaEPreenche(conteudo);
    if(novo == NULL) return false;
    //A lista está vazia?
    if(lista->inicio == NULL)
        lista->inicio = novo;
    else{
        //Lista nao vazia, temos que encontrar o último elemento
        TNo* aux = lista->inicio;
        while(aux->prox!=NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return true;
}


void lista_imprime(TLinkedList* lista){
    TNo* aux = lista->inicio;
    while(aux!=NULL){
        TIndividuoImprime(aux->conteudo);
        aux = aux->prox;
    }
    putchar('\n');
}

TNo* TNo_criaEPreenche(TIndividuo conteudo){
    TNo* novo = malloc(sizeof(TNo));
    if(novo){
        novo->conteudo = conteudo;
        novo->prox = NULL;
    }
    return novo;
}

//Resolve a parte de lista encadeada
// -------------------------------------------------------------------------
//Começa a solucionar o problema da população

TLinkedList *criar_populacao_inicial()
{
    TLinkedList *popInicial = lista_criar();

    char movimentos[] = {'C', 'B', 'D', 'E'};

    for (int i = 1; i <= maxPopulacao; i++)
    {
        TIndividuo ti;
        ti.id = i;
        ti.qtdMovimentos = qtdMovimentosMax;
        // ti.fitness = rand() % 100 + 0;
        ti.fitness = 0;

        for (int j = 0; j < qtdMovimentosMax; j++)
        {
            ti.seqMovimentos[j] = movimentos[rand() % 4 + 0];
        }

        if (!lista_insere_fim(popInicial, ti))
            break;
    }
    return popInicial;
}

void populacao_percorre(TLinkedList* lista){
    TNo* aux = lista->inicio;
    while(aux!=NULL){
        TIndividuoPercorre(aux->conteudo);
        aux = aux->prox;
    }
    putchar('\n');
}