/*
Parser (tira do texto e bota em codigo) do arquivo ASCII e funções de acesso à matriz do labirinto.
*/

#ifndef MAPA_H
#define MAPA_H
#define MAPHEI 10
#define MAPWID 10
#include <stdbool.h>

void mapaVisualizar(char matriz[MAPHEI][MAPWID]);
bool mapaImportar(char matriz[MAPHEI][MAPWID], int coordenada[2][2]);
#endif