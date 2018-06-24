#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int info;
  struct no* e;
  struct no* d;
}no;

no* novono(int info){
  no* n = (no*)malloc(sizeof(no));
  n->info = info;
  n->e = NULL;
  n->d = NULL;
  return n;
}

void ordenar(int *vet){
  int x=vet[0], j=0;
  int y = 15;
  int arr[y];
  for (size_t i = 0; i < y; i++) arr[i]=0;
  for (size_t k = 0; k < y; k++) {
    for (size_t i = 0; i < y; i++) {
      if (x > vet[i] && vet[i]!=0){
        x=vet[i];
        j=i;
      }
    }
    arr[k] = vet[j];
    vet[j] = 0;
    x=1000;
  }
  for (size_t i = 0; i < 15; i++) vet[i] = arr[i];
  return;
}

no* buildminheap(int vet[], int ind){
  no* n = novono(vet[ind]);
  if(2*ind == 0) {n->e = buildminheap(vet, 2*ind+1); n->d = buildminheap(vet, 2*ind+2);}
  else if(2*ind<15 && 2*ind+1<15) {n->e = buildminheap(vet, 2*ind); n->d = buildminheap(vet, 2*ind+1);}
  return n;
}

void inorder(no* n){
  printf("%d ", n->info);
  inorder(n->e);
  inorder(n->d);
}

int main(){
  int arr1[100] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  ordenar(arr1);
  no* n = buildminheap(arr1, 0);
  inorder(n);
  return 0;
}
