#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define HEIGHT 10
#define WIDTH 10
#define PENALIDADE 200

typedef struct {
    int id;
    float fitness;
    int movimentoQtd;
    char movimentoFilho[99];
} Individuo;

// exporta os dados do individuo para um arquivo separado
int individuoExportar(Individuo *dv){
    FILE *fptr = fopen("individuo.txt", "a");
    fprintf(fptr, "\n");

    fprintf(fptr, "ID\n%d\n", dv->id);
    fprintf(fptr, "%f", dv->fitness);
    fprintf(fptr, "\n%d\n", dv->movimentoQtd);

    for (int i = 0; i < dv->movimentoQtd; i++){
        fprintf(fptr, "%c", dv->movimentoFilho[i]);
    }

    fprintf(fptr, "\n");
    
    fclose(fptr);
    return 0;
};

// importa os dados do individuo de um arquivo separado
int individuoImportar(Individuo *dv, int indId){
    FILE *fptr = fopen("individuo.txt", "r");

    char buffer[20];
    int idTemp;

    while (fgets(buffer, sizeof(buffer), fptr)) {
        if (strncmp(buffer, "ID", 2) == 0) {
            fscanf(fptr, "%d", &idTemp);

            if (idTemp == indId) {
                dv->id = idTemp;
                fscanf(fptr, "\n%f", &dv->fitness);
                fscanf(fptr, "\n%d\n", &dv->movimentoQtd);

                for (int i = 0; i < dv->movimentoQtd; i++) {
                    fscanf(fptr, "%c", &dv->movimentoFilho[i]);
                }

                fclose(fptr);
                return 0;
            }
        }
    }
    fclose(fptr);

    return 0;
}

// prepara o individuo para tentar resolver o labirinto
int individuoCriar(Individuo *dv, int valorManhattan){
    // pega algum valor entre o valor manhattan do ponto E ao S e o dobro desse valor
    dv->movimentoQtd = rand() % ((valorManhattan * 2) - valorManhattan + 1) + valorManhattan;
    char movimentoTipos[4] = {'C', 'B', 'E', 'D'}; 
    
    for (int i = 0; i < dv->movimentoQtd; i++){
        dv->movimentoFilho[i] = movimentoTipos[rand() % 4];
    }
    
    return 0;
}

// faz o individuo percorrer o labirinto
int individuoPercorrer(Individuo *dv, char matriz[HEIGHT][WIDTH], int coordenadaEntSai[2][2]){
    int posAtual[2];
    posAtual[0] = coordenadaEntSai[0][0];
    posAtual[1] = coordenadaEntSai[0][1];

    for (int i = 0; i < dv->movimentoQtd; i++){
        if(dv->movimentoFilho[i] == 'C' && matriz[posAtual[0] - 1][posAtual[1]] != '#'){
            posAtual[0] = posAtual[0] - 1;

        } else if(dv->movimentoFilho[i] == 'B' && matriz[posAtual[0] + 1][posAtual[1]] != '#'){
            posAtual[0] = posAtual[0] + 1;

        } else if(dv->movimentoFilho[i] == 'D' && matriz[posAtual[0]][posAtual[1] + 1] != '#'){
            posAtual[1] = posAtual[1] + 1;

        } else if(dv->movimentoFilho[i] == 'E' && matriz[posAtual[0]][posAtual[1] - 1] != '#'){
            posAtual[1] = posAtual[1] - 1;

        } else {
            printf("\nBateu na parede");
            printf("\nPosição atual: %d e %d", posAtual[0], posAtual[1]);

            dv->fitness = 1000 - sqrt(pow((posAtual[0] - coordenadaEntSai[1][0]), 2) + pow((posAtual[1] - coordenadaEntSai[1][1]), 2)) - PENALIDADE;
            return 0;
        }

        if((posAtual[0] == coordenadaEntSai[1][0] && posAtual[1] == coordenadaEntSai[1][1]) || matriz[posAtual[0]][posAtual[1]] == 'S'){
            dv->fitness = 1000;
            printf("\nChegou na saída!");
            return 1;
        }
    }


    printf("\nPosição atual: %d e %d", posAtual[0], posAtual[1]);
    dv->fitness = 1000 - sqrt(pow((posAtual[0] - coordenadaEntSai[1][0]), 2) + pow((posAtual[1] - coordenadaEntSai[1][1]), 2));
    
    return 0;
}

void individuoVisualizar(Individuo *dv){
    printf("\nId: %d", dv->id);
    printf("\nFitness: %f", dv->fitness);
    printf("\nMovimentos: ");
    for (int i = 0; i < dv->movimentoQtd; i++){
        printf("%c", dv->movimentoFilho[i]);
    }
}