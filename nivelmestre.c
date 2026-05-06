#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define H 5 // tamanho das matrizes de habilidade (5x5)

// ===== VALIDA POSICIONAMENTO DE NAVIO =====
int podePosicionar(int tab[TAM][TAM], int l, int c, int dl, int dc) {
    for (int i = 0; i < NAVIO; i++) {
        int nl = l + i * dl;
        int nc = c + i * dc;

        if (nl < 0 || nl >= TAM || nc < 0 || nc >= TAM) return 0;
        if (tab[nl][nc] != 0) return 0;
    }
    return 1;
}

// ===== POSICIONA NAVIO =====
void posicionarNavio(int tab[TAM][TAM], int l, int c, int dl, int dc) {
    for (int i = 0; i < NAVIO; i++) {
        tab[l + i * dl][c + i * dc] = 3;
    }
}

// ===== CRIA MATRIZ CONE (topo no meio, expandindo para baixo) =====
void criarCone(int cone[H][H]) {
    int meio = H / 2;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (j >= meio - i && j <= meio + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// ===== CRIA MATRIZ CRUZ =====
void criarCruz(int cruz[H][H]) {
    int meio = H / 2;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i == meio || j == meio) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// ===== CRIA MATRIZ OCTAEDRO (losango) =====
void criarOctaedro(int oct[H][H]) {
    int meio = H / 2;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio) {
                oct[i][j] = 1;
            } else {
                oct[i][j] = 0;
            }
        }
    }
}

// ===== APLICA HABILIDADE NO TABULEIRO =====
void aplicarHabilidade(int tab[TAM][TAM], int hab[H][H], int origemL, int origemC) {
    int meio = H / 2;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            int l = origemL + (i - meio);
            int c = origemC + (j - meio);

            if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                if (hab[i][j] == 1 && tab[l][c] == 0) {
                    tab[l][c] = 5; // marca área de efeito
                }
            }
        }
    }
}

int main() {

    int tab[TAM][TAM];

    // ===== INICIALIZA TABULEIRO =====
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = 0;

    // ===== NAVIOS (mesmo padrão do nível anterior) =====
    int navios[4][4] = {
        {1, 1, 0, 1},
        {5, 2, 1, 0},
        {0, 7, 1, -1},
        {6, 6, 1, 1}
    };

    for (int n = 0; n < 4; n++) {
        if (podePosicionar(tab, navios[n][0], navios[n][1], navios[n][2], navios[n][3])) {
            posicionarNavio(tab, navios[n][0], navios[n][1], navios[n][2], navios[n][3]);
        }
    }

    // ===== MATRIZES DE HABILIDADE =====
    int cone[H][H], cruz[H][H], oct[H][H];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(oct);

    // ===== APLICA HABILIDADES (pontos definidos no código) =====
    aplicarHabilidade(tab, cone, 2, 2);
    aplicarHabilidade(tab, cruz, 7, 7);
    aplicarHabilidade(tab, oct, 5, 5);

    // ===== EXIBIÇÃO =====
    printf("\nTABULEIRO FINAL (0=agua, 3=navio, 5=habilidade):\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tab[i][j] == 0) printf(". ");
            else if (tab[i][j] == 3) printf("N ");
            else if (tab[i][j] == 5) printf("* ");

        }
        printf("\n");
    }

    return 0;
}