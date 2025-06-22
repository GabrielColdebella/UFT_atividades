#include "Mapa.h"
#include <stdio.h>

void mapaVisualizar(char matriz[MAPHEI][MAPWID])
{
    for (int i = 0; i < MAPHEI; i++)
    {
        printf("\n");
        for (int j = 0; j < MAPWID; j++)
        {
            printf("%c", matriz[i][j]);
        }
    }
}

bool mapaImportar(char matriz[MAPHEI][MAPWID], int coordenada[2][2])
{
    FILE *fptr = fopen("C:\\Users\\ghcso\\Documents\\UFT\\Programacao\\LinguagemC\\projetoLabirintoReborn\\dados\\mapa.txt", "r");

    for (int i = 0; i < MAPHEI; i++)
    {
        for (int j = 0; j < MAPWID; j++)
        {
            matriz[i][j] = fgetc(fptr);

            if(matriz[i][j] == 'E') {
                coordenada[0][0] = i;
                coordenada[0][1] = j;
            };

            if(matriz[i][j] == 'S') {
                coordenada[1][0] = i;
                coordenada[1][1] = j;
            };
        }
        fgetc(fptr);
    }
    fclose(fptr);
    return true;
}

// exporta dados para arquivo separado
int mapaExportar(char matriz[MAPHEI][MAPWID]){
    FILE *fptr = fopen("C:\\Users\\ghcso\\Documents\\UFT\\Programacao\\LinguagemC\\projetoLabirintoReborn\\dados\\mapaGanhador.txt", "w");

    for (int i = 0; i < MAPHEI; i++){
        for (int j = 0; j < MAPWID; j++){
            fprintf(fptr, "%c", matriz[i][j]);
        }
        fprintf(fptr, "\n");
    }

    fclose(fptr);
}