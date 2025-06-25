# 🧬 Resolução de Labirintos com Algoritmos Genéticos

## ✅ Objetivo

Utilizar um algoritmo genético para simular a resolução de labirintos, por meio de individuos representados por uma combinação aleatória de um conjunto de letras que determinam seu caminho.
Os  indivíduos que chegam mais perto da saída devem ser capazes de reproduzir, formando assim, gerações mais eficientes.

## 🏭 Estrutura do projeto
O projeto é dividido em 3 partes:
- Indivíduo e população
Responsável por manipular os indivíduos e seus respectivos grupos.

- Utilitários (gerador e mapa)
Necessário para reconhecer e utilizar arquivos externos.
  
- Main (função principal)
Função que faz o projeto acontecer, onde, permite várias gerações surgirem para tentarem resolver os desafios.

## 📒 Função fitness
No código, a função fitness é calculada por meio da subtração entre o total (100) e a distÂncia euclidiana mais a penlidade.

## 🏃‍♂️ Instruções para compilar e executar o código
1. Abra o terminal
2. Entre na pasta \src, dentro de \projetoLabirintoReborn
3. Execute os comandos
   
`gcc .\main.c .\Individuo.c .\Populacao.c .\Mapa.c .\Gerador.c -o programa.exe`

`.\programa.exe caminhoMapa caminhoParametros`

*Observação: substitua caminhoMapa e caminhoParametros pelos caminhos NÃO relativos dos arquivos em seu computador*

*Observação 2: O arquivo do mapa deve obrigatoriamente estar cercado de cerquilhas, e o mapa deve ter pelo menos 1 entrada e 1 saída*

*Observação 3: O arquivo de parametros deverá ter uma separação marcada por "=" entre o valor e a chave, e obedecer a seguinte ordem

mapa_altura, mapa_largura, penalidade_fitness, porcentagem_mutacao, quantidade_maxima_movimentos, populacao_maxima, porcentagem_melhores*

