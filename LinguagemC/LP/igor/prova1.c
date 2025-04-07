#include <stdio.h>
#include <stdlib.h>

#define maxEntrevistado 30
#define numMeses 3

typedef struct{
    int votoPresidencia;
    int votoGoverno;
    int idade;
    int faixaSalarial;

} entrevista; 

void registro(){ 
    FILE *arquivo = fopen("dados.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!.\n");
        return;
    }

    for (int mes = 0; mes < numMeses ;mes++) {
        int numEntrevistado;
        printf("Registro de entrevistas - Mes %d\n", mes + 1);
        printf("Quantas pessoas para ser entrevistadas no Mes %d (20 a 30)? ", mes + 1);
        
        scanf("%d", &numEntrevistado);

        if (numEntrevistado < 2 || numEntrevistado > 4) {
            printf("Numero invalido. A quantidade deve ser entre 20 e 30.\n");
            fclose(arquivo);
            return;
        }   
        entrevista entrevistados[numMeses][maxEntrevistado];

        for (int i = 0; i < numEntrevistado; i++) { 
            printf("\nEntrevistado %d:\n", i + 1);
            printf("Qual seu candidato a Presidencia? ([17], [26], [0] para branco, [99] para indeciso): ");
            scanf("%d", &entrevistados[mes][i].votoPresidencia);

            printf("Qual seu candidato ao Governo do Estado? ([17], [26], [31], [0] para branco, [99] para indeciso): ");
            scanf("%d", &entrevistados[mes][i].votoGoverno);

            printf("Qual sua idade? ");
            scanf("%d", &entrevistados[mes][i].idade);

            printf("Qual sua faixa salarial? ([0]: < 3 salarios, [1]: 3 a 5 salarios, [2]: > 5 salarios): ");
            scanf("%d", &entrevistados[mes][i].faixaSalarial);;
        }
            
        fwrite(entrevistados, sizeof(entrevista), numEntrevistado, arquivo);

    }
    fclose(arquivo);
    printf("\nDados registrados e salvos com sucesso\n");
}
int main(){
    registro();
    return 0;
}