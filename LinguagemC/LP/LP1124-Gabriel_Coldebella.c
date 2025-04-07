#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define maxPacotes 60
#define maxCidades 3


int verificarMaisLotes(float numero){
    numero = numero / 3;

    // já que o número apresentado é float
    // se ele for for igual a versão dele mesmo em int
    // quer dizer que ele não tem números após a virgula
    if (numero != (int) numero){
        numero = numero + 1;
    }
    return numero;
    
}

float registraPacote(int registraPacote_pacotes_codigo[maxCidades][maxPacotes], float registraPacote_pacotes_peso[maxCidades][maxPacotes], int registraPacote_pacotes_escritorio[maxCidades]){
    int pacoteCOD, pacoteDEST;
    float pacotePESO;

    do {
        printf("\nInsira o código, destino e peso do pacote:\n");
        printf("Insira o código: ");
        scanf(" %d", &pacoteCOD);

        printf("Destinos:\n\t[1] Palmas\n\t[2] Gurupi\n\t[3] Goiânia\nDestino: ");
        scanf(" %d", &pacoteDEST);
        //diminui em 1 para deixar usavel, visto que, arrays começam em 0
        pacoteDEST = pacoteDEST - 1;

        printf("Insira o peso: ");
        scanf(" %f", &pacotePESO);

        if(pacoteDEST != -1 && pacotePESO != 0){
        // faz uma verificação para ver se o usuário escreveu/escolheu certo
            if (pacoteDEST > 2 || pacoteDEST < 0){
                printf("Destino inválido. Tente novamente...");
            }

            if (registraPacote_pacotes_escritorio[pacoteDEST] >= maxPacotes){
                printf("Escritório chegou a máximo lugares disponíveis!\tPor favor, tente outro...");
            }
        }
    } while ((registraPacote_pacotes_escritorio[pacoteDEST] >= maxPacotes || (pacoteDEST > 2 || pacoteDEST < -1)) && (pacoteDEST != -1 && pacotePESO != 0));

    if(pacotePESO > 0){
        //vai no escritorio e no próximo lugar registra o código do produto
        registraPacote_pacotes_codigo[pacoteDEST][registraPacote_pacotes_escritorio[pacoteDEST]] = pacoteCOD;

        //armazena o peso do pacote em pesosPacote
        registraPacote_pacotes_peso[pacoteDEST][registraPacote_pacotes_escritorio[pacoteDEST]] = pacotePESO;

        //ajuda a calcular o tanto de pacotes por escritorio ao inves de fazer loop para calcular
        registraPacote_pacotes_escritorio[pacoteDEST] = registraPacote_pacotes_escritorio[pacoteDEST] + 1;
    }

    return pacotePESO;
}


// nome da função vem antes da variavel para indicar que este será usado apenas ali dentro
char *inicializador(int inicializador_pacotes_codigo[maxCidades][maxPacotes], float inicializador_pacotes_peso[maxCidades][maxPacotes], int inicializador_pacotes_escritorio[maxCidades]) {
    float pacote_peso;

    //15 vezes o tamanho de char para a senha
    char* senhaAdm = malloc(15 * sizeof(char));

    printf("\nPor favor digite a senha: ");
    scanf(" %13s", senhaAdm);

    printf("\nQuando quiser encerrar, digite 0 em todos os campos.\n");

    //registro de encomendas da central
    do {
        // chama a função de registro de pacotes para fazer o serviço
        pacote_peso = registraPacote(inicializador_pacotes_codigo, inicializador_pacotes_peso, inicializador_pacotes_escritorio);
    } while (pacote_peso > 0 && (inicializador_pacotes_escritorio[0] + inicializador_pacotes_escritorio[1] + inicializador_pacotes_escritorio[2] < 180));
    
    printf("\nRegistro da central encerrado!");

    return senhaAdm;
}

int main() {
    // Armazena os códigos de pacote
    int pacotes_codigo[maxCidades][maxPacotes] = {0};

    // Armazena os pesos dos pacotes
    float pacotes_peso[maxCidades][maxPacotes] = {0};

    //armazena a quantidade de pacotes por escritório
    int pacotes_escritorio[maxCidades] = {0};
    
    // cidades para mostrar durante o relátorio
    char cidades[maxCidades][15] = {"Palmas", "Gurupi", "Goiânia"};

    int opcoesADM;

    int percorreArray1, percorreArray2;
    int seletor1, seletor2;
    float seletor3;

    char *senhaADM = inicializador(pacotes_codigo, pacotes_peso, pacotes_escritorio), *senhaUSUARIO = malloc(15 * sizeof(char));

    int pacoteCOD, pacoteDEST;
    float pacotePESO;

    
    do{
        printf("\n\nMenu\n\t[0] Sair\n\t[1] Registre 1 pacote \n\t[2] Consulta pacote por código\n\t[3] Quantidade de pacotes geral \n\t[4] Verificar entrega por escritório \n\t[5] Autoriza a entrega\n\t[6] Mostrar todos os pacotes\nOpção: ");
        scanf(" %d", &opcoesADM);

        switch (opcoesADM){
            case 1:
                registraPacote(pacotes_codigo, pacotes_peso, pacotes_escritorio);
                break;

            case 2:
                printf("\nDigite o código: ");
                scanf(" %d", &seletor1);

                for (percorreArray1 = 0; percorreArray1 < maxCidades; percorreArray1++){

                    for (percorreArray2 = 0; percorreArray2 < maxPacotes; percorreArray2++){
                        //encerra assim que vê um peso igual a 0
                        if (pacotes_peso[percorreArray1][percorreArray2] == 0){
                            break;
                        }
                        
                        if (pacotes_codigo[percorreArray1][percorreArray2] == seletor1){
                            printf("\n\nCódigo:\t\t%d\nPeso:\t\t%f\nDestino:\t%s", pacotes_codigo[percorreArray1][percorreArray2], pacotes_peso[percorreArray1][percorreArray2], cidades[percorreArray1]);
                            break;
                        }
                    }
                    if (pacotes_codigo[percorreArray1][percorreArray2] == seletor1){
                        break;
                    }
                }
                if (pacotes_codigo[percorreArray1][percorreArray2] != seletor1){
                    printf("\nPacote não encontrado.");
                }
                break;

            case 3:
                seletor1 = 0;
                for (percorreArray1 = 0; percorreArray1 < maxCidades; percorreArray1++){
                    seletor1 = seletor1 + pacotes_escritorio[percorreArray1];
                }
                
                printf("\nNúmero total de pacotes que estão na central: %d", seletor1);

                for (percorreArray1 = 0; percorreArray1 < maxCidades; percorreArray1++){
                    //%% para colocar apenas 1 % no print
                    printf("\n%s:\t%.2f%%", cidades[percorreArray1], (float) ((pacotes_escritorio[percorreArray1] * 100) / seletor1));
                }

                break;

            case 4:
                pacotePESO = 0;
                seletor1 = 0;
                printf("\nDestinos:\n\t[1] Palmas\n\t[2] Gurupi\n\t[3] Goiânia\nDestino: ");
                scanf(" %d", &pacoteDEST);
                pacoteDEST = pacoteDEST - 1;
                printf("\nLista de pacotes com destino a %s: %d", cidades[pacoteDEST], pacotes_escritorio[pacoteDEST]);
                printf("\nTotal de lotes necessários: %d", verificarMaisLotes(pacotes_escritorio[pacoteDEST]));

                printf("\n\n");
                printf("\nCódigo\t\t|  Peso: ");
                for (percorreArray1 = 0; percorreArray1 < maxPacotes; percorreArray1++){


                    printf("\n%d\t\t|%f", pacotes_codigo[pacoteDEST][percorreArray1], pacotes_peso[pacoteDEST][percorreArray1]);
                    pacotePESO = pacotePESO + pacotes_peso[pacoteDEST][percorreArray1];
                    
                    if (pacotes_peso[pacoteDEST][percorreArray1] > 50){
                        seletor1 = 1;
                    }
                    if (pacotes_peso[pacoteDEST][percorreArray1 + 1] == 0){
                        break;
                    }
                }

                printf("\nPeso total: %f", pacotePESO);

                if (seletor1 > 0){
                    printf("\nNecessidade de reforço!!");
                }
                break;

            case 5:
                seletor1 = 0;
                printf("\nDigite a senha para prosseguir: ");
                scanf(" %13s", senhaUSUARIO);
                if (strcmp(senhaADM,senhaUSUARIO) == 0){

                    printf("\nDestinos:\n\t[1] Palmas\n\t[2] Gurupi\n\t[3] Goiânia\nDestino: ");
                    scanf(" %d", &pacoteDEST);
                    pacoteDEST = pacoteDEST - 1;

                    if (pacotes_escritorio[pacoteDEST] != 0){
                        printf("\n\n\t[0] CANCELAR\n\t[1] AUTORIZAR\nOpção: ");
                        scanf(" %d", &seletor1);

                        if (seletor1 == 1){
                            memset(pacotes_codigo[pacoteDEST], 0, sizeof(pacotes_codigo[pacoteDEST]));
                            memset(pacotes_peso[pacoteDEST], 0, sizeof(pacotes_peso[pacoteDEST]));
                            pacotes_escritorio[pacoteDEST] = 0;
                            break;
                        } else {
                            break;
                        }

                    } else {
                        printf("\nNão há pacotes neste escritório!");
                    }

                    
                } else {
                    printf("\nSenha incorreta!");
                    break;
                }
                
                break;

            case 6:
                for (percorreArray1 = 0; percorreArray1 < maxCidades; percorreArray1++){
                    printf("\n\n");
                    printf("\nTotal de pacotes no escritorio de %s: %d", cidades[percorreArray1], pacotes_escritorio[percorreArray1]);
                    printf("\nCódigo\t\t|  Peso: ");
                    for (percorreArray2 = 0; percorreArray2 < maxPacotes; percorreArray2++){
                        // quando o valor atual ou o próximo do peso é igual a 0, ele pula 
                        if (pacotes_peso[percorreArray1][percorreArray2] == 0){
                            break;
                        }
                        printf("\n%d\t\t|%f", pacotes_codigo[percorreArray1][percorreArray2], pacotes_peso[percorreArray1][percorreArray2]);
                    }
                }
                break;
            default:
                break;
            }
    } while (opcoesADM != 0);

    return 0;
}