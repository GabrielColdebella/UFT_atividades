#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int array[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    
    // Imprimir o array original
    for (int i = 0; i < 2; i++) {
        printf("\nLinha %d:", i);
        for (int x = 0; x < 5; x++) {
            printf(" %d", array[i][x]);
        }
    }
    printf("\n\n------------------------------------\n\n");

    // Zerando toda a linha array[0]
    memset(array[0], 0, sizeof(array[0]));

    // Imprimir o array após a modificação
    for (int i = 0; i < 2; i++) {
        printf("\nLinha %d:", i);
        for (int x = 0; x < 5; x++) {
            printf(" %d", array[i][x]);
        }
    }
    printf("\n\n");
}