#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TMAX 256
#define t 5

int p[TMAX];
int topo=0;

int empilha(int value){
  p[topo] = value;
  topo++;
}

int desempilha(){
  p[topo-1] = NULL;
  topo--;
  return 0;
}

int main(int argc, char const *argv[]) {
  int op1, n, stack=0, aux;
  char op='s';
  while (op == 's' || op == 'S'){
    printf("Digite a opcao desejada:\n\n1- Para escrever no vetor\n2- Para desempilhar\n3- Para imprimir o vetor\n\nSua opcao: ");
    scanf("%d", &op1);
    switch (op1) {
      case 1:
        printf("\nDigite a quantidade de elementos que deseja escrever: ");
        scanf("%d", &n);
        printf("\n");
        if((n+stack)>t)printf("Quantidade acima do permitido.\n\n");
        else{
          for (size_t i = 0; i < n; i++) {
            printf("Digite o elemento %d: ", stack+1);
            scanf("%d", &aux);
            //scanf("%d\n", p[stack]);
            empilha(aux);
            stack++;
          }
          printf("\n\n");
        }
      break;
      case 2:
        printf("\nDigite a quantidade de elementos que deseja desempilhar: ");
        scanf("%d", &n);
        if(n>t) for (size_t i = 0; i < stack; i++) desempilha();
        else
          for (size_t i = 0; i < n; i++) desempilha();
      printf("\n");
      break;
      case 3:
        printf("\nVetor: ");
        for (size_t i = 0; i < topo; i++) printf("%d ", p[i]);
        printf("\n\n");
      break;
    }

    printf("Deseja continuar? Digite S para sim e N para nao: ");
    scanf(" %c", &op);
    if (op!='s'&&op!='S'&&op!='n'&&op!='N'){
      op='s';
      printf("\nOpcao invalida.\n");
    }

    printf("\n");
  }
  return 0;
}
