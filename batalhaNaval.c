#include <stdio.h>

#define LINHAS 10 // linhas que a matriz terá
#define COLUNAS 10 //colunas que a matriz terá

#define AGUA 0 
#define NAVIO 3
#define HABILIDADE 1

int main() {

    int tabuleiro[LINHAS][COLUNAS]; // matriz recebendo os valores setados nas constantes


    for (int i = 0; i < LINHAS; i++) //Aqui estou definindo a matriz em si
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[i][j] = AGUA;
        }
        printf("\n");
    }
    
    //Declaração dos navios

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

    int linhaInicial = 4, colunaInicial = 4; //Definindo o local onde a piramide irá começar

    for (int i = 0; i < 4; i++)
    {
        int esquerda = colunaInicial + 2 - i; // posição esquerda onde será desenhado o cone
        int direita = colunaInicial + 2 + i;// posição direita onde será desenhado o cone

        for (int j = esquerda; j < direita ; j++) //alterando os valores para 1
        {
            tabuleiro[linhaInicial + i][j] = HABILIDADE;
        }
        
    }

    int linhaDoCentroDaCruz = 1; //posição da cruz linha na matriz
    int colunaDoCentroDaCruz = 1; //posição da cruz coluna na matriz

    for (int i = 0; i < 4; i++) //iterando por 4 posições
    {
        for (int j = 0; j < 4; j++)
        {
            if(i == 1 || j == 1) //verificando as posições de i e j e preenchendo até que forme a cruz
            {
                tabuleiro[linhaDoCentroDaCruz - 1 + i][colunaDoCentroDaCruz - 1 + j] = HABILIDADE;
            }
        }
    }
    
    int linhaDoOctaedro = 1; //posição na matriz
    int colunaDoOctaedro = 8;

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
        {
            if(i == 1 || j == 1) //desenhando o octaedro após verificar as posições i e j
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

    return 0;
}
