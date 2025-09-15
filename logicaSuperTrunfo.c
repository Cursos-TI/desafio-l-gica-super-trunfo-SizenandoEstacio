#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[3];
    char codigo[4];
    char cidade[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
};

int main() {
    // Cadastro manual das cartas (pré-definidas)
    struct Carta carta1 = {"SP", "A01", "São Paulo", 12300000, 1521.0, 699.28, 25};
    struct Carta carta2 = {"RJ", "A02", "Rio de Janeiro", 6718903, 1182.3, 395.36, 18};

    // Cálculo dos atributos derivados
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // --- Comparação ---
    // Aqui escolhemos qual atributo comparar: População, Área, PIB, Densidade ou PIB per capita.
    // Neste exemplo: PIB per capita
    printf("Comparacao de cartas (Atributo: PIB per capita):\n\n");

    printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.pibPerCapita);
    printf("Carta 2 - %s (%s): %.2f\n\n", carta2.cidade, carta2.estado, carta2.pibPerCapita);

    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
