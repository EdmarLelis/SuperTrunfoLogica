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


  // Exibição de cartas:
  printf("\n\n----------- Exibicao de cartas -----------\n\n");
  printf("Carta 1: \nEstado: %c \nCodigo: %s \nNome da cidade: %sPopulacao: %lu \nArea: %.2f km quadrados \nPIB: %.2f bilhoes de reais \nNumero de Pontos Turisticos: %d \nDensidade Populacional: %.2f hab/km quadrado \nPIB per Capita: %.2f reais \nSuper poder: %.2f \n", 
    estado_1, codigo_completo_1, cidade_1, populacao_1, area_1, PIB_1, pts_turisticos_1, densidade_populacional_1, PIB_per_capita_1, super_poder_1); 
  // Exibe os dados da primeira carta

  printf("\n\nCarta 2: \nEstado: %c \nCodigo: %s \nNome da cidade: %sPopulacao: %lu \nArea: %.2f km quadrados \nPIB: %.2f bilhoes de reais \nNumero de Pontos Turisticos: %d \nDensidade Populacional: %.2f hab/km quadrado \nPIB per Capita: %.2f reais \nSuper poder: %.2f \n", 
    estado_2, codigo_completo_2, cidade_2, populacao_2, area_2, PIB_2, pts_turisticos_2, densidade_populacional_2, PIB_per_capita_2, super_poder_2);
  // Exibe os dados da segunda carta

  // Comparação e exibição da comparação:
  printf("\n\n----------- Comparacao das cartas -----------\n\n");

  // Exibição do poder de cada carta
  printf("\nCarta 1 - %s (%c), poder: %.2f", cidade_1, estado_1, super_poder_1); 
  printf("\nCarta 2 - %s (%c), poder: %.2f", cidade_2, estado_2, super_poder_2);

  if (super_poder_1 > super_poder_2){ // comparação do poder das cartas para decidir o vencedor
    printf("\nA Carta 1 (%s) ganhou!", cidade_1);
  }
  else {
    printf("\nA Carta 2 (%s) ganhou!", cidade_2);
  }

  return 0; // Indica que o programa finalizou corretamente
}
