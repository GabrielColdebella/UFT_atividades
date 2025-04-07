#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define qtdEntrevistas 4

void armazenarDadosEntrevista
    (
    int ini_cPresEscolhido[qtdEntrevistas], 
    int ini_cGovEscolhido[qtdEntrevistas], 
    int ini_eDados[3][qtdEntrevistas]
    ){

    bool condicaoEleger;
    int seletor1, eleitorAtual = 0, mes = 0;
    int sPresidente, sGovernador, eIdade, eFaixaSalarial;

    printf("\nPara pular o mês, digite 0 na idade.");
    //Caso atingir o 4 mês, código encerrará
    do
    {

        printf("\nMês: %d", mes + 1);
        do
        {
            condicaoEleger = true;
            printf("\n\nEleitor %d", eleitorAtual + 1);
            printf("\nOpções para presidência:\n\t[26] Candidato X\n\t[17] Candidato Y\n\t[1] Ainda não escolhi\n\t[0] Branco\nOpção: ");
            scanf(" %d", &sPresidente);

            printf("\nOpções para governador:\n\t[31] Candidato X\n\t[26] Candidato Y\n\t[17] Candidato Z\n\t[1] Ainda não escolhi\n\t[0] Branco\nOpção: ");
            scanf(" %d", &sGovernador);

            printf("\nQual é a sua idade?\n");
            scanf(" %d", &eIdade);

            printf("\nQual sua faixa salarial?\n\t[0] Menos que 3 salários mínimos\n\t[1] De 3 a 5 salários mínimos\n\t[2] Mais que 5 salários mínimos\nOpção:");
            scanf(" %d", &eFaixaSalarial);

            if(eIdade == 0){
                condicaoEleger = true;
            }
            else if (eIdade != 0 && eIdade < 18){
                printf("Idade inválida");
                condicaoEleger = false;
            }
            else if (sPresidente != 17 && sPresidente != 26 && sPresidente != 0 && sPresidente != 1){
                printf("Candidato inválido");
                condicaoEleger = false;
            }
            else if (sGovernador != 17 && sGovernador != 26 && sGovernador != 31 && sGovernador != 0 && sGovernador != 1){
                printf("Candidato inválido");
                condicaoEleger = false;
            }
            else if(eFaixaSalarial < 0 || eFaixaSalarial > 2){
                condicaoEleger = false;
                printf("Faixa Salarial inválida");

            }
            
            if (condicaoEleger == false){
                printf("\nTente novamente.");
            }            
        } while (condicaoEleger == false);
        
        if(eIdade == 0){
            mes = mes + 1;
        }
        else if (condicaoEleger){
            ini_cPresEscolhido[eleitorAtual] = sPresidente;
            ini_cGovEscolhido[eleitorAtual] = sGovernador;
            ini_eDados[0][eleitorAtual] = eIdade;
            ini_eDados[1][eleitorAtual] = eFaixaSalarial;
            ini_eDados[2][eleitorAtual] = mes;
            eleitorAtual = eleitorAtual + 1;
        }
        
    } while (eleitorAtual < qtdEntrevistas && mes < 3);
}

int main(){
    int mes, eleitorAtual, seletor1, qtdRegistros;
    struct structEntrevistas{
        int candidatoPresidenciaEscolhido[qtdEntrevistas];
        int candidatoGovernadorEscolhido[qtdEntrevistas];
        int dadosEleitor[3][qtdEntrevistas];
        //idade, faixa e mês
    };
    
    struct structEntrevistas seletorEstrutura;

    armazenarDadosEntrevista(
        seletorEstrutura.candidatoPresidenciaEscolhido,
        seletorEstrutura.candidatoGovernadorEscolhido,
        seletorEstrutura.dadosEleitor
    );

    for (seletor1 = 0; seletor1 < qtdEntrevistas; seletor1++){
        printf("\n\nEleitor %d:", seletor1);
        printf("\nCandidato presidencia: %d", seletorEstrutura.candidatoPresidenciaEscolhido[seletor1]);
        printf("\nCandidato governador: %d", seletorEstrutura.candidatoGovernadorEscolhido[seletor1]);

        printf("\nIdade do eleitor: %d", seletorEstrutura.dadosEleitor[0][seletor1]);
        printf("\nFaixa salarial do eleitor: %d", seletorEstrutura.dadosEleitor[1][seletor1]);
        printf("\nMes da entrevista: %d", seletorEstrutura.dadosEleitor[2][seletor1] + 1);
        
        if (seletorEstrutura.dadosEleitor[0][seletor1 + 1]  == 0){
            break;
        }
        
    }
    
    
    FILE *fptr;
    fptr = fopen("prova_arquivo3.bin", "wb");

    if (fptr == NULL) {
        printf("Erro!!!!!");
        exit(1);
    }

    qtdRegistros = seletor1;
    int separador = 999;
    fwrite(&qtdRegistros, sizeof(int), 1, fptr);

    fwrite(seletorEstrutura.candidatoPresidenciaEscolhido, sizeof(int), qtdRegistros, fptr);
    fwrite(&separador, sizeof(int), 1, fptr);
    fwrite(seletorEstrutura.candidatoGovernadorEscolhido, sizeof(int), qtdRegistros, fptr);
    fwrite(&separador, sizeof(int), 1, fptr);
    fwrite(seletorEstrutura.dadosEleitor[0], sizeof(int), qtdRegistros, fptr);
    fwrite(&separador, sizeof(int), 1, fptr);
    fwrite(seletorEstrutura.dadosEleitor[1], sizeof(int), qtdRegistros, fptr);
    fwrite(&separador, sizeof(int), 1, fptr);
    fwrite(seletorEstrutura.dadosEleitor[2], sizeof(int), qtdRegistros, fptr);

    
    fclose(fptr);
    return 0;
}