#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
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

// Função para calcular atributos derivados
void calcularExtras(struct Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000) / c->populacao; // PIB em bilhões
}

// Função para exibir opções do menu
void mostrarMenu(int excluir) {
    printf("\nEscolha um atributo:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Populacional\n");
    if (excluir != 6) printf("6 - PIB per Capita\n");
    printf("Digite a opção: ");
}

// Função para pegar o valor de um atributo
float pegarAtributo(struct Carta c, int opcao) {
    switch (opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidade;
        case 6: return c.pibPerCapita;
        default: return 0;
    }
}

// Função para nome do atributo
const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        default: return "Inválido";
    }
}

int main() {
    // Duas cartas pré-cadastradas
    struct Carta carta1 = {"SP", "A01", "São Paulo", 12325000, 1521.11, 699.28, 50};
    struct Carta carta2 = {"RJ", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    calcularExtras(&carta1);
    calcularExtras(&carta2);

    int escolha1, escolha2;

    // Escolha do primeiro atributo
    mostrarMenu(0);
    scanf("%d", &escolha1);

    // Escolha do segundo atributo (sem repetir o primeiro)
    mostrarMenu(escolha1);
    scanf("%d", &escolha2);

    // Valores das cartas
    float valor1_c1 = pegarAtributo(carta1, escolha1);
    float valor1_c2 = pegarAtributo(carta2, escolha1);
    float valor2_c1 = pegarAtributo(carta1, escolha2);
    float valor2_c2 = pegarAtributo(carta2, escolha2);

    // Comparações individuais com if-else + operador ternário
    int resultado1, resultado2;

    if (escolha1 == 5) { // regra invertida para densidade
        resultado1 = (valor1_c1 < valor1_c2) ? 1 : (valor1_c2 < valor1_c1) ? 2 : 0;
    } else {
        resultado1 = (valor1_c1 > valor1_c2) ? 1 : (valor1_c2 > valor1_c1) ? 2 : 0;
    }

    if (escolha2 == 5) { // regra invertida
        resultado2 = (valor2_c1 < valor2_c2) ? 1 : (valor2_c2 < valor2_c1) ? 2 : 0;
    } else {
        resultado2 = (valor2_c1 > valor2_c2) ? 1 : (valor2_c2 > valor2_c1) ? 2 : 0;
    }

    // Soma dos atributos
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    int vencedor = (soma_c1 > soma_c2) ? 1 : (soma_c2 > soma_c1) ? 2 : 0;

    // ======= Saída =======
    printf("\n==== RESULTADO DA RODADA ====\n");
    printf("Carta 1 - %s\n", carta1.cidade);
    printf("Carta 2 - %s\n\n", carta2.cidade);

    printf("Atributo 1 (%s): %.2f x %.2f => %s\n",
           nomeAtributo(escolha1), valor1_c1, valor1_c2,
           resultado1 == 1 ? carta1.cidade :
           resultado1 == 2 ? carta2.cidade : "Empate");

    printf("Atributo 2 (%s): %.2f x %.2f => %s\n",
           nomeAtributo(escolha2), valor2_c1, valor2_c2,
           resultado2 == 1 ? carta1.cidade :
           resultado2 == 2 ? carta2.cidade : "Empate");

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.cidade, soma_c1);
    printf("%s: %.2f\n", carta2.cidade, soma_c2);

    if (vencedor == 1) {
        printf("\nResultado Final: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (vencedor == 2) {
        printf("\nResultado Final: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("\nResultado Final: Empate!\n");
    }

    return 0;
}
