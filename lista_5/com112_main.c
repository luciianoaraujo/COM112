// Luciano José de Araujo -- 2018006868

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "com112_file.h"
#include "com112_sort.h"

int menu()
{
    int opcao;
    printf("\n-------------------MENU-------------------\n");
    printf("|           1. Bubble Sort               |\n");
    printf("|           2. Selection Sort            |\n");
    printf("|           3. Insertion Sort            |\n");
    printf("|           4. Merge Sort                |\n");
    printf("|           5. Relatorio                 |\n");
    printf("|           6. Sair                      |\n");
    printf("------------------------------------------\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int relatorio(int tam)
{
char s[50],c;
FILE *arq;
arq = fopen("com112_relatorio.txt","r");
if(arq == NULL)
    {
      printf("\nErro, nao foi possivel ler o arquivo\n");
      return 1;
    }
else if((c=fgetc(arq)) == EOF )
{
  printf("Arquivo vazio");
  return 1;
}
rewind(arq);
while((fgets(s,50,arq)) != NULL){
printf("\n%s\n", s);
}
fclose(arq);
return 0;
}

void copiaVetor(int vetn[],int vet[], int tam){
  int i;
  for(i=0;i<tam;i++)
  {
    vetn[i] = vet[i];
  }
  return;
}

int main()
{
  int *v,*v1, tam, opcao,comp=0,mov=0;
  clock_t t_ini, t_fim;
  float tempo;

  printf("Digite a quantidade de numeros da sua sequencia:");
  scanf("%d", &tam);
  v = (int*) malloc(tam*sizeof(int)); 
  v1 = (int*) malloc(tam*sizeof(int));
  entrada(v,tam);
 
 
  do{
  opcao = menu();
  switch(opcao)
  {
    case 1:
      copiaVetor(v1, v, tam);
      bubble_sort(v1,tam);
      saida(v1,tam);
      break;
    case 2:
      copiaVetor(v1, v, tam);
      selection_Sort(v1, tam);
      saida(v1,tam);
      break;
    case 3:
      copiaVetor(v1, v, tam);
      insertion_sort(v1,tam);
      saida(v1,tam);
      break;
    case 4:
      copiaVetor(v1, v, tam);
      t_ini = clock();
      mergeSort(v1,0,tam,&comp,&mov);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);
      relatorioEscreve(tam, tempo,comp,mov,4);
      saida(v1,tam);
    break;
    case 5:
      relatorio(tam);
      break;
    case 6:
      printf("\nSaindo...\n");
      free(v);
      free(v1);
    break;
    default: 
      printf("Numero invalido");
  } 
}while(opcao!=6);
return 0;
}
