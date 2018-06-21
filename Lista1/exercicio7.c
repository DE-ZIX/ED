#include <stdio.h>
#include <stdlib.h>

int check = 0;

int igual (char s1, char s2){
  if (s1 == s2){
    return 1;
  }
  else{
    return 0;
  }

}

int main(int argc, char const *argv[]) {
  char c1 = '0', c2 = '0';
  printf("Digite o char1: ");
  scanf("%c", &c1);
  getchar();
  printf("Digite o char2: ");
  scanf("%c", &c2);
  getchar();
  check = igual(c1, c2);
  if (check == 1)
    printf("\n\nOs caracteres sao iguais.\n\n");
  else
    printf("\n\nOs caracteres nao sao iguais.\n\n");
  return 0;
}
