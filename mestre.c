#include <stdio.h>
#include <stdbool.h>

// Constantes para direções
#define CIMA 0
#define BAIXO 1
#define ESQUERDA 2
#define DIREITA 3
#define DIAGONAL_SUP_DIR 4

// Protótipos das funções
void imprimirDirecao(int direcao);
void moverBispoRecursivo(int casas);
void moverTorreRecursivo(int casas);
void moverRainhaRecursivo(int casas);
void moverCavaloComplexo();

// Função principal
int main() {
    printf("=== Simulador de Xadrez - Nivel Mestre ===\n");
    
    printf("\n--- Movimento do Bispo (5 casas diagonal superior direita) ---\n");
    moverBispoRecursivo(5);
    
    printf("\n--- Movimento da Torre (5 casas para direita) ---\n");
    moverTorreRecursivo(5);
    
    printf("\n--- Movimento da Rainha (8 casas para esquerda) ---\n");
    moverRainhaRecursivo(8);
    
    printf("\n--- Movimento do Cavalo (L para cima-direita) ---\n");
    moverCavaloComplexo();
    
    return 0;
}

void imprimirDirecao(int direcao) {
    const char* direcoes[] = {"Cima", "Baixo", "Esquerda", "Direita", "Diagonal Superior Direita"};
    printf("%s\n", direcoes[direcao]);
}

// Função recursiva para mover o bispo
void moverBispoRecursivo(int casas) {
    if (casas <= 0) return;
    
    printf("Casa %d: ", 6 - casas);
    imprimirDirecao(DIAGONAL_SUP_DIR);
    
    moverBispoRecursivo(casas - 1); // Chamada recursiva
}

// Função recursiva para mover a torre
void moverTorreRecursivo(int casas) {
    if (casas <= 0) return;
    
    printf("Casa %d: ", 6 - casas);
    imprimirDirecao(DIREITA);
    
    moverTorreRecursivo(casas - 1); // Chamada recursiva
}

// Função recursiva para mover a rainha
void moverRainhaRecursivo(int casas) {
    if (casas <= 0) return;
    
    printf("Casa %d: ", 9 - casas);
    imprimirDirecao(ESQUERDA);
    
    moverRainhaRecursivo(casas - 1); // Chamada recursiva
}

// Função complexa para mover o cavalo com loops aninhados e controle preciso
void moverCavaloComplexo() {
    int movimentos = 0;
    bool movimentoCompleto = false;
    
    // Loop externo para controle geral
    for (int etapa = 1; etapa <= 2 && !movimentoCompleto; etapa++) {
        // Loop interno com condição múltipla
        for (int passo = 1; passo <= 2; passo++) {
            if (etapa == 1 && passo == 2) {
                continue; // Pula o segundo passo da primeira etapa
            }
            
            if (etapa == 2 && passo == 1) {
                printf("Passo %d: ", ++movimentos);
                imprimirDirecao(DIREITA);
                break; // Interrompe após o primeiro passo da segunda etapa
            }
            
            printf("Passo %d: ", ++movimentos);
            imprimirDirecao(CIMA);
            
            if (movimentos >= 3) {
                movimentoCompleto = true;
                break;
            }
        }
    }
    
    // Versão alternativa com loops aninhados mostrando todos os padrões L
    printf("\nTodos os padrões L possíveis:\n");
    for (int vertical = 1; vertical <= 2; vertical++) {
        for (int horizontal = 1; horizontal <= 2; horizontal++) {
            if (vertical == horizontal) continue; // Ignora movimentos quadrados
            
            printf("\nPadrão L %dx%d:\n", vertical, horizontal);
            for (int v = 0; v < vertical; v++) {
                printf("Passo %d: Cima\n", v+1);
            }
            for (int h = 0; h < horizontal; h++) {
                printf("Passo %d: Direita\n", vertical+h+1);
            }
        }
    }
}