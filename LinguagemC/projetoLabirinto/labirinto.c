#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define HEIGHT 10
#define WIDTH 10

// exporta dados para arquivo separado
int labirintoExportar(char matriz[HEIGHT][WIDTH]){
    FILE *fptr = fopen("labirinto.txt", "w");

    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            fprintf(fptr, "%c", matriz[i][j]);
        }
        fprintf(fptr, "\n");
    }

    fclose(fptr);
}

// cria o labirinto
int labirintoCriar(char matriz[HEIGHT][WIDTH]){
    //" ", "E", "S", "#"; 
    char gerador;
    int ent = 0, sai = 0;

    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            gerador = rand() % 5 + 0;

            if (i == 0 || i == (HEIGHT - 1) || j == 0 || j == (WIDTH - 1)){
                matriz[i][j] = '#';

            } else if (gerador == 3 && ent == 0){
                matriz[i][j] = 'E';
                ent = 1;

            } else if (gerador == 4 && sai == 0 && i > HEIGHT/2){
                matriz[i][j] = 'S';
                sai = 1;

            } else {
                if ((rand() % 3 + 0) < 2){
                    matriz[i][j] = ' ';

                } else {
                    matriz[i][j] = '#';

                }
            }
        }
    }

    labirintoExportar(matriz);
    return 0;
}

// importa dados armazenados em arquivo separado
int labirintoImportar(char matriz[HEIGHT][WIDTH]){
    FILE *fptr = fopen("labirinto.txt", "r");

    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            matriz[i][j] = fgetc(fptr);
        }
        fgetc(fptr);
    }

    return 0;
}

// imprime o labirinto
void labirintoVisualizar(char matriz[HEIGHT][WIDTH]){
    for (int i = 0; i < HEIGHT; i++){ 
        printf("\n");
        for (int j = 0; j < WIDTH; j++){
            printf("%c", matriz[i][j]);
        }
    }
}

// calcula a distacia manhattan era a entrada e a saida
void distManhattan (char matriz[HEIGHT][WIDTH], int distTotal[2], int pontosES[2][2]){
    int coordenada[2][2] = {{0, 0}, {0, 0}};

    // encontra os pontos E e S
    for (int i = 0; i < HEIGHT; i++){ 
        for (int j = 0; j < WIDTH; j++){
            if(matriz[i][j] == 'E') {
                coordenada[0][0] = i;
                coordenada[0][1] = j;
            };

            if(matriz[i][j] == 'S') {
                coordenada[1][0] = i;
                coordenada[1][1] = j;
            };
        }
    }

    // calcula o valor absoluto entre E e S
    distTotal[0] = abs(coordenada[0][0] - coordenada[1][0]);
    distTotal[1] = abs(coordenada[0][1] - coordenada[1][1]);

    pontosES[0][0] = coordenada[0][0];
    pontosES[0][1] = coordenada[0][1];

    pontosES[1][0] = coordenada[1][0];
    pontosES[1][1] = coordenada[1][1];
}
