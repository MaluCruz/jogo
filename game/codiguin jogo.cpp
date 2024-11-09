#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para verificar se a peça foi encontrada
void EncontrouPeca(int posicao, int peca) {
    if (posicao == peca) {
        printf("Parabens! Voce encontrou a peça!\n");
    } else {
        printf("Nao ha peça nesta posicao.\n");
        printf("Continue procurando!\n");
    }
}

// Função para gerar um número aleatório no intervalo especificado
int NumAleatorio(int inicio, int fim) {
    return rand() % (fim - inicio + 1) + inicio;
}

int main() {
    // Variáveis
    int componentes[10]; // Vetor que representa os componentes da máquina
    int posicaoAtual, opcao, peca, i, j, temp;
    int codigoSecreto = 224; // Código secreto para finalizar o jogo
    int codigoEntrada; // Variável para armazenar a entrada do jogador

    // Inicialização do gerador de números aleatórios
    srand(time(NULL));

    // Inicialização do vetor componentes com valores de 0 a 9
    for (i = 0; i < 10; i++) {
        componentes[i] = i;
    }

    // Embaralhamento do vetor componentes para simular uma distribuição aleatória
    for (i = 0; i < 10; i++) {
        j = NumAleatorio(i, 9); // Gera um índice aleatório
        // Troca os elementos do vetor
        temp = componentes[i];
        componentes[i] = componentes[j];
        componentes[j] = temp;
    }

    // Definir a posição inicial do jogador e a posição da peça
    posicaoAtual = 0;
    peca = NumAleatorio(0, 9); // Escolhe aleatoriamente a posição da peça

    // Loop principal do jogo
    while (1) {
        printf("Voce esta na posicao %d da máquina.\n", posicaoAtual);
        printf("Escolha um numero para avancar (0 a 9): ");
        scanf("%d", &opcao);

        // Verifica se a opção escolhida pelo jogador é válida
        if (opcao >= 0 && opcao <= 9) {
            posicaoAtual = opcao; // Atualiza a posição atual do jogador
            EncontrouPeca(posicaoAtual, peca); // Verifica se a peça foi encontrada

            // Se a peça foi encontrada, sai do loop
            if (posicaoAtual == peca) {
                break;
            }
        } else if (opcao == codigoSecreto) { // Verifica se o código secreto foi inserido
            printf("Codigo secreto inserido! O jogo foi finalizado.\n");
            break; // Sai do loop
        } else {
            printf("Opcao invalida. Tente novamente.\n"); // Informa o jogador sobre a opção inválida
        }
    }

    return 0;
}