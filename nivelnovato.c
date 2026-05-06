#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {

    // ===== 1. DECLARAÇÃO E INICIALIZAÇÃO DO TABULEIRO =====
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 = água
        }
    }

    // ===== 2. DECLARAÇÃO DOS NAVIOS (vetores) =====
    int navio_horizontal[TAM_NAVIO] = {3, 3, 3};
    int navio_vertical[TAM_NAVIO]   = {3, 3, 3};

    // ===== 3. COORDENADAS INICIAIS (definidas no código) =====
    int linhaH = 2, colunaH = 4; // navio horizontal
    int linhaV = 5, colunaV = 1; // navio vertical

    // ===== 4. VALIDAÇÃO E POSICIONAMENTO DO NAVIO HORIZONTAL =====
    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO) {

        int podePosicionar = 1;

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                podePosicionar = 0;
            }
        }

        // Posiciona
        if (podePosicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navio_horizontal[i];
            }
        } else {
            printf("Erro: Navio horizontal sobrepõe outro navio.\n");
        }

    } else {
        printf("Erro: Navio horizontal fora do tabuleiro.\n");
    }

    // ===== 5. VALIDAÇÃO E POSICIONAMENTO DO NAVIO VERTICAL =====
    if (linhaV + TAM_NAVIO <= TAM_TABULEIRO) {

        int podePosicionar = 1;

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                podePosicionar = 0;
            }
        }

        // Posiciona
        if (podePosicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navio_vertical[i];
            }
        } else {
            printf("Erro: Navio vertical sobrepõe outro navio.\n");
        }

    } else {
        printf("Erro: Navio vertical fora do tabuleiro.\n");
    }

    // ===== 6. EXIBIÇÃO DO TABULEIRO =====
    printf("\nTABULEIRO:\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}