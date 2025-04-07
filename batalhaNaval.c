#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAM 10

void exibirTabuleiro(int linhas, int colunas, int tabuleiro[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j] ? 1 : 0);
        }
        printf("\n");
    }
    printf("\n");
}

void habilidadeCruz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void habilidadeCone(int matriz[5][5]) {
    int centro = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i >= centro && j >= centro - i && j <= centro + i) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void habilidadeOctaedro(int matriz[5][5]) {
    int centro = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - centro) + abs(j - centro) <= 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posiciona dois navios: um horizontal (4 células), outro vertical (3 células)
    for (int i = 0; i < 4; i++) {
        tabuleiro[2][i + 2] = 3;  // navio horizontal na linha 2
    }
    for (int i = 0; i < 3; i++) {
        tabuleiro[i + 5][6] = 3;  // navio vertical na coluna 6
    }

    // Posiciona dois navios diagonais (4 células cada)
    for (int i = 0; i < 4; i++) {
        tabuleiro[i][i] = 3;  // diagonal principal
    }
    for (int i = 0; i < 4; i++) {
        tabuleiro[i][TAM - 1 - i] = 3;  // diagonal secundária
    }

    printf("Tabuleiro com navios (3 = navio, 0 = vazio):\n");
    exibirTabuleiro(TAM, TAM, tabuleiro);

    // Matrizes de habilidades
    int cruz[5][5], cone[5][5], octaedro[5][5];

    habilidadeCruz(cruz);
    habilidadeCone(cone);
    habilidadeOctaedro(octaedro);

    printf("Habilidade - Cruz:\n");
    exibirTabuleiro(5, 5, cruz);

    printf("Habilidade - Cone:\n");
    exibirTabuleiro(5, 5, cone);

    printf("Habilidade - Octaedro:\n");
    exibirTabuleiro(5, 5, octaedro);

    return 0;
}