#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[20];
    int ataque;
    int defesa;
} Carta;

int main() {
    srand(time(NULL));

    // Baralho básico
    Carta baralho[4] = {
        {"Cavaleiro", 70, 50},
        {"Dragão", 90, 40},
        {"Mago", 60, 80},
        {"Orc", 75, 60}
    };

    // Sorteio de cartas (simples)
    int suaCarta = rand() % 4;
    int cpuCarta;
    do {
        cpuCarta = rand() % 4;
    } while(cpuCarta == suaCarta);

    printf("=== SUPER TRUNFO BÁSICO ===\n");
    printf("Sua carta: %s (Ataque: %d | Defesa: %d)\n",
           baralho[suaCarta].nome,
           baralho[suaCarta].ataque,
           baralho[suaCarta].defesa);

    int escolha;
    printf("Escolha atributo para disputar (1 = Ataque, 2 = Defesa): ");
    scanf("%d", &escolha);

    int valorJogador, valorCPU;
    if(escolha == 1){
        valorJogador = baralho[suaCarta].ataque;
        valorCPU = baralho[cpuCarta].ataque;
        printf("CPU escolheu %s (Ataque: %d)\n",
               baralho[cpuCarta].nome, valorCPU);
    } else {
        valorJogador = baralho[suaCarta].defesa;
        valorCPU = baralho[cpuCarta].defesa;
        printf("CPU escolheu %s (Defesa: %d)\n",
               baralho[cpuCarta].nome, valorCPU);
    }

    if(valorJogador > valorCPU){
        printf("Você venceu!\n");
    } else if(valorJogador < valorCPU){
        printf("CPU venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}
