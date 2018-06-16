#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n = 0, aux = 0;
  printf("Digite a quantidade de elementos: ");
  scanf("%d", &n);
  int vet[n];
  for (size_t i = 0; i < n; i++) {
    printf("Digite o elemento %d:", i+1);
    scanf("%d", &vet[i]);
  }
  printf("\n\n");
  for (size_t i = 0; i < n/2; ++i) {
    aux = vet[i];
    vet[i] = vet[n-1-i];
    vet[n-1-i] = aux;
  }
  for (size_t i = 0; i < n; i++) {
    printf("Novo elemento %d:%d\n",i+1, vet[i]);
  }

  return 0;
}
