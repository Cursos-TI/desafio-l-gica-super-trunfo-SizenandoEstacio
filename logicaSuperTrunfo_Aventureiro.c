#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as informações de cada carta
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
    // Cadastro pré-definido de duas cartas (pode ser via scanf se quiser)
    struct Carta carta1 = {"SP", "A01", "São Paulo", 12325000, 1521.11, 699.28, 50};
    struct Carta carta2 = {"RJ", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    // Cálculos extras
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib * 1000000000 / carta1.populacao; // PIB em bilhões -> reais
    carta2.pibPerCapita = carta2.pib * 1000000000 / carta2.populacao;

    int escolha;

    printf("\n==== SUPER TRUNFO ====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("Digite a opção: ");
    scanf("%d", &escolha);

    printf("\nComparação entre %s (Carta 1) e %s (Carta 2):\n", carta1.cidade, carta2.cidade);

    switch (escolha) {
        case 1: // População
            printf("População: %d x %d\n", carta1.populacao, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // Área
            printf("Área: %.2f km² x %.2f km²\n", carta1.area, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // PIB
            printf("PIB: %.2f bi x %.2f bi\n", carta1.pib, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Pontos turísticos
            printf("Pontos Turísticos: %d x %d\n", carta1.pontosTuristicos, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Densidade (regra invertida)
            printf("Densidade: %.2f hab/km² x %.2f hab/km²\n", carta1.densidade, carta2.densidade);
            if (carta1.densidade < carta2.densidade) {
                printf("Resultado: Carta 1 (%s) venceu (menor densidade)!\n", carta1.cidade);
            } else if (carta2.densidade < carta1.densidade) {
                printf("Resultado: Carta 2 (%s) venceu (menor densidade)!\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 6: // PIB per Capita
            printf("PIB per Capita: %.2f reais x %.2f reais\n", carta1.pibPerCapita, carta2.pibPerCapita);
            if (carta1.pibPerCapita > carta2.pibPerCapita) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Escolha entre 1 e 6.\n");
    }

    return 0;
}
