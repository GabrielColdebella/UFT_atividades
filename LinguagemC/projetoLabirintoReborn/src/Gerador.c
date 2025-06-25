#include "Gerador.h"
#include <stdio.h>
#include <string.h>

// função que transforma um arquivo de texto em constantes em parametros.h
int resgata_parametros_de_arquivo(char const *caminho)
{
    FILE *fptrEntrada = fopen(caminho, "r");
    FILE *arquivoSaida = fopen("Parametros.h", "w");

    if (!fptrEntrada || !arquivoSaida)
    {
        printf("Erro ao abrir os arquivos\n");
        return 2;
    }

    char linha[128], chave[64];
    int valor, bufferValor[7];

    
    while (fgets(linha, sizeof(linha), fptrEntrada))
    {
        if (sscanf(linha, "%[^=]=%d", chave, &valor) == 2)
        {
            for (char *p = chave; *p; p++)
            {
                if (*p == ' ')
                    *p = '\0';
            }

            if (strstr(linha, "mapa_altura"))
                bufferValor[0] = valor;
            else if (strstr(linha, "mapa_largura"))
                bufferValor[1] = valor;
            else if (strstr(linha, "penalidade_fitness"))
                bufferValor[2] = valor;
            else if (strstr(linha, "porcentagem_mutacao"))
                bufferValor[3] = valor;
            else if (strstr(linha, "quantidade_maxima_movimentos"))
                bufferValor[4] = valor;
            else if (strstr(linha, "populacao_maxima"))
                bufferValor[5] = valor;
            else if (strstr(linha, "porcentagem_melhores"))
                bufferValor[6] = valor;
        }
    }

    fprintf(arquivoSaida, "#ifndef PARAMETROS_H\n");
    fprintf(arquivoSaida, "#define PARAMETROS_H\n\n");
    fprintf(arquivoSaida, "#define MAPHEI %d\n", bufferValor[0]);
    fprintf(arquivoSaida, "#define MAPWID %d\n", bufferValor[1]);
    fprintf(arquivoSaida, "#define PENALIDADE %d\n", bufferValor[2]);
    fprintf(arquivoSaida, "#define porcentagemMutacao %d\n", bufferValor[3]);
    fprintf(arquivoSaida, "#define qtdMovimentosMax %d\n", bufferValor[4]);
    fprintf(arquivoSaida, "#define maxPopulacao %d\n", bufferValor[5]);
    fprintf(arquivoSaida, "#define porcentagemMelhores %d\n", bufferValor[6]);
    fprintf(arquivoSaida, "#endif\n");

    fclose(fptrEntrada);
    fclose(arquivoSaida);
    return 0;
}