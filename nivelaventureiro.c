#include <stdio.h>

#define TAM 10
#define NAVIO 3

// ===== FUNÇÃO PARA VALIDAR POSIÇÃO =====
int podePosicionar(int tab[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha + i * dLinha;
        int c = coluna + i * dColuna;

        // Verifica limites
        if (l < 0 || l >= TAM || c < 0 || c >= TAM) {
            return 0;
        }

        // Verifica sobreposição
        if (tab[l][c] != 0) {
            return 0;
        }
    }
    return 1;
}

// ===== FUNÇÃO PARA POSICIONAR NAVIO =====
void posicionarNavio(int tab[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha + i * dLinha;
        int c = coluna + i * dColuna;
        tab[l][c] = 3;
    }
}

int main() {

    // ===== 1. CRIAÇÃO DO TABULEIRO =====
    int tabuleiro[TAM][TAM];

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ===== 2. DEFINIÇÃO DOS NAVIOS =====
    // (linha, coluna, direçãoLinha, direçãoColuna)

    int navios[4][4] = {
        {1, 1, 0, 1},   // horizontal →
        {5, 2, 1, 0},   // vertical ↓
        {0, 7, 1, -1},  // diagonal ↙
        {6, 6, 1, 1}    // diagonal ↘
    };

    // ===== 3. POSICIONAMENTO DOS NAVIOS =====
    for (int n = 0; n < 4; n++) {

        int linha = navios[n][0];
        int coluna = navios[n][1];
        int dLinha = navios[n][2];
        int dColuna = navios[n][3];

        if (podePosicionar(tabuleiro, linha, coluna, dLinha, dColuna)) {
            posicionarNavio(tabuleiro, linha, coluna, dLinha, dColuna);
        } else {
            printf("Erro ao posicionar navio %d\n", n + 1);
        }
    }

    // ===== 4. EXIBIÇÃO DO TABULEIRO =====
    printf("\nTABULEIRO FINAL:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}