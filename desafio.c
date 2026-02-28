#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Variáveis das Cartas 
    char nome1[50], nome2[50];
    unsigned long int pop1, pop2;
    float area1, area2, pib1, pib2;
    int pontos1, pontos2;
    float densidade1, densidade2, pibCapita1, pibCapita2;
    
    // Variáveis de controle do jogo
    int opcao1, opcao2;
    float valorAtributo1_C1, valorAtributo1_C2;
    float valorAtributo2_C1, valorAtributo2_C2;
    float somaC1, somaC2;

    // --- CADASTRO (Simplificado para o exemplo) ---
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Nome da Cidade: "); scanf(" %[^\n]", nome1);
    printf("População: "); scanf("%lu", &pop1);
    printf("Área (km²): "); scanf("%f", &area1);
    printf("PIB: "); scanf("%f", &pib1);
    printf("Pontos Turísticos: "); scanf("%d", &pontos1);

    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Nome da Cidade: "); scanf(" %[^\n]", nome2);
    printf("População: "); scanf("%lu", &pop2);
    printf("Área (km²): "); scanf("%f", &area2);
    printf("PIB: "); scanf("%f", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &pontos2);

    // Cálculos de propriedades 
    densidade1 = (float)pop1 / area1;
    pibCapita1 = pib1 / (float)pop1;
    densidade2 = (float)pop2 / area2;
    pibCapita2 = pib2 / (float)pop2;

    // --- MENU INTERATIVO: PRIMEIRO ATRIBUTO --- 
    printf("\nEscolha o PRIMEIRO atributo para comparação:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade\n");
    printf("Opção: "); scanf("%d", &opcao1);

    switch (opcao1) {
        case 1: valorAtributo1_C1 = (float)pop1; valorAtributo1_C2 = (float)pop2; break;
        case 2: valorAtributo1_C1 = area1; valorAtributo1_C2 = area2; break;
        case 3: valorAtributo1_C1 = pib1; valorAtributo1_C2 = pib2; break;
        case 4: valorAtributo1_C1 = (float)pontos1; valorAtributo1_C2 = (float)pontos2; break;
        case 5: valorAtributo1_C1 = densidade1; valorAtributo1_C2 = densidade2; break;
        default: printf("Opção inválida!\n"); return 0;
    }

    // --- MENU INTERATIVO: SEGUNDO ATRIBUTO (Dinâmico) --- 
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    if (opcao1 != 1) printf("1. População\n");
    if (opcao1 != 2) printf("2. Área\n");
    if (opcao1 != 3) printf("3. PIB\n");
    if (opcao1 != 4) printf("4. Pontos Turísticos\n");
    if (opcao1 != 5) printf("5. Densidade\n");
    printf("Opção: "); scanf("%d", &opcao2);

    // Validação de atributo repetido 
    if (opcao1 == opcao2) {
        printf("Erro: Você não pode escolher o mesmo atributo duas vezes!\n");
        return 0;
    }

    switch (opcao2) {
        case 1: valorAtributo2_C1 = (float)pop1; valorAtributo2_C2 = (float)pop2; break;
        case 2: valorAtributo2_C1 = area1; valorAtributo2_C2 = area2; break;
        case 3: valorAtributo2_C1 = pib1; valorAtributo2_C2 = pib2; break;
        case 4: valorAtributo2_C1 = (float)pontos1; valorAtributo2_C2 = (float)pontos2; break;
        case 5: valorAtributo2_C1 = densidade1; valorAtributo2_C2 = densidade2; break;
        default: printf("Opção inválida!\n"); return 0;
    }

    // --- LÓGICA DE SOMA E COMPARAÇÃO --- 
    // Se for densidade, o valor é invertido para a soma pois "menor vence"
    somaC1 = (opcao1 == 5 ? (1/valorAtributo1_C1) : valorAtributo1_C1) + (opcao2 == 5 ? (1/valorAtributo2_C1) : valorAtributo2_C1);
    somaC2 = (opcao1 == 5 ? (1/valorAtributo1_C2) : valorAtributo1_C2) + (opcao2 == 5 ? (1/valorAtributo2_C2) : valorAtributo2_C2);

    // --- EXIBIÇÃO DO RESULTADO --- 
    printf("\n=== RESULTADO DA BATALHA ===\n");
    printf("Carta 1 (%s): Atributo 1 = %.2f, Atributo 2 = %.2f\n", nome1, valorAtributo1_C1, valorAtributo2_C1);
    printf("Carta 2 (%s): Atributo 1 = %.2f, Atributo 2 = %.2f\n", nome2, valorAtributo1_C2, valorAtributo2_C2);
    printf("Soma Total: Carta 1 = %.2f | Carta 2 = %.2f\n", somaC1, somaC2);

    if (somaC1 == somaC2) {
        printf("Resultado: Empate!\n"); 
    } else {
        printf("Vencedor: %s!\n", (somaC1 > somaC2) ? nome1 : nome2);
    }

    return 0;
}