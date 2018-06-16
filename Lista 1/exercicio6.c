#include <stdio.h>
#include <stdlib.h>
int n = 0;

int fibonacci (int arr[n]){
  int a = 0, b = 1, aux = 0;
  arr[0] = a;
  arr[1] = b;
  for (size_t i = 2; i < n; i++) {
    arr[i] = arr[i-1] + arr[i-2];
  }
}

int main(int argc, char const *argv[]) {
  int soma = 0;
  printf("Digite a quantidade de elementos: ");
  scanf("%d", &n);
  int vet[n];
  fibonacci(vet);
  printf("\nSequencia dos elementos de fibonacci:\n");
  for (size_t i = 0; i < n; i++) {
    printf("%d\n", vet[i]);
  }
  for (size_t i = 0; i < n; i++) {
    soma = soma + vet[i];
  }
  printf("\n\n");
  printf("A soma dos elementos de Fibonacci e de: %d\n\n", soma);
  return 0;
}
