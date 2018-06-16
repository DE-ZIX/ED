#include <stdio.h>
#include <stdlib.h>

#define TMAX 100

int x = 100;

int p[TMAX], top1=0, top2=0;

void declara(){
  top2 = x/2;
}

int empilha(int n, int vet){
  if (vet==1 && (top1+1) < x/2) {
    p[top1] = n;
    top1++;
  }
  if (vet==2 && (top2+1) < x) {
    p[top2] = n;
    top2++;
  }
}

int desempilha(int vet){
  if (vet==1) {
    p[top1-1] = NULL;
    top1--;
  }
  if (vet==2) {
    p[top2-1] = NULL;
    top2--;
  }
}

void imprime(int vet){
  printf("Vetor P%d: ", vet);
  if (vet==1)
    for (size_t i = 0; i < top1; i++) printf("%d ", p[i]);
  if (vet==2)
    for (size_t i = x/2; i < top2; i++) printf("%d ", p[i]);

}

int main(int argc, char const *argv[]) {
  declara();
  for (size_t i = 1; i < 7; i++) empilha(i, 1);
  for (size_t i = 10; i < 16; i++) empilha(i, 2);
  imprime(1);
  printf("\n\n");
  imprime(2);
  printf("\n");
  return 0;
}
