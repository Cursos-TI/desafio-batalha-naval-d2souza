#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 1

int main() {

    /*int tabuleiro[4][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9 ,10 ,11},
        {12, 13, 14, 15}
    };

    printf("Navio na posição %d, %d e %d\n", tabuleiro[1][0], tabuleiro[2][0], tabuleiro[3][0]);
    printf("Navio na posição %d, %d e %d\n", tabuleiro[0][1], tabuleiro[0][2], tabuleiro[0][3]);
    */

    int tabuleiro[LINHAS][COLUNAS];
    int linhaInicial = 4, colunaInicial = 4;

    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[i][j] = AGUA;
        }
        printf("\n");
    }
    
    tabuleiro[6][3] = NAVIO;
    tabuleiro[6][4] = NAVIO;
    tabuleiro[6][5] = NAVIO;

    tabuleiro[3][6] = NAVIO;
    tabuleiro[3][7] = NAVIO;
    tabuleiro[3][8] = NAVIO;

    tabuleiro[0][9] = NAVIO;
    tabuleiro[1][8] = NAVIO;

    tabuleiro[6][1] = NAVIO;
    tabuleiro[7][2] = NAVIO;
    tabuleiro[8][3] = NAVIO;
    tabuleiro[9][4] = NAVIO;

    for (int i = 0; i < 4; i++)
    {
        int left = colunaInicial + 2 - i;
        int right = colunaInicial + 2 + i;

        for (int j = left; j < right; j++)
        {
            tabuleiro[linhaInicial + i][j] = HABILIDADE;
        }
        
    }

    int linhaDoCentroDaCruz = 1;
    int colunaDoCentroDaCruz = 1;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(i == 1 || j == 1) 
            {
                tabuleiro[linhaDoCentroDaCruz - 1 + i][colunaDoCentroDaCruz - 1 + j] = HABILIDADE;
            }
        }
    }
    
    int linhaDoOctaedro = 1;
    int colunaDoOctaedro = 8;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(i == 1 || j == 1) 
            {
                tabuleiro[colunaDoOctaedro - 1 + i][linhaDoOctaedro - 1 + j] = HABILIDADE;
            }
        }
    }


    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
