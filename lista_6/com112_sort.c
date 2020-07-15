// Luciano José de Araujo -- 2018006868

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "com112_sort.h"
#include "com112_file.h"

void bubble_sort(int vetor[], int n)
{
    clock_t t_ini, t_fim; 
    float tempo;
    int k, j, aux, comp=0, mov=0;

    t_ini = clock();
    for (k = n - 1; k > 0; k--)
    {
        for (j = 0; j < k; j++)
        {
            comp++;
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                mov += 2;
            }
        }
    }
    t_fim = clock();
    tempo = (t_fim - t_ini)*1000/CLOCKS_PER_SEC;
    printf("Bubble Sort realizado com sucesso");
    relatorioEscreve(n,tempo,comp,mov,1);
    return;
}

void selection_Sort(int vet[],int n) 
{ 
    clock_t t_ini, t_fim;
    float tempo;
    int minIndex,comp=0,mov=0;
    int aux;

    t_ini = clock();
    for (int i = 0; i < n-1; i++) 
    { 
        minIndex = i; 
        for (int j = i+1; j < n; j++)
        {
          comp++;
          if (vet[j] < vet[minIndex])
            minIndex = j;
        }
        aux = vet[i];
        vet[i] = vet[minIndex];
        vet[minIndex] = aux;
        mov+=2;        
    }
    t_fim = clock();
    tempo = (t_fim - t_ini)*1000/CLOCKS_PER_SEC;
    relatorioEscreve(n,tempo,comp,mov,2);
    printf("Selection Sort realizado com sucesso");
    return;
} 

void insertion_sort(int vetor[], int n)
{
    clock_t t_ini, t_fim;
    float tempo;
    int k, j, aux,comp=0,mov=0;
    t_ini = clock();
    for (k = 1; k <= n - 1; k++)
    {
        aux = vetor[k];
        j = k - 1;
        comp++;
        while (j >= 0 && aux < vetor[j])
        {
            vetor[j + 1] = vetor[j];
            j--;
            mov++;
            comp++;
        }
        vetor[j + 1] = aux;
        mov++;
    }
    t_fim = clock();
    tempo = (t_fim - t_ini)*1000/CLOCKS_PER_SEC;
    relatorioEscreve(n,tempo,comp,mov,3);
    printf("Insertion Sort realizado com sucesso");
    return;
}

void merge(int *v, int inicio, int meio, int fim,int *comp,int *mov)
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1=inicio;
    p2=meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    (*comp)++;
    if(temp != NULL)
    {
        for(i=0;i<tamanho;i++)
        {
          (*comp)++;
            if(!fim1 && !fim2)
            {
              (*comp)++;
                if(v[p1] < v[p2])
                    temp[i]=v[p1++];
                else
                    temp[i]=v[p2++];
                if(p1>meio)
                  fim1=1;
                if(p2>fim)
                  fim2=1;
                (*comp) += 2;
            }else
            {
              (*comp)++;
                if(!fim1)
                    temp[i]=v[p1++];
                else
                    temp[i]=v[p2++];
                    
            }    
        }
        for(j=0, k=inicio;j<tamanho;j++, k++){
            v[k] = temp[j];
            (*mov)++;
        }
    }
    free(temp);
    return;
}

void mergeSort(int *V,int inicio,int fim,int *comp,int *mov)
{
  int meio;
  (*comp)++;
  if(inicio<fim){
    meio = floor((inicio+fim)/2);
    mergeSort(V,inicio,meio,comp,mov);
    mergeSort(V,meio+1,fim,comp,mov);
    merge(V,inicio,meio,fim,comp,mov);
  }
}
int particiona(int *v,int inicio,int final,int *comp,int *mov){
  int esq, dir, pivo, aux;
  esq = inicio;
  dir = final;
  pivo = v[inicio];
  while(esq < dir){
   
    while(v[esq] <= pivo){
      esq++;
      (*comp)++;
    }
    while(v[dir] > pivo){
      dir--;
      (*comp)++;
    }
    (*comp)++;
    if(esq < dir){
      aux = v[esq];
      v[esq] = v[dir];
      v[dir] = aux;
      *mov = *mov + 2;
    }
     (*comp)++;
  }
  v[inicio] = v[dir];
  v[dir] = pivo;
  *mov = *mov + 2;

  return dir;
}

void quickSort(int *v,int inicio,int fim,int *comp,int *mov){
  int pivo;
  (*comp)++;
  if(fim > inicio){
    pivo = particiona(v, inicio, fim,comp,mov);
    quickSort(v,inicio,pivo-1,comp,mov);
    quickSort(v,pivo+1,fim,comp,mov);
  }
}
