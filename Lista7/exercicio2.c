#include <stdio.h>
#include <stdlib.h>

#define size 10


void buildminheap(int *vet){
  int arr[size];
  for (size_t i = 0; i < size; i++) {
    arr[i] = vet[i];
      for (size_t j = 0; j < size; j++) {
        if (arr[j] < arr[j/2] && arr[j/2] !=0 && arr[j]!=0){
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

int main(){
  int arr[size] = {5, 3, 17, 10, 85, 2, 19, 6, 22, 4};
  buildminheap(arr);
  for (size_t i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}
