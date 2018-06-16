#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n=0, resp=0;
  printf("Digite a quantidade de elementos: ");
  scanf("%d", &n);
  printf("\n\n");
  int vet[n];
  for (size_t i = 0; i < n; i++) {
    printf("Digite o elemento %d: ", i+1);
    scanf("%d", &vet[i]);
    if (vet[i]<0) {
      resp++;
    }
  }
  printf("\n\nA quantidade de elementos negativos e de: %d\n\n", resp);
  return 0;
}
