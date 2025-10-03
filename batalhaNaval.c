#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

#define TAMANHO_HABILIDADE 5
#define AREA_AFETADA 5

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Preenche todo o tabuleiro com o valor da constante AGUA
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

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
    if (linhaNavio3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaNavio3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavio3 + i][colunaNavio3 + i] = NAVIO;
        }
    }

    // Navio 4 Diagonal de cima-direita para baixo-esquerda
    int linhaNavio4 = 6;
    int colunaNavio4 = 4;
    if (linhaNavio4 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaNavio4 - TAMANHO_NAVIO >= -1) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavio4 + i][colunaNavio4 - i] = NAVIO;
        }
    }

    // Criar matriz de habilidade cone
    int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int centro = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // A condição desenha um triângulo/cone 
            if (i <= centro && (j >= centro - i && j <= centro + i)) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }

    int origemLinha = 5;
    int origemColuna = 4;

    // Lógica para sobrepor a matriz de habilidade no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaNoTabuleiro = origemLinha + (i - centro);
                int colunaNoTabuleiro = origemColuna + (j - centro);

                //  garante que a área de efeito permaneça dentro dos limites
                if (linhaNoTabuleiro >= 0 && linhaNoTabuleiro < TAMANHO_TABULEIRO &&
                    colunaNoTabuleiro >= 0 && colunaNoTabuleiro < TAMANHO_TABULEIRO) {
                    
                    // Marca a área afetada no tabuleiro principal
                    tabuleiro[linhaNoTabuleiro][colunaNoTabuleiro] = AREA_AFETADA;
                }
            }
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