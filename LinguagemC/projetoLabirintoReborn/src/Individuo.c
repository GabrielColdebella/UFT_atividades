#include "Individuo.h"
#include <stdio.h>

TIndividuo TIndividuoCriar()
{
    char movimentos[4] = {'C', 'B', 'D', 'E'};
    int static idIndividuo = 0, i;
    TIndividuo ti;

    // acessa o individuo e insere os dados
    ti.id = idIndividuo++;
    ti.fitness = 0;

    // monta aleatoriamente a sequencia de movimentos do invididuo
    for (i = 0; i < qtdMovimentosMax; i++)
        ti.seqMovimentos[i] = movimentos[rand() % 4 + 0];

    return ti;
}

void TIndividuoImprime(TIndividuo ti)
{
    int i;

    // imprime o id, os movimentos e o fitness do individuo
    printf("id: %d\t", ti.id);
    for (i = 0; i < qtdMovimentosMax; i++)
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

int TIndividuoPercorre(TIndividuo *ti, char const *argv)
{
    // inicializa variaveis e logo preenche com os dados do mapa
    // formato do labirinto e coordenada da entrada e saida
    char matriz[MAPHEI][MAPWID];
    int coordenadaEntSai[2][2], i;
    if (!mapaImportar(matriz, coordenadaEntSai, argv))
        return 2;

    // monta a posição atual y e x de acordo com a coordenada da entrada
    int posAtualY = coordenadaEntSai[0][0];
    int posAtualX = coordenadaEntSai[0][1];
    int chegou = false;
    int j;

    for (i = 0; i < qtdMovimentosMax; i++)
    {
        // a proxima posição recebe a coordenada atual
        int novaY = posAtualY;
        int novaX = posAtualX;

        char possiveis[4];
        j = 0;

        // checar movimentos válidos
        if (matriz[novaY - 1][novaX] != '#') possiveis[j++] = 'C';
        if (matriz[novaY + 1][novaX] != '#') possiveis[j++] = 'B';
        if (matriz[novaY][novaX + 1] != '#') possiveis[j++] = 'D';
        if (matriz[novaY][novaX - 1] != '#') possiveis[j++] = 'E';
        if (j == -1) break; 

        // escolher aleatório entre os válidos
        ti->seqMovimentos[i]  = possiveis[rand() % j];

        //"calcula" o movimento
        switch (ti->seqMovimentos[i])
        {
        case 'C':
            novaY--;
            break;
        case 'B':
            novaY++;
            break;
        case 'D':
            novaX++;
            break;
        case 'E':
            novaX--;
            break;
        }

        // se bater em um muro, interrompe o loop
        if (matriz[novaY][novaX] == '#')
            break;

        // atualiza posição
        posAtualY = novaY;
        posAtualX = novaX;

        // checa se chegou na saída
        if (matriz[posAtualY][posAtualX] == 'S')
        {
            chegou = true;
            break;
        }
    }

    // se chegou, o fitness é mil.
    // Caso contrario, calcula a dist euclidiana
    if (chegou)
    {
        ti->fitness = 100;
        return 1;
    }
    else
    {
        // pontua de acordo da distancia entre a posAtual e a saida
        float dx = posAtualY - coordenadaEntSai[1][0];
        float dy = posAtualX - coordenadaEntSai[1][1];
        ti->fitness = 100 - sqrt(dx * dx + dy * dy) * 10 - PENALIDADE;
        return 0;
    }
}

TIndividuo TIndividuoCrossover(TIndividuo *pai1, TIndividuo *pai2)
{
    TIndividuo filho = TIndividuoCriar();

    // escolhe o ponto de separação dos genes entre 25% e 75% da sequencia de movimentos
    int pontoCorte = rand() % (qtdMovimentosMax / 2 + 1) + qtdMovimentosMax / 4, i, j;
    // escolhe aleatoriamente de qual pai vai ser a primeira parte do genes
    int genesInicial = rand() % 2;

    // gera uma mutação em um lugar aleatorio
    int mutacaoComeco;
    // coloca um fim na mutação em algum lugar apos o começo
    int mutacaoFinal;
    char movimentos[4] = {'C', 'B', 'D', 'E'};

    for (j = 0; j < qtdMovimentosMax; j++)
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

    // mutação - altera em um lugar e quantidade aleatoria o genes do filho
    if (rand() % 100 < porcentagemMutacao)
    {
        mutacaoComeco = rand() % qtdMovimentosMax;
        mutacaoFinal = mutacaoComeco + rand() % (qtdMovimentosMax - mutacaoComeco);

        for (i = mutacaoComeco; i < mutacaoFinal; i++)
        {
            filho.seqMovimentos[i] = movimentos[rand() % 4 + 0];
        }
    }

    return filho;
}

int TIndividuoVisualizarSeqMovimentos(TIndividuo *ti, char const *argv)
{
    // inicializa variaveis e logo preenche com os dados do mapa
    // formato do labirinto e coordenada da entrada e saida
    char matriz[MAPHEI][MAPWID];
    int coordenadaEntSai[2][2];
    mapaImportar(matriz, coordenadaEntSai, argv);

    // monta a posição atual y e x de acordo com a coordenada da entrada
    int posAtualY = coordenadaEntSai[0][0];
    int posAtualX = coordenadaEntSai[0][1];
    bool chegou = false;

    for (int i = 0; i < qtdMovimentosMax; i++)
    {
        // a proxima posição recebe a coordenada atual
        int novaY = posAtualY;
        int novaX = posAtualX;

        //"calcula" o movimento
        switch (ti->seqMovimentos[i])
        {
        case 'C':
            novaY--;
            break;
        case 'B':
            novaY++;
            break;
        case 'D':
            novaX++;
            break;
        case 'E':
            novaX--;
            break;
        }

        // se bater em um muro, interrompe o loop
        if (matriz[novaY][novaX] == '#')
            break;

        // marca o movimento no mapa
        if (matriz[posAtualY][posAtualX] == ' ')
            matriz[posAtualY][posAtualX] = '.';

        // atualiza posição
        posAtualY = novaY;
        posAtualX = novaX;

        // checa se chegou na saída
        if (matriz[posAtualY][posAtualX] == 'S')
        {
            chegou = true;
            break;
        }
    }

    // se chegou de verdade, mostra e exporta o mapa.
    // Caso contrario, retorna 0
    if (chegou)
    {
        mapaVisualizar(matriz);
        mapaExportar(matriz);
        return 1;
    }
    else
    {
        return 0;
    }
}

bool TIndividuoCriaArquivoCSV()
{
    FILE *fptr;
    fptr = fopen("..\\..\\projetoLabirintoReborn\\dados\\logExperimento.csv", "w");

    fclose(fptr);
    return true;
}

bool TIndividuoGuardaFitnessCSV(TIndividuo *ti, int id)
{
    FILE *fptr;
    fptr = fopen("..\\..\\projetoLabirintoReborn\\dados\\logExperimento.csv", "a");

    fprintf(fptr, "%d;%2.f;", id, ti->fitness);

    for (int j = 0; j < qtdMovimentosMax; j++)
    {
        fprintf(fptr, "%c", ti->seqMovimentos[j]);
    }
    fprintf(fptr, ";\n");

    fclose(fptr);

    return true;
}