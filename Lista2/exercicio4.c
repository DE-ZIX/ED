#include <stdio.h>
#include <stdlib.h>

#define TMAX 5

int n = 5;
int fila2[TMAX], fila5[TMAX], fila7[TMAX], fila2ini=0, fila5ini=0, fila7ini=0, fila2fim=0, fila5fim=0,fila7fim=0;
int enfila(int ele, int fila[n]){
  if (fila == fila2)
    if ((ele%2)==0 && ele!=0){
      if (fila2fim+1>n) fila2fim = 0;
      fila2[fila2fim] = ele;
      fila2fim++;
    }
  else printf("Elemento nao divisivel por 2.\n\n");

  if (fila == fila5)
    if ((ele%5)==0 && ele!=0){
      if (fila5fim+1>n) fila5fim = 0;
      fila5[fila5fim] = ele;
      if (fila5fim+1>n) fila5fim = 0; else fila5fim++;
    }
  else printf("Elemento nao divisivel por 5.\n\n");

  if (fila == fila7)
    if ((ele%7)==0 && ele!=0){
      if (fila7fim+1>n) fila7fim = 0;
      fila7[fila7fim] = ele;
      if (fila7fim+1>n) fila7fim = 0; else fila7fim++;
    }
  else printf("Elemento nao divisivel por 7.\n\n");
}

int desenfila(int fila[n]){
  if (fila == fila2){
    fila2[fila2ini] = 0;
    if (fila2ini+1>n) fila2ini = 0; else fila2ini++;
  }
  if (fila == fila5){
    fila5[fila5ini] = 0;
    if (fila5ini+1>n) fila5ini = 0; else fila5ini++;
  }
  if (fila == fila7){
    fila7[fila7ini] = 0;
    if (fila7ini+1>n) fila7ini = 0; else fila7ini++;
  }
}

int comprimento(int fila[n]){
  int x=0;
  for (size_t i = 0; i < n; i++) if(fila[i]!=0) x++;
  return x;
}



int main(int argc, char const *argv[]) {
  int x=2;
  fila2ini=0; fila5ini=0; fila7ini=0; fila2fim=0; fila5fim=0;fila7fim=0;
  for (size_t i = 0; i < n; i++){enfila(x,fila2);x=x+2;}
  enfila(0,fila5);
  enfila(2,fila5);
  enfila(3,fila5);
  enfila(5,fila5);
  enfila(10,fila5);
  enfila(3,fila7);
  enfila(7,fila7);
  enfila(14,fila7);
  enfila(22,fila7);
  enfila(21,fila7);

  printf("Fila 2: ");
  for (size_t i = 0; i < n; i++)printf("%d ", fila2[i]);
  //for (size_t i = 0; i < n; i++)if(fila2[i] != NULL)printf("%d ", fila2[i]);
  printf("\n\nFila 5: ");
  for (size_t i = 0; i < n; i++)printf("%d ", fila5[i]);
  //for (size_t i = 0; i < n; i++)if(fila5[i] != NULL)printf("%d ", fila5[i]);
  printf("\n\nFila 7: ");
  for (size_t i = 0; i < n; i++)printf("%d ", fila7[i]);
  //for (size_t i = 0; i < n; i++)if(fila7[i] != NULL)printf("%d ", fila7[i]);
  printf("\n\n");

  printf("Comprimento da Fila2: %d\n", comprimento(fila2));
  printf("Comprimento da Fila5: %d\n", comprimento(fila5));
  printf("Comprimento da Fila7: %d\n\n", comprimento(fila7));

}
