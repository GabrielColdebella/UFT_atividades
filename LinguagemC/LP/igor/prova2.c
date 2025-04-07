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

void analisarDados() {
    FILE *arquivo = fopen("dados.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    entrevista entrevistados[numMeses][maxEntrevistado]; 
    int totalEntrevistas[numMeses];

    for (int mes = 0; mes < numMeses; mes++) {
        totalEntrevistas[mes] = fread(entrevistados[mes], sizeof(entrevista), maxEntrevistado, arquivo);
    }

    fclose(arquivo);

    int op;
    do {
        printf("\nMenu de Analise:\n");
        printf("[1] Intencao de votos para Presidencia\n");
        printf("[2] Intencao de votos para Governo\n");
        printf("[3] Fidelidade Partidaria\n");
        printf("[4] Intencao a Presidencia por faixa salarial\n");
        printf("[5] Intencao final dos mais jovens\n");
        printf("[6] Relatorio por mes\n");
        printf("[0] Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: {
                int votos17 = 0, votos26 = 0, brancos = 0, indecisos = 0, total = 0;
                for (int mes = 0; mes < numMeses; mes++) {
                    for (int i = 0; i < totalEntrevistas[mes]; i++) {
                        total++;
                        switch (entrevistados[mes][i].votoPresidencia) {
                            case 17: votos17++; break;
                            case 26: votos26++; break;
                            case 0: brancos++; break;
                            case 99: indecisos++; break;
                        }
                    }
                }
                printf("Intencao de votos para Presidencia:\n");
                printf("17: %.2f%%\n", (votos17 * 100.0) / total);
                printf("26: %.2f%%\n", (votos26 * 100.0) / total);
                printf("Brancos: %.2f%%\n", (brancos * 100.0) / total);
                printf("Indecisos: %.2f%%\n", (indecisos * 100.0) / total);
                break;
            }
            case 2:{
                int votos17 = 0, votos26 = 0, votos31 = 0, brancos = 0, indecisos = 0, total = 0;
                    for (int mes = 0; mes < numMeses; mes++) {
                        for (int i = 0; i < totalEntrevistas[mes]; i++) {
                            total++;
                            switch (entrevistados[mes][i].votoGoverno) {
                                case 17: votos17++; break;
                                case 26: votos26++; break;
                                case 31: votos31++; break;
                                case 0: brancos++; break;
                                case 99: indecisos++; break;
                            }
                        }
                    }
                    printf("Intencao de votos para Presidencia:\n");
                    printf("17: %.2f%%\n", (votos17 * 100.0) / total);
                    printf("26: %.2f%%\n", (votos26 * 100.0) / total);
                    printf("26: %.2f%%\n", (votos31 * 100.0) / total);
                    printf("Brancos: %.2f%%\n", (brancos * 100.0) / total);
                    printf("Indecisos: %.2f%%\n", (indecisos * 100.0) / total);
                break;
            }
            case 3:{
                int total = 0, fidelidade = 0;
                    for (int mes = 0; mes < numMeses; mes++) {
                        for (int i = 0; i < totalEntrevistas[mes]; i++) {
                            if (entrevistados[mes][i].votoPresidencia == entrevistados[mes][i].votoGoverno && (entrevistados[mes][i].votoPresidencia == 17 || entrevistados[mes][i].votoPresidencia == 26)) {
                            fidelidade++;
                            }
                            total++;
                        }
                    }
                    printf("Fidelidade partidaria: %.2f%%\n", (fidelidade * 100.0) / total);
                break;
            }
            case 4:{
                int faixa;
                printf("Escolha a faixa salarial ([0]- menor que 3 salarios, [1]- entre 3 e 5 salarios, [2]-maior que 5 salarios. ");
                scanf("%d", &faixa);

                int mes = 0, votos17 = 0, votos26 = 0, total = 0;
                for (mes = 0; mes < numMeses; mes++) {
                    for (int i = 0; i < totalEntrevistas[mes]; i++) {
                        if (entrevistados[mes][i].faixaSalarial == faixa) {
                            total++;
                            switch (entrevistados[mes][i].votoPresidencia) {
                                case 17: votos17++; break;
                                case 26: votos26++; break;
                                
                            }
                        }
                    }
                }
                if(votos17 > votos26){
                                    printf("Candidato de numero 17 eh maior");
                                }else{
                                    printf("Candidato de numero 26 eh maior");
                                }
                break;
            }
            
            break;
            case 5: {
                int votos17 = 0, votos26 = 0, brancos = 0, indecisos = 0, total = 0;
                for (int i = 0; i < totalEntrevistas[numMeses - 1]; i++) {
                    if (entrevistados[numMeses - 1][i].idade < 30) {
                        total++;
                        switch (entrevistados[numMeses - 1][i].votoPresidencia) {
                            case 17: votos17++; break;
                            case 26: votos26++; break;
                            case 0: brancos++; break;
                            case 99: indecisos++; break;
                        }
                    }
   
                }

                printf("\nIntencao de votos dos mais jovens no ultimo mes:\n");
                printf("17: %.2f%%\n", (votos17 * 100.0) / total);
                printf("26: %.2f%%\n", (votos26 * 100.0) / total);
                printf("Brancos: %.2f%%\n", (brancos * 100.0) / total);
                printf("Indecisos: %.2f%%\n", (indecisos * 100.0) / total);
                break;
            }
            case 6: {
                int mes;
                printf("Informe o mes para o relatorio (1 a 3)");
                scanf("%d", &mes);

                if (mes < 1 || mes > numMeses){
                    printf("Mes invelido.\n");
                } else{
                    mes--; 
                    printf("Relatorio do Mes %d:\n", mes + 1);
                    for (int i = 0; i < totalEntrevistas[mes]; i++) {
                        printf("Entrevistado %d: Presidencia=%d, Governo=%d, Idade=%d, Faixa Salarial=%d\n", i + 1, entrevistados[mes][i].votoPresidencia, entrevistados[mes][i].votoGoverno, entrevistados[mes][i].idade, entrevistados[mes][i].faixaSalarial);
                    }
                }
                break;
            }
            case 0:{
                printf("Encerrando analise.\n");
                break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
            }    
        }   
    } while (op != 0);
}

int main(){
    analisarDados();

    return 0;
}