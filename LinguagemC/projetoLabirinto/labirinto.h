#ifndef LABIRINTO_H
#define LABIRINTO_H

#define HEIGHT 10
#define WIDTH 10

void labirintoCriar(char matriz[HEIGHT][WIDTH]);
void labirintoExportar(char matriz[HEIGHT][WIDTH]);
void labirintoImportar(char matriz[HEIGHT][WIDTH]);
void labirintoVisualizar(char matriz[HEIGHT][WIDTH]);
void distManhattan(char matriz[HEIGHT][WIDTH], int distTotal[2], int pontosES[2][2]);

#endif