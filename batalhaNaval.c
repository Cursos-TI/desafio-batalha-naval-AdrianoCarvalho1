#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Preenche todo o tabuleiro com o valor da constante AGUA
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posicionamento dos Quatro Navios
    // Navio 1 Horizontal
    int linhaNavio1 = 1;
    int colunaNavio1 = 1;
    if (colunaNavio1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavio1][colunaNavio1 + i] = NAVIO;
        }
    }

    // Navio 2 Vertical
    int linhaNavio2 = 3;
    int colunaNavio2 = 8;
    if (linhaNavio2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavio2 + i][colunaNavio2] = NAVIO;
        }
    }

    // Navio 3 Diagonal de cima-esquerda para baixo-direita
    int linhaNavio3 = 3;
    int colunaNavio3 = 1;
    // Valida se o navio cabe tanto na vertical quanto na horizontal
    if (linhaNavio3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaNavio3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Incrementa a linha E a coluna a cada passo
            tabuleiro[linhaNavio3 + i][colunaNavio3 + i] = NAVIO;
        }
    }

    // Navio 4 Diagonal de cima-direita para baixo-esquerda
    int linhaNavio4 = 6;
    int colunaNavio4 = 4;
    // Valida se o navio cabe na vertical
    if (linhaNavio4 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaNavio4 - TAMANHO_NAVIO >= -1) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Incrementa a linha e decrementa a coluna a cada passo.
            tabuleiro[linhaNavio4 + i][colunaNavio4 - i] = NAVIO;
        }
    }

    // Exibição do Tabuleiro
    printf("TABULEIRO DE BATALHA NAVAL\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        
        printf("\n");
    }

    return 0;
}