#include <stdio.h>
#include <stdlib.h>

#define size 10


void buildmaxheap(int *vet){
  int arr[size];
  for (size_t i = 0; i < size; i++) arr[i] = 0;
  for (size_t i = 0; i < size; i++) {
    arr[i] = vet[i];
      for (size_t j = 0; j < size; j++) {
        if (arr[j] > arr[j/2] && arr[j/2] !=0 && arr[j]!=0 && arr[j] < 5000){
          int aux = arr[j/2];
          arr[j/2] = arr[j];
          arr[j] = aux;
        }
      }
      for (size_t i = 0; i < size; i++) printf("%d ", arr[i]);
      printf("\n\n");
    }
        for (size_t i = 0; i < size; i++) vet[i] = arr[i];
}

int ismaxheap(int *arr){
  for (size_t j = 0; j < size; j++) {
    if (arr[j] > arr[j/2] && arr[j/2] !=0 && arr[j]!=0 && arr[j] < 5000){
      return 0;
    }
  }
  return 1;
}

void del(int *vet, int n){
  for (size_t i = 0; i < size; i++)
    if(vet[i] == n) {vet[i] = 0;n = i;}

  for (size_t i = n; i < size; i++) vet[i] = vet[i+1];
  vet[size-1] = 0;
  for (size_t i = n; i < size; i++) printf("%d ", vet[i]);
  buildmaxheap(vet);
  return;
}

int main(){
  int arr[size] = {5, 3, 17, 10, 85, 2, 19, 6, 22, 4};
  int arr1[size] = {5, 3, 17, 10, 85, 2, 19, 6, 22, 4};
  buildmaxheap(arr);
  for (size_t i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  del(arr, 85);
  for (size_t i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}
