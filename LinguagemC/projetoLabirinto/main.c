// usar:
// gcc main.c labirinto.c individuo.c -o programa.exe
// .\programa.exe

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "labirinto.h"
#include "individuo.h"

#define HEIGHT 10
#define WIDTH 10
#define PENALIDADE 200


int main(){
    srand(time(NULL));

    char labirinto[HEIGHT][WIDTH];
    int  distFinal[2], coordenadaEntSai[2][2]; 
    
    labirintoImportar(labirinto);
    // labirintoCriar(labirinto);
    // labirintoExportar();
    distManhattan(labirinto, distFinal, coordenadaEntSai);
    // labirintoVisualizar(labirinto);
    
    
    Individuo ind1;
    individuoImportar(&ind1, 5);
    // individuoCriar(&ind1, (distFinal[0] + distFinal[1]));


    individuoVisualizar(&ind1);
    
    individuoPercorrer(&ind1, labirinto, coordenadaEntSai);
    // individuoExportar(&ind1);
    
    return 0;

}