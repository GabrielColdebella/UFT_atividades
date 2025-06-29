#include "Mapa.h"
#include <stdio.h>
#include <string.h>

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

bool mapaImportar(char matriz[MAPHEI][MAPWID], int coordenada[2][2], char const *argv)
{
    FILE *fptr = fopen(argv, "r");

    if (fptr == NULL) {
        perror("Erro ao abrir o arquivo");
        return false;
    }
    //C:\\Users\\ghcso\\Documents\\UFT\\Programacao\\LinguagemC\\projetoLabirintoReborn\\dados\\mapa.txt
    // projetoLabirintoReborn\\dados\\mapa.txt

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
    FILE *fptr = fopen("..\\..\\projetoLabirintoReborn\\dados\\mapaGanhador.txt", "w");

    for (int i = 0; i < MAPHEI; i++){
        for (int j = 0; j < MAPWID; j++){
            fprintf(fptr, "%c", matriz[i][j]);
        }
        fprintf(fptr, "\n");
    }

    fclose(fptr);
}