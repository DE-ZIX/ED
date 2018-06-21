#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TMAX 21

int main(int argc, char const *argv[]) {
  char op ='n';
  char v[TMAX];
  char r[TMAX];
  char proc, test;
  int l = strlen(v);
  while (op == 'n' || op == 'N') {
    int opt = 0, quantidade = 0, pos = 0, vaz = 0, dif = 0;
    printf("Digite a opcao desejada: \n\n1- Para Escrever o vetor\n2- Para apagar um elemento\n3- Para imprimir a lista invertida\n4- Para encontrar a ultima posicao de certo elemento\n5- Contar quantos elementos vazios existem\n6- Contar a quantidade de certo elemento na lista\n7- Para sair do programa\n\nSua opcao: ");
    scanf("%d", &opt);
    switch (opt) {
      case 1:
        for (size_t i = 0; i < TMAX; i++) {
          v[i] = '\0';
        }
        printf("\nDigite o conteudo:");
        //gets(v);
        scanf( "%[^\n]s",&v);
        getchar();
        //scanf("%[^\n]%*c", v);
        printf("\n\n");
        for (size_t i = 0; i < TMAX; i++) {
          if (v[i]==' ')
            v[i]=='\0';
        }
      break;
      case 2:
      break;
      case 3:
        l = strlen(v);
        for(size_t i = 0; i < l; i++) {
          r[i] = v[l - 1 - i];
        }
      printf("\n\nConteudo invertido: %s", r);
      printf("\n\n");
      break;
      case 4:
      pos = -1;
        printf("Digite o elemento desejado: ");
        scanf(" %c", &proc);
        getchar();
        for (size_t i = 0; i < TMAX; i++) {
          if (v[i] == proc) {
            pos = i;
          }
        }
        if (pos < 0)
          printf("\n\nElemento nao encontrado.\n\n");
        else
          printf("\n\nA ultima posicao deste elemento e: %d\n\n", pos);
      break;
      case 5:
      vaz = 0;
        for (size_t i = 0; i < TMAX; i++) {
          if (v[i] != '\0' && v[i] != ' ')
            dif=i;
        }
        printf("%d", dif);
        //v[1]=' ';
        test=v[1];
        printf("%c", test);
        for (size_t i = 0; i < TMAX; i++) {
          if (v[i] == '\0' || v[i] == ' ' || v[i]==test)
            vaz++;
        }
      printf("A quantidade de elementos vazios e de: %d\n\n", vaz);
      break;
      case 6:
        printf("\n\nDigite o elemento desejado: ");
        scanf(" %c", &proc);
        getchar();
        quantidade = 0;
        for (size_t i = 0; i < TMAX; i++) {
          if (v[i] == proc) {
            quantidade++;
          }
        }
        printf("\n\nA quantidade deste elemento na lista e de: %d\n\n", quantidade);
      break;
      case 7:
      break;
      case 8:
      printf("%s\n", v);
      default:
        printf("Opcao invalida, por favor, digite o numero novamente\n\n");
      break;
    }
      printf("Deseja sair do programa? Digite N para fazer outra opercao ou S para sair: ");
      scanf(" %c", &op);
      getchar();
      printf("\n\n");
    if (op != 'N' && op != 'n' && op != 'S' && op != 's') {
      int error = 1;
      while (error == 1) {
        printf("\n\nOpcao invalida, por favor, digite a opcao novamente: ");
        scanf(" %c", &op);
        getchar();
        if (op == 'N' || op == 'n' || op == 'S' || op == 's')
          error = 0;
      }
    }

  }
  return 0;
}
