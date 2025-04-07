#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    /* --------------------------------------------------------------- */
    //Recebe a quantidade total de entrevistas

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
    qtdRegistrosTotal = (qtdRegistros * 5) + 4;
    // 5 -> Porque são 5 dados distintos; 5 -> Quantidade de separadores; 

    /* --------------------------------------------------------------- */
    //inicia váriaveis e faz outras coisas importantes
    int opUser;

    int seletor1, seletor2, seletor3, seletor4[2][3];
    int qtdVotos[2][5];
    int candidatoPresidenciaEscolhido[qtdRegistros];
    int candidatoGovernadorEscolhido[qtdRegistros];
    int dadosEleitor[3][qtdRegistros];
    //[0] idade;[1] faixa;[2] mês;

    //zera as arrays, visto que tava dando um bug esquisito na hora de inserir dados
    memset(qtdVotos, 0, sizeof(qtdVotos));
    memset(candidatoPresidenciaEscolhido, 0, sizeof(candidatoPresidenciaEscolhido));
    memset(candidatoGovernadorEscolhido, 0, sizeof(candidatoGovernadorEscolhido));
    memset(dadosEleitor, 0, sizeof(dadosEleitor));

    //aluga espaço na memoria em bytes, a quantidade de entrevistas * 4 (tamanho do int)
    int *buffer = malloc(qtdRegistrosTotal * sizeof(int));
    //insere no espaço todos os registros, cujo o espaço foi alugado
    fread(buffer, sizeof(int), qtdRegistrosTotal, fptr);

    /* --------------------------------------------------------------- */
    // tira do buffer e bota nas arrays

    seletor2 = 0; 
    //começa o loop e para de acordo com a qtd de entrevista
    for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++) {

        if (buffer[seletor2] == 0){
            qtdVotos[0][0]++;
        }
        else if(buffer[seletor2] == 1){
            qtdVotos[0][1]++;
        }
        else if(buffer[seletor2] == 17){
            qtdVotos[0][2]++;
        }
        else if(buffer[seletor2] == 26){
            qtdVotos[0][3]++;
        }
        
        //apesar do seletor1 sempre ser resetado, o seletor continua rodando na lista
        candidatoPresidenciaEscolhido[seletor1] = buffer[seletor2];
        seletor2++;
    }

    for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++) {
        //quando o seletor2 parar no separador, ele vai adicionar +1 e vai continuar no proximo
        //nesse caso, vai colocar na lista de votados para governador
        //nunca demorei tanto pra pensar em um codigo T_T
        if (buffer[seletor2] == 999){
            seletor2++;
        }

       if (buffer[seletor2] == 0){
            qtdVotos[1][0]++;
        }
        else if(buffer[seletor2] == 1){
            qtdVotos[1][1]++;
        }
        else if(buffer[seletor2] == 17){
            qtdVotos[1][2]++;
        }
        else if(buffer[seletor2] == 26){
            qtdVotos[1][3]++;
        }
        else if(buffer[seletor2] == 31){
            qtdVotos[1][4]++;
        }
        

        candidatoGovernadorEscolhido[seletor1] = buffer[seletor2];
        seletor2++;
    }

    for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++) {
        if (buffer[seletor2] == 999){
            seletor2++;
        }

        dadosEleitor[0][seletor1] = buffer[seletor2];
        seletor2++;
    }

    for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++) {
        if (buffer[seletor2] == 999){
            seletor2++;
        }

        dadosEleitor[1][seletor1] = buffer[seletor2];
        seletor2++;
    }

    for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++) {
        if (buffer[seletor2] == 999){
            seletor2++;
        }

        dadosEleitor[2][seletor1] = buffer[seletor2];
        seletor2++;
    }
    /* --------------------------------------------------------------- */

    do
    {
        printf("\n\nEscolha:");
        printf("\n\t[0] Sair ");
        printf("\n\t[1] Intenção de votos para ");
        printf("\n\t[2] Intenção de votos para Governo ");
        printf("\n\t[3] Fidelidade Partidária ");
        printf("\n\t[4] Intenção à Presidência por faixa salarial");
        printf("\n\t[5] Intenção final dos mais jovens ");
        printf("\n\t[6] Relatório por mês");
        printf("\n\t[7] Todos os votos");
        printf("\nOpção: ");
        scanf(" %d", &opUser);

        seletor1 = 0;
        seletor2 = 0;
        seletor3 = 0;
        memset(seletor4, 0, sizeof(seletor4));

        switch (opUser){
            case 1:

                printf("\nPorcentagem de votos em branco:\t %.2f",  (float) (qtdVotos[0][0] * 100) / qtdRegistros);
                printf("\nPorcentagem de indecisos:\t %.2f",        (float) (qtdVotos[0][1] * 100) / qtdRegistros);
                printf("\nPorcentagem de votos em 17:\t %.2f",      (float) (qtdVotos[0][2] * 100) / qtdRegistros);
                printf("\nPorcentagem de votos em 26:\t %.2f",      (float) (qtdVotos[0][3] * 100) / qtdRegistros);

                
                break;

            case 2:

                printf("\nPorcentagem de votos em branco:\t %.2f",  (float) (qtdVotos[1][0] * 100) / qtdRegistros);
                printf("\nPorcentagem de indecisos:\t %.2f",        (float) (qtdVotos[1][1] * 100) / qtdRegistros);
                printf("\nPorcentagem de votos em 17:\t %.2f",      (float) (qtdVotos[1][2] * 100) / qtdRegistros);
                printf("\nPorcentagem de votos em 26:\t %.2f",      (float) (qtdVotos[1][3] * 100) / qtdRegistros);
                printf("\nPorcentagem de votos em 31:\t %.2f",      (float) (qtdVotos[1][4] * 100) / qtdRegistros);
                break;

            case 3:

                for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++){
                    if (candidatoPresidenciaEscolhido[seletor1] == candidatoGovernadorEscolhido[seletor1]){
                        seletor2++;
                    }
                }
                printf("\nQuantidade de pessoas que votaram em candidatos do mesmo partido: %d", seletor2);
                break;

            case 4:

                printf("\nQual é a faixa salarial?\n\t[0] Menos que 3 salários mínimos\n\t[1] De 3 a 5 salários mínimos\n\t[2] Mais que 5 salários mínimos\nOpção: ");
                scanf(" %d", &seletor2);

                for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++){
                    if(seletor2 == dadosEleitor[1][seletor1]){
                        
                        if(candidatoPresidenciaEscolhido[seletor1] == 17){
                            seletor4[0][0]++;
                        }
                        else if(candidatoPresidenciaEscolhido[seletor1] == 26){
                            seletor4[0][1]++;
                        }

                        if(candidatoGovernadorEscolhido[seletor1] == 17){
                            seletor4[1][0]++;
                        }
                        else if(candidatoGovernadorEscolhido[seletor1] == 26){
                            seletor4[1][1]++;
                        }
                        else if(candidatoGovernadorEscolhido[seletor1] == 31){
                            seletor4[1][2]++;
                        }
                    }
                }

                printf("\nEntre os que estão na faixa salarial escolhida, quem ganha na presidência é ");
                if (seletor4[0][0] > seletor4[0][1]){
                    printf("17!");
                }
                else if (seletor4[0][1] > seletor4[0][0]){
                    printf("26!");
                }
                else {
                    printf("ninguém! não houve votos que passaram pelo filtro...");
                }
                
                printf("\nEntre os que estão na faixa salarial escolhida, quem ganha na governador é ");
                if (seletor4[1][0] > seletor4[1][1] && seletor4[1][0] > seletor4[1][2]){
                    printf("17!");
                }
                else if (seletor4[1][1] > seletor4[1][0] && seletor4[1][1] > seletor4[1][2]){
                    printf("26!");
                }
                else if(seletor4[1][2] > seletor4[1][0] && seletor4[1][2] > seletor4[1][1]){
                    printf("31!");
                }
                else {
                    printf("ninguém! não houve votos que passaram pelo filtro...");
                }
                break;

            case 5:
                for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++){
                    if(dadosEleitor[0][seletor1] < 30 && dadosEleitor[2][seletor1] == 2){
                        
                        if(candidatoPresidenciaEscolhido[seletor1] == 17){
                            seletor4[0][0]++;
                        }
                        else if(candidatoPresidenciaEscolhido[seletor1] == 26){
                            seletor4[0][1]++;
                        }

                        if(candidatoGovernadorEscolhido[seletor1] == 17){
                            seletor4[1][0]++;
                        }
                        else if(candidatoGovernadorEscolhido[seletor1] == 26){
                            seletor4[1][1]++;
                        }
                        else if(candidatoGovernadorEscolhido[seletor1] == 31){
                            seletor4[1][2]++;
                        }
                    }
                }

                printf("\nEntre os abaixo de 30 anos e consultados no último mês, quem ganha na presidência é ");
                if (seletor4[0][0] > seletor4[0][1]){
                    printf("17!");
                }
                else if (seletor4[0][1] > seletor4[0][0]){
                    printf("26!");
                }
                else {
                    printf("ninguém! não houve votos que passaram pelo filtro...");
                }
                
                printf("\nEntre os abaixo de 30 anos e consultados no último mês, quem ganha na governador é ");
                if (seletor4[1][0] > seletor4[1][1] && seletor4[1][0] > seletor4[1][2]){
                    printf("17!");
                }
                else if (seletor4[1][1] > seletor4[1][0] && seletor4[1][1] > seletor4[1][2]){
                    printf("26!");
                }
                else if(seletor4[1][2] > seletor4[1][0] && seletor4[1][2] > seletor4[1][1]){
                    printf("31!");
                }
                else {
                    printf("ninguém! não houve votos que passaram pelo filtro...");
                }
                break;

            case 6:
                printf("\nDigite o mês (1 a 3): ");
                scanf(" %d", &seletor2);
                seletor2--;

                for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++){
                    if (dadosEleitor[2][seletor1] == seletor2){                    
                        printf("\n\nEleitor %d:", seletor1);
                        printf("\nCandidato presidencia: %d", candidatoPresidenciaEscolhido[seletor1]);
                        printf("\nCandidato governador: %d", candidatoGovernadorEscolhido[seletor1]);

                        printf("\nIdade do eleitor: %d", dadosEleitor[0][seletor1]);
                        printf("\nFaixa salarial do eleitor: %d", dadosEleitor[1][seletor1]);
                        printf("\nMes da entrevista: %d", dadosEleitor[2][seletor1] + 1);
                    }
                }
                break;
            
            case 7:
                for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++){
                    printf("\n\nEleitor %d:", seletor1);
                    printf("\nCandidato presidencia: %d", candidatoPresidenciaEscolhido[seletor1]);
                    printf("\nCandidato governador: %d", candidatoGovernadorEscolhido[seletor1]);

                    printf("\nIdade do eleitor: %d", dadosEleitor[0][seletor1]);
                    printf("\nFaixa salarial do eleitor: %d", dadosEleitor[1][seletor1]);
                    printf("\nMes da entrevista: %d", dadosEleitor[2][seletor1] + 1);
                }
                break;

            default:
                break;
        }
        
    } while (opUser != 0);
    
    return 0;
}