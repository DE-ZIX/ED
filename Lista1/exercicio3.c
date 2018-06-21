#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charcount = 0;
char c[1000]="0";

int contaLetra(char *s){
  for (size_t i = 0; i < s[i]; i++) {
    if (s[i] != ' ') {
      charcount++;
    }
  }
  return charcount;
}

int main(int argc, char const *argv[]) {
  printf("Digite a frase ou palavra: ");
  //scanf("%s", &c);
  fgets(c,1000,stdin);
  printf("\n\n");
  printf("%s\n\n", c);
  contaLetra(c);
  printf("A quantidade de letras e: %d", charcount);
  printf("\n\n");
  return 0;
}
