#include <stdio.h>
#include <stdlib.h>
typedef struct dados{
  int dado;

  struct dados *prox;  
}Pilha;


Pilha *inserir(int valor,Pilha *pilha){
    Pilha *novo = (Pilha *) malloc(sizeof(Pilha));
    novo->dado = valor;
    novo->prox = pilha;
    return novo;
}

int main(){
  FILE *file;
  char arquivo[200];
  Pilha *pilha = NULL;
  int contador = 0;
  
  
  printf("digite o nome do arquivo: ");
  scanf("%s",arquivo);
  file = fopen(arquivo,"r");
  if(!file){
    printf("arquivo nao abriu");
    exit(0);
  }
  char numeros[100];
  int valor;
  while (fgets(numeros,100,file)!=NULL)
  {
    fscanf(file,"%d",&valor);
    printf("%d\n",valor);
    pilha = inserir(valor,pilha);
    contador++;  
  }
  printf("o ultimo valor inserido foi: %d\n",valor);
  printf("%d",contador);
    
 
 
  
  return 0;
}