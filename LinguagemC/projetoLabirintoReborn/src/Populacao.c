#include "Populacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _no
{
    TIndividuo conteudo;
    struct _no *prox;
} TNo;
TNo *TNo_criaEPreenche(TIndividuo);

typedef struct _list
{
    TNo *inicio;
} TLinkedList;

TLinkedList *lista_criar()
{
    TLinkedList *nova = malloc(sizeof(TLinkedList));
    if (nova)
    {
        nova->inicio = NULL;
    }
    return nova;
}

bool lista_insere_comeco(TLinkedList *lista, TIndividuo conteudo)
{
    TNo *novo = TNo_criaEPreenche(conteudo);
    if (novo == NULL)
        return false;

    if (lista->inicio != NULL)
        novo->prox = lista->inicio;
    lista->inicio = novo;
    return true;
}

bool lista_insere_fim(TLinkedList *lista, TIndividuo conteudo)
{
    TNo *novo = TNo_criaEPreenche(conteudo);
    if (novo == NULL)
        return false;

    // A lista está vazia?
    if (lista->inicio == NULL)
        lista->inicio = novo;
    else
    {
        // Lista nao vazia, temos que encontrar o último elemento
        TNo *aux = lista->inicio;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return true;
}

void lista_imprime(TLinkedList *lista)
{
    if (lista == NULL)
    {
        printf("Lista esta nula\n");
        return;
    }

    TNo *aux = lista->inicio;
    int i = 0;

    while (aux != NULL)
    {
        printf("Imprimindo individuo #%d;", i);
        TIndividuoImprime(aux->conteudo);
        aux = aux->prox;
        i++;
    }
    putchar('\n');
}

TNo *TNo_criaEPreenche(TIndividuo conteudo)
{
    TNo *novo = malloc(sizeof(TNo));
    if (novo)
    {
        novo->conteudo = conteudo;
        novo->prox = NULL;
    }
    return novo;
}

// resolve a parte de lista encadeada
//  -------------------------------------------------------------------------
// soluciona o problema da organização dos dados

// concatena 2 listas
TLinkedList *lista_concatenar(TLinkedList *l1, TLinkedList *l2)
{
    // se l1 estiver vazia, retorna l2
    if (!l1->inicio)
    {
        free(l1);
        return l2;
    }

    // percorre até o último nó e faz apontar para o começo de l2
    TNo *aux = l1->inicio;
    while (aux->prox)
        aux = aux->prox;
    aux->prox = l2->inicio;
    free(l2);
    return l1;
}

// separa os individuos de acordo com o fitness em 3 grupo (>, <, ==)
// faz isso recursivamente para que a lista final apresente os dados de forma decrescente
TLinkedList *lista_quicksort(TLinkedList *lista)
{
    // lista vazia ou com 1 elemento
    if (!lista || !lista->inicio || !lista->inicio->prox)
        return lista;

    //  menor, igual ou maior que o pivo (primeiro elemento)
    TLinkedList *menor = lista_criar();
    TLinkedList *igual = lista_criar();
    TLinkedList *maior = lista_criar();

    TNo *aux = lista->inicio;

    //  acessando o primeiro elemento
    float pivo = aux->conteudo.fitness;

    while (aux != NULL)
    {
        if (aux->conteudo.fitness < pivo)
        {
            lista_insere_fim(menor, aux->conteudo);
        }
        else if (aux->conteudo.fitness > pivo)
        {
            lista_insere_fim(maior, aux->conteudo);
        }
        else
        {
            lista_insere_fim(igual, aux->conteudo);
        }

        aux = aux->prox;
    }

    free(lista);

    menor = lista_quicksort(menor);
    maior = lista_quicksort(maior);

    // decrescente
    TLinkedList *listaFinal = lista_concatenar(maior, igual);
    listaFinal = lista_concatenar(listaFinal, menor);

    // crescente
    //  TLinkedList *listaFinal = lista_concatenar(menor, igual);
    //  listaFinal = lista_concatenar(listaFinal, maior);

    return listaFinal;
}

//  -------------------------------------------------------------------------
// começa a solucionar o problema da população

TLinkedList *criar_populacao_inicial()
{
    TLinkedList *popInicial = lista_criar();

    for (int i = 1; i <= maxPopulacao; i++)
    {
        if (!lista_insere_fim(popInicial, TIndividuoCriar()))
            break;
    }
    return popInicial;
}

int populacao_percorre(TLinkedList *lista, float *melhorFitness, char const *argv)
{
    TNo *aux = lista->inicio;
    *melhorFitness = 0;
    int resultado;
    int static idGeracao = 0;

    while (aux != NULL)
    {
        resultado = TIndividuoPercorre(&aux->conteudo, argv);

        TIndividuoGuardaFitnessCSV(&aux->conteudo, idGeracao);
        // TIndividuoImprime(aux->conteudo);
        
        if (aux->conteudo.fitness > *melhorFitness)
        {
            *melhorFitness = aux->conteudo.fitness;
        }

        if (resultado == 1)
        {
            printf("\nseq de movimentos do ganhador\t");
            for (int i = 0; i < qtdMovimentosMax; i++)
            {
                printf("%c, ", aux->conteudo.seqMovimentos[i]);
            }
            *melhorFitness = aux->conteudo.fitness;
            TIndividuoGuardaFitnessCSV(&aux->conteudo, idGeracao);
            TIndividuoVisualizarSeqMovimentos(&aux->conteudo, argv);
            return 1;
        }
        else if (resultado == 2)
        {
            return 2;
        }
        aux = aux->prox;
    }

    idGeracao++;
    return 0;
}

TLinkedList *populacao_crossover(TLinkedList *lista)
{
    TNo *aux = lista->inicio;
    TIndividuo temp;
    TLinkedList *nova = lista_criar();
    int i = 0;

    while (aux != NULL && i < maxPopulacao * porcentagemMelhores / 100)
    {
        if (i % 2 == 0)
        {
            temp = aux->conteudo;
        }
        else
        {
            for (int j = 0; j < 2; j++)
            {
                lista_insere_fim(nova, TIndividuoCrossover(&temp, &aux->conteudo));
            }
        }
        i = i + 1;
        aux = aux->prox;
    }
    return lista_concatenar(nova, lista);
}

// ignorara a geração atual(quem nao tiver fintess) e substituira a geracao anterior(quem tiver fitness)
TLinkedList *populacao_substituicao(TLinkedList *lista)
{
    TLinkedList *nova = lista_criar();
    TNo *aux = lista->inicio;
    TNo *temp = nova->inicio;
    int i = 0;

    while (aux != NULL)
    {
        if (aux->conteudo.fitness == 0)
        {
            lista_insere_fim(nova, aux->conteudo);
            i++;
        }
        aux = aux->prox;
    }

    free(lista);

    for (int j = 0; j < maxPopulacao - i; j++)
    {
        lista_insere_fim(nova, TIndividuoCriar());
    }

    return nova;
}