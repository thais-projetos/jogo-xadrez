#include <stdio.h>
#include <stdbool.h>

// Constantes para direções
#define CIMA 0
#define BAIXO 1
#define ESQUERDA 2
#define DIREITA 3

// Função para imprimir direções
void imprimirDirecao(int direcao) {
    switch(direcao) {
        case CIMA:
            printf("Cima\n");
            break;
        case BAIXO:
            printf("Baixo\n");
            break;
        case ESQUERDA:
            printf("Esquerda\n");
            break;
        case DIREITA:
            printf("Direita\n");
            break;
    }
}

// Função para mover o cavalo em L (para baixo e esquerda)
void moverCavalo() {
    printf("\nMovimento do Cavalo (em L para baixo e esquerda):\n");
    
    // Primeira parte do L: 2 casas para baixo
    printf("Primeira parte do L (2 casas para baixo):\n");
    for(int i = 0; i < 2; i++) {
        printf("Passo %d: ", i+1);
        imprimirDirecao(BAIXO);
    }
    
    // Segunda parte do L: 1 casa para esquerda
    printf("\nSegunda parte do L (1 casa para esquerda):\n");
    int contador = 0;
    while(contador < 1) {
        printf("Passo %d: ", contador+1);
        imprimirDirecao(ESQUERDA);
        contador++;
    }
    
    // Versão alternativa com loops aninhados para mostrar todas as combinações possíveis
    printf("\nTodas as possiveis combinacoes de movimento em L:\n");
    for(int vertical = 1; vertical <= 2; vertical++) {
        for(int horizontal = 1; horizontal <= 2; horizontal++) {
            if((vertical == 2 && horizontal == 1) || (vertical == 1 && horizontal == 2)) {
                printf("\nPadrao L %dx%d:\n", vertical, horizontal);
                
                // Movimento vertical
                int v = 0;
                do {
                    printf("Passo %d: ", v+1);
                    imprimirDirecao(vertical == 2 ? BAIXO : CIMA);
                    v++;
                } while(v < vertical);
                
                // Movimento horizontal
                for(int h = 0; h < horizontal; h++) {
                    printf("Passo %d: ", v+h+1);
                    imprimirDirecao(horizontal == 2 ? DIREITA : ESQUERDA);
                }
            }
        }
    }
}

// Função principal
int main() {
    printf("=== Simulador de Movimentos de Xadrez - Nivel Aventureiro ===\n");
    printf("Movimento do Cavalo em L:\n");
    
    moverCavalo();
    
    printf("\nDemonstracao concluida.\n");
    return 0;
}