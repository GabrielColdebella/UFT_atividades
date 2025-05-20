#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#define HEIGHT 10
#define WIDTH 10
#define PENALIDADE 200

typedef struct {
    int id;
    float fitness;
    int movimentoQtd;
    char movimentoFilho[99];
} Individuo;

void individuoCriar(Individuo *dv, int valorManhattan);
void individuoExportar(Individuo *dv);
int  individuoImportar(Individuo *dv, int id);
int  individuoPercorrer(Individuo *dv, char matriz[HEIGHT][WIDTH], int coordenadaEntSai[2][2]);
void individuoVisualizar(Individuo *dv);

#endif