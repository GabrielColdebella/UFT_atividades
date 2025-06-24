#ifndef MAPA_H
#define MAPA_H
#include <stdbool.h>
#include "Parametros.h"

/**
 * Mostra o mapa importado no terminal.
 * @param matriz - Matriz de char
 */
void mapaVisualizar(char matriz[MAPHEI][MAPWID]);

/**
 * Importa o mapa de um arquivo de texto salvo na pasta do projeto.
 * @param matriz - Matriz que será inserido os dados importados.
 * @param coordenada - Coordenada de entrada e saída do labirinto
 * @return bool informando o sucesso da operação
 */
bool mapaImportar(char matriz[MAPHEI][MAPWID], int coordenada[2][2]);

/**
 * Exporta o mapa gerado para um arquivo de texto na pasta do projeto.
 * @param matriz - Matriz que será exportada.
 * @return int informando o sucesso da operação
 */
int mapaExportar(char matriz[MAPHEI][MAPWID]);
#endif