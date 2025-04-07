#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#define maxContatos 10

struct Contato
{
    char Nome[128];
    char Telefone[15];
};

// Função que cadastra o contato usando o nome e telefone inseridos pelo usuário.
void CadastrarContato(char cadastroNome[128], char cadastroTelefone[15]){

    printf("\nCadastro -----");

    // este while limpa o buffer antes do fgets (mesma coisa do espaço em scanf(" %d"))
    while (getchar() != '\n');  

    //pega o input e remove o caractere de nova linha
    printf("\nInsira o nome:\n\t>> ");
    fgets(cadastroNome, 128, stdin);
    cadastroNome[strcspn(cadastroNome, "\n")] = '\0'; 

    printf("\nNúmero de telefone:\n\t>> ");
    fgets(cadastroTelefone, 15, stdin);
    cadastroTelefone[strcspn(cadastroTelefone, "\n")] = '\0'; 

    printf("\nContato cadastrado com sucesso!");
}


// Função que salva apenas 1 contato por vez no arquivo
void SalvarEmArquivo(FILE *salvarFptr, char salvarNome[128], char salvarTelefone[15]){
    salvarFptr = fopen("arquivoContatos.txt", "a");
    fprintf(salvarFptr, "%s;%s;\n", salvarNome, salvarTelefone);
    fclose(salvarFptr);
}

int main(){
    FILE *fptr;

    struct Contato listaContatos[maxContatos];
    
    bool arquivoSalvo = true;
    int contador, opcaoUsuario = 2, opcaoTemp;
    char buffer[255];
    
    //FOR que coloca todos os primeiros espaços como '\0' para finalizar a string logo no começo
    // ---> perguntar ao professor maneira melhor de fazer isso, já que "= {0}" não funciona
    for (contador = 0; contador < maxContatos; contador++)
    {
        listaContatos[contador].Nome[0] = '\0';
        listaContatos[contador].Telefone[0] = '\0';
    }
    
    if ((fptr = fopen("arquivoContatos.txt","r")) == NULL)
    {
        fptr = fopen("arquivoContatos.txt", "w");
        fclose(fptr);
    } else 
    {
        contador = 0;

        // enquanto navega pelo arquivo, separa tudo por ';'. Copia o primeiro da linha para o nome
        // depois coloca o ponteiro pra continuar após o ';' e copiar o segundo trecho para o telefone
        while (fgets(buffer, 255, fptr) != NULL && contador < maxContatos) 
        {
            char *ptrTemp = strtok(buffer, ";");

            strcpy(listaContatos[contador].Nome, ptrTemp);

            ptrTemp = strtok(NULL, ";");

            strcpy(listaContatos[contador].Telefone, ptrTemp);
            contador++;
        }

        fclose(fptr);
    }

    while (opcaoUsuario != 0)
    {
        printf("\n\nMENU -----\n\t0. Sair\n\t1. Novo cadastro de contato\n\t2. Imprimir agenda na tela\n\t3. Deletar um contato\n\t4. Salvar em arquivo\n\t5. Buscar contato\n>> ");
        scanf(" %d", &opcaoUsuario);

        opcaoTemp = 0;
        contador = 0;
        switch (opcaoUsuario)
        {
            case 1:
                // novo cadastro
                //for que coloca o cadastro como ultimo da lista
                for (contador = 0; contador < maxContatos && listaContatos[contador].Nome[0] != '\0'; contador++);
                
                CadastrarContato(listaContatos[contador].Nome, listaContatos[contador].Telefone);
                arquivoSalvo = false;
                break;

            case 2:
                //exibe os contatos da lista
                printf("\nLista de contatos -----");
                for (contador = 0; contador < maxContatos && listaContatos[contador].Nome[0] != '\0'; contador++)
                {
                    printf("\n\n%d -", contador + 1);
                    printf("\n%s", listaContatos[contador].Nome);
                    printf("\n%s", listaContatos[contador].Telefone);
                }
                break;

            case 3:
                printf("\nQual contato deseja deletar?\ninsira 0 para cancelar\n(colocar o ID do contato. use a função de buscar caso necessário)\n\t>> ");
                scanf(" %d", &opcaoTemp);
                opcaoTemp = opcaoTemp - 1;
                
                if (listaContatos[opcaoTemp].Nome[0] != '\0' && opcaoTemp >= 0) {
                    printf("\n%s removido da lista de contatos", listaContatos[opcaoTemp].Nome);

                    // O código substitui todos da lista pelo proximo valor, fazendo com que não haja espaços entre contatos
                    // evitando um contato vazio entre 2 contatos preenchidos
                    for (contador = opcaoTemp; contador < maxContatos; contador++)
                    {
                        strcpy(listaContatos[contador].Nome, listaContatos[contador + 1].Nome);
                        strcpy(listaContatos[contador].Telefone, listaContatos[contador + 1].Telefone);
                    }
                    
                    arquivoSalvo = false;

                } else {
                    printf("Cancelado.");
                }
                break;

            case 4:
                //salva toda a lista em arquivo CSV
                fptr = fopen("arquivoContatos.txt", "w"); 
                for (contador = 0; contador < maxContatos && listaContatos[contador].Nome[0] != '\0'; contador++){
                    fprintf(fptr, "%s;%s;\n", listaContatos[contador].Nome, listaContatos[contador].Telefone);
                }
                fclose(fptr);
                printf("Salvo!");
                break;        
                
            case 5:
                //procura o contato na lista com base no nome ou telefone

                printf("\nDigite o nome ou número de telefone:\n\t>>");
                scanf(" %s", buffer);

                for (contador = 0; contador < maxContatos && listaContatos[contador].Nome[0] != '\0'; contador++){
                    if (strstr(listaContatos[contador].Nome, buffer) != NULL || strstr(listaContatos[contador].Telefone, buffer) != NULL)
                    {
                        printf("\n%d - \n%s\n%s", contador + 1, listaContatos[contador].Nome, listaContatos[contador].Telefone);
                    }
                    
                }
                
            default:
                break;
        }
    };
    
    //salvamento automatico 
    if (arquivoSalvo == false)
    {
        fptr = fopen("arquivoContatos.txt", "w"); 
        for (contador = 0; contador < maxContatos && listaContatos[contador].Nome[0] != '\0'; contador++){
            fprintf(fptr, "%s;%s;\n", listaContatos[contador].Nome, listaContatos[contador].Telefone);
        }
        fclose(fptr);
        printf("Salvo automaticamente!");
    }



    return 1;
}