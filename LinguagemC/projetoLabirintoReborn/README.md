# 🧬 Resolução de Labirintos com Algoritmos Genéticos

## ✅ Objetivo

Utilizar um algoritmo genético para simular a resolução de labirintos, por meio de indivíduos representados por uma combinação aleatória de letras que determinam seu caminho.
Os indivíduos que chegam mais próximos da saída devem ser capazes de se reproduzir, formando assim gerações progressivamente mais eficientes.

---

## 🏭 Estrutura do Projeto

O projeto é dividido em 3 partes principais:

### **Indivíduo e População**
  Responsáveis por manipular os indivíduos e seus respectivos grupos.

### **Utilitários (Gerador e Mapa)**
  Módulos auxiliares para leitura e manipulação de arquivos externos.

### **Main (Função Principal)**
  Ponto de entrada do programa, onde ocorrem as execuções de múltiplas gerações na tentativa de resolver o desafio do labirinto.

---

## 🧠 Genótipo dos Indivíduos

Cada indivíduo é representado por uma sequência de caracteres, onde cada caractere indica uma direção:

* `'C'` – Cima
* `'B'` – Baixo
* `'E'` – Esquerda
* `'D'` – Direita

Essa sequência de movimentos define o "DNA" do indivíduo. Durante a reprodução, mutações podem ocorrer, modificando letras e criando diversidade genética entre as gerações.

---

## 📋 Listas Utilizadas

### **Lista de dinâmica População**:
  Implementada por meio de uma lista encadeada, onde cada nó representa um indivíduo. Essa estrutura facilita a inserção, remoção e avaliação de indivíduos a cada geração.

### **Lista de estática Movimentos**:
  Usada para armazenar a sequência de movimentos executados por cada indivíduo, sendo útil na avaliação da função fitness e reprodução dos melhores.

---

## 📒 Função Fitness

A função fitness é responsável por avaliar a qualidade de cada indivíduo.
Ela é calculada com a fórmula:

```
fitness = 100 - (distância euclidiana até a saída + penalidade * 10)
```

Indivíduos que batem nas paredes ou saem dos limites do labirinto recebem penalidades, impactando negativamente sua pontuação.
Quanto menor a distância até a saída e menor a penalidade, maior o fitness.

---

## 🏃‍♂️ Instruções para Compilar e Executar o Código

1. Abra o terminal.
2. Navegue até a pasta **src**, dentro de **projetoLabirintoReborn**s.
3. Execute os seguintes comandos:

```bash
gcc .\main.c .\Individuo.c .\Populacao.c .\Mapa.c .\Gerador.c -o programa.exe
.\programa.exe caminhoMapa caminhoParametros
```

### ⚠️ Observações Importantes:

* Substitua `caminhoMapa` e `caminhoParametros` pelos caminhos **absolutos** dos arquivos em seu computador.
* O **arquivo do mapa** deve estar obrigatoriamente cercado por cerquilhas (`#`) e conter pelo menos **uma entrada e uma saída**.
* O **arquivo de parâmetros** deve seguir o seguinte formato, com cada linha separando chave e valor por `"="` e obedecendo a ordem:

```txt
mapa_altura=...
mapa_largura=...
penalidade_fitness=...
porcentagem_mutacao=...
quantidade_maxima_movimentos=...
populacao_maxima=...
porcentagem_melhores=...
```

## 📋 Gráficos:

link do sheets:

https://docs.google.com/spreadsheets/d/1Jj3J9SHiJPX5agk3cHxSpLXCjWNwFx-tyz6KuSjDios/edit?usp=sharing

Caso 1:
Indivíduos normais em mapa 1

https://docs.google.com/spreadsheets/d/e/2PACX-1vS4D4LS-ZXevqVMjpzKuRG5lHXV-2EF6lGl5hYW5Du1z4yknVZ1iaYWh-aUTJoQNo13-iPe4DnO7jnk/pubchart?oid=618130886&format=interactive

![Histograma de fitness](https://github.com/user-attachments/assets/53da7ec2-a9e0-4ca3-81fd-785e28cc2f20)

Caso 2: 
Indivíduos normais em mapa 2

https://docs.google.com/spreadsheets/d/e/2PACX-1vS4D4LS-ZXevqVMjpzKuRG5lHXV-2EF6lGl5hYW5Du1z4yknVZ1iaYWh-aUTJoQNo13-iPe4DnO7jnk/pubchart?oid=1383601889&format=interactive

![fitness](https://github.com/user-attachments/assets/9448fdfe-e155-491c-9831-b49a32402e99)


Caso 3:
Indivíduos mais inteligentes em mapa 3

https://docs.google.com/spreadsheets/d/e/2PACX-1vS4D4LS-ZXevqVMjpzKuRG5lHXV-2EF6lGl5hYW5Du1z4yknVZ1iaYWh-aUTJoQNo13-iPe4DnO7jnk/pubchart?oid=181846318&format=interactive

![fitness](https://github.com/user-attachments/assets/069cf121-2a1f-461f-8f81-6db3c8eff558)


Caso 4: 
Indivíduos mais inteligentes em mapa 4

https://docs.google.com/spreadsheets/d/e/2PACX-1vS4D4LS-ZXevqVMjpzKuRG5lHXV-2EF6lGl5hYW5Du1z4yknVZ1iaYWh-aUTJoQNo13-iPe4DnO7jnk/pubchart?oid=131968439&format=interactive
![fitness (2)](https://github.com/user-attachments/assets/21b0e18d-09fb-4e99-b6d3-61ab53c34392)
