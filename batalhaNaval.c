#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    int tabuleiro[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int linhaNavioVertical = 2;
    int colunaNavioVertical = 3;

    if (linhaNavioVertical + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
        }
    }

    int linhaNavioHorizontal = 5;
    int colunaNavioHorizontal = 5;

    if (colunaNavioHorizontal + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
        }
    }

    printf("TABULEIRO DE BATALHA NAVAL\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        
        printf("\n");
    }

    return 0;
}