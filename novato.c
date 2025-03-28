#include <stdio.h>
#include <stdbool.h>

// Constantes para direções
#define CIMA 0
#define BAIXO 1
#define ESQUERDA 2
#define DIREITA 3
#define DIAGONAL_SUP_DIR 4
#define DIAGONAL_SUP_ESQ 5
#define DIAGONAL_INF_DIR 6
#define DIAGONAL_INF_ESQ 7

// Constantes para peças
#define BISPO 0
#define TORRE 1
#define RAINHA 2

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
        case DIAGONAL_SUP_DIR:
            printf("Diagonal Superior Direita\n");
            break;
        case DIAGONAL_SUP_ESQ:
            printf("Diagonal Superior Esquerda\n");
            break;
        case DIAGONAL_INF_DIR:
            printf("Diagonal Inferior Direita\n");
            break;
        case DIAGONAL_INF_ESQ:
            printf("Diagonal Inferior Esquerda\n");
            break;
    }
}

// Função para mover o bispo
void moverBispo() {
    printf("\nMovimento do Bispo (5 casas na diagonal superior direita):\n");
    
    // Usando for para as 5 casas
    for(int i = 1; i <= 5; i++) {
        printf("Casa %d: ", i);
        imprimirDirecao(DIAGONAL_SUP_DIR);
    }
    
    // Demonstração da combinação de direções básicas
    printf("\nCombinacao de direcoes basicas para diagonal:\n");
    for(int i = 0; i < 5; i++) {
        printf("Passo %d: ", i+1);
        imprimirDirecao(CIMA);
        imprimirDirecao(DIREITA);
    }
}

// Função para mover a torre
void moverTorre() {
    printf("\nMovimento da Torre (5 casas para a direita):\n");
    
    // Usando while para as 5 casas
    int casas = 0;
    while(casas < 5) {
        casas++;
        printf("Casa %d: ", casas);
        imprimirDirecao(DIREITA);
    }
}

// Função para mover a rainha
void moverRainha() {
    printf("\nMovimento da Rainha (8 casas para a esquerda):\n");
    
    // Usando do-while para as 8 casas
    int casas = 0;
    do {
        casas++;
        printf("Casa %d: ", casas);
        imprimirDirecao(ESQUERDA);
    } while(casas < 8);
}

// Função principal
int main() {
    printf("=== Simulador de Movimentos de Xadrez ===\n");
    
    // Variáveis para controle
    int peca = BISPO; // Pode ser alterado para TORRE ou RAINHA
    bool executando = true;
    
    // Loop principal do programa
    while(executando) {
        printf("\nSelecione a peca para mover:\n");
        printf("0 - Bispo\n1 - Torre\n2 - Rainha\n3 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &peca);
        
        switch(peca) {
            case BISPO:
                moverBispo();
                break;
            case TORRE:
                moverTorre();
                break;
            case RAINHA:
                moverRainha();
                break;
            default:
                executando = false;
                break;
        }
    }
    
    printf("\nPrograma encerrado.\n");
    return 0;
}