#include <stdio.h>
#include <ctype.h>

int main()
{
  // Declaração de variáveis para armazenar os dados das cartas
  char estado_1, 
  estado_2;

  char codigo_1[3], 
  codigo_2[3];

  char codigo_completo_1[4], codigo_completo_2[4];

  char cidade_1[50], 
  cidade_2[50];

  int unsigned long populacao_1,   // Armazenando um numero decimal grande e positivo
  populacao_2;

  int pts_turisticos_1, 
  pts_turisticos_2;

  float area_1, PIB_1, 
  area_2, PIB_2;

  float densidade_populacional_1, 
  densidade_populacional_2;

  float PIB_per_capita_1, 
  PIB_per_capita_2;

  float super_poder_1, 
  super_poder_2;

  // Cadastro carta 1
  printf("\n-----------Carta 01----------- \n");
  printf("Indique uma letra de 'A' a 'H' (representando um dos oito estados) para a carta 1: ");
  scanf(" %c", &estado_1); // Lê um único caractere
  estado_1 = toupper(estado_1); // Converte o caractere para maiúscula

  printf("\nIndique um numero de 01 a 04 para complementar o codigo da carta 1: ");
  scanf(" %2s", codigo_1); // Lê uma string de até 2 caracteres

  snprintf(codigo_completo_1, sizeof(codigo_completo_1), "%c%s", estado_1, codigo_1); 
  // Concatena o estado com o número para formar o código completo da carta

  printf("\nIndique o nome da cidade para a carta 1: ");
  getchar(); // Consome o '\n' deixado pelo scanf anterior
  fgets(cidade_1, sizeof(cidade_1), stdin); // Lê a string da cidade permitindo espaços
  // Remove o '\n' da string cidade_1 caso exista
  if (cidade_1[strlen(cidade_1) - 1] == '\n') {
    cidade_1[strlen(cidade_1) - 1] = '\0';
  }

  printf("\nIndique a populacao da cidade para a carta 1: ");
  scanf("%lu", &populacao_1); // Lê um número inteiro para a população

  printf("\nIndique area da cidade em quilometros quadrados da cidade para a carta 1: ");
  scanf("%f", &area_1); // Lê um número decimal para a área

  printf("\nIndique o PIB da cidade para a carta 1: ");
  scanf("%f", &PIB_1); // Lê um número decimal para o PIB

  printf("\nIndique a quantidade de pontos turisticos na cidade para a carta 1: ");
  scanf("%d", &pts_turisticos_1); // Lê um número inteiro para os pontos turísticos

  densidade_populacional_1 = populacao_1 / area_1; // Calculando densidade populacional da carta 1
  PIB_per_capita_1 = PIB_1 / (float) populacao_1; // Calculando PIB per capita da carta 1

  float inverso_densidade_1 = densidade_populacional_1 * -1; // inverso da densidade

  super_poder_1 = (float) populacao_1 + area_1 + PIB_1 + (float) pts_turisticos_1 + PIB_per_capita_1 + inverso_densidade_1; // Calculando o poder da carta

  // Cadastro carta 2
  printf("\n\n-----------Carta 02----------- \n");
  printf("Indique uma letra de 'A' a 'H' (representando um dos oito estados) para a carta 2: ");
  scanf(" %c", &estado_2);
  estado_2 = toupper(estado_2); 

  printf("\nIndique um numero de 01 a 04 para complementar o codigo da carta 2: ");
  scanf(" %2s", codigo_2);

  snprintf(codigo_completo_2, sizeof(codigo_completo_2), "%c%s", estado_2, codigo_2);

  printf("\nIndique o nome da cidade para a carta 2: ");
  getchar(); 
  fgets(cidade_2, sizeof(cidade_2), stdin); 
  // Remove o '\n' da string cidade_2 caso exista
  if (cidade_2[strlen(cidade_2) - 1] == '\n') {
    cidade_2[strlen(cidade_2) - 1] = '\0';
  }

  printf("\nIndique a populacao da cidade para a carta 2:");
  scanf("%lu", &populacao_2); 

  printf("\nIndique area da cidade em quilometros quadrados da cidade para a carta 2: ");
  scanf("%f", &area_2); 

  printf("\nIndique o PIB da cidade para a carta 2: ");
  scanf("%f", &PIB_2); 

  printf("\nIndique a quantidade de pontos turisticos na cidade para a carta 2: ");
  scanf("%d", &pts_turisticos_2); 

  densidade_populacional_2 = populacao_2 / area_2; // Calculando densidade populacional da carta 2
  PIB_per_capita_2 = PIB_2 / (float) populacao_2; // Calculando PIB per capita da carta 2

  float inverso_densidade_2 = densidade_populacional_2 * -1; // inverso da densidade


  super_poder_2 = (float) populacao_2 + area_2 + PIB_2 + (float) pts_turisticos_2 + PIB_per_capita_2 + inverso_densidade_2; // calculando o poder da carta 2


  // Menu interativo para escolha do atributo
  int escolha;
  printf("\n\n----------- Menu de Comparação -----------\n");
  printf("Escolha o atributo para comparar as cartas:\n");
  printf("1. População\n");
  printf("2. Área\n");
  printf("3. PIB\n");
  printf("4. Número de pontos turísticos\n");
  printf("5. Densidade populacional\n");
  printf("Escolha uma opção (1-5): ");
  scanf("%d", &escolha);

  // Lógica de comparação
  switch(escolha) {
    case 1: // Comparar População
      printf("\nAtributo escolhido: Populacao\n");
      printf("Populacao Carta 1: %lu\n", populacao_1);
      printf("Populacao Carta 2: %lu\n", populacao_2);
      if (populacao_1 > populacao_2) {
        printf("A Carta 1 (%s) venceu!\n", cidade_1);
      } else if (populacao_1 < populacao_2) {
        printf("A Carta 2 (%s) venceu!\n", cidade_2);
      } else {
        printf("Empate!\n");
      }
      break;
    
    case 2: // Comparar Área
      printf("\nAtributo escolhido: Area\n");
      printf("Area Carta 1: %.2f km quadrados\n", area_1);
      printf("Area Carta 2: %.2f km quadrados\n", area_2);
      if (area_1 > area_2) {
        printf("A Carta 1 (%s) venceu!\n", cidade_1);
      } else if (area_1 < area_2) {
        printf("A Carta 2 (%s) venceu!\n", cidade_2);
      } else {
        printf("Empate!\n");
      }
      break;

    case 3: // Comparar PIB
      printf("\nAtributo escolhido: PIB\n");
      printf("PIB Carta 1: %.2f bilhões\n", PIB_1);
      printf("PIB Carta 2: %.2f bilhões\n", PIB_2);
      if (PIB_1 > PIB_2) {
        printf("A Carta 1 (%s) venceu!\n", cidade_1);
      } else if (PIB_1 < PIB_2) {
        printf("A Carta 2 (%s) venceu!\n", cidade_2);
      } else {
        printf("Empate!\n");
      }
      break;

    case 4: // Comparar Pontos Turísticos
      printf("\nAtributo escolhido: Pontos Turisticos\n");
      printf("Pontos Turisticos Carta 1: %d\n", pts_turisticos_1);
      printf("Pontos Turisticos Carta 2: %d\n", pts_turisticos_2);
      if (pts_turisticos_1 > pts_turisticos_2) {
        printf("A Carta 1 (%s) venceu!\n", cidade_1);
      } else if (pts_turisticos_1 < pts_turisticos_2) {
        printf("A Carta 2 (%s) venceu!\n", cidade_2);
      } else {
        printf("Empate!\n");
      }
      break;

    case 5: // Comparar Densidade Populacional
      printf("\nAtributo escolhido: Densidade Populacional\n");
      printf("Densidade Populacional Carta 1: %.2f hab/km quadrado\n", densidade_populacional_1);
      printf("Densidade Populacional Carta 2: %.2f hab/km quadrado\n", densidade_populacional_2);
      if (densidade_populacional_1 < densidade_populacional_2) { // Regra invertida para densidade
        printf("A Carta 1 (%s) venceu!\n", cidade_1);
      } else if (densidade_populacional_1 > densidade_populacional_2) {
        printf("A Carta 2 (%s) venceu!\n", cidade_2);
      } else {
        printf("Empate!\n");
      }
      break;

    default:
      printf("Opção inválida!\n");
  }

  return 0; // Indica que o programa finalizou corretamente
}
