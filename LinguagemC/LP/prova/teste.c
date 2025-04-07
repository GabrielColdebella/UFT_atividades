#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    //Recebe a quantidade total de entrevistas
    /* --------------------------------------------------------------- */
    int qtdRegistros, qtdRegistrosTotal;

    FILE *fptr;

    fptr = fopen("prova_arquivo3.bin", "rb");
    
    //apenas para pegar o total de registros
    int *pegaTotalRegistros = malloc(sizeof(int));
    fread(pegaTotalRegistros, sizeof(int), 1, fptr);

    if (pegaTotalRegistros[0] == 0){
        pegaTotalRegistros[0] = pegaTotalRegistros[0] + 1;
    }
    
    qtdRegistros = pegaTotalRegistros[0];
    qtdRegistrosTotal = (qtdRegistros * 5) + 5;
    // 5 -> Porque são 5 dados distintos; 5 -> Quantidade de separadores; 
    /* --------------------------------------------------------------- */


    int seletor1, seletor2;
    int candidatoPresidenciaEscolhido[qtdRegistros];
    int candidatoGovernadorEscolhido[qtdRegistros];
    int dadosEleitor[3][qtdRegistros];
    //idade, faixa e mês

    //zera as arrays, visto que tava dando um bug esquisito
    memset(candidatoPresidenciaEscolhido, 0, sizeof(candidatoPresidenciaEscolhido));
    memset(candidatoGovernadorEscolhido, 0, sizeof(candidatoGovernadorEscolhido));
    memset(dadosEleitor, 0, sizeof(dadosEleitor));

    //aluga espaço na memoria em bytes, a quantidade de entrevistas * 4 (tamanho do int)
    int *buffer = malloc(qtdRegistrosTotal * sizeof(int));
    //insere no espaço todos os registros, cujo o espaço foi alugado
    fread(buffer, sizeof(int), qtdRegistrosTotal, fptr);
    //qtdRegistrosTotal

    printf("\nregistro todos: %d", qtdRegistros);
    
    for (int i = 0; i < qtdRegistrosTotal; i++){

        printf("\nregistro atual, %d: %d", i, buffer[i]);

        // if (buffer[i + 1] == 999){
        //     break;
        // }
        
    }
    
    fclose(fptr);
    return 0;
}