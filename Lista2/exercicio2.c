#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int topo=0, n=0;
char st[100] = "ESTE EXERCICIO E MUITO FACIL";

int empilha(char n){
  st[topo] = n;
  topo++;
}

int desempilha(){
  st[topo-1] = '\0';
  topo--;
}

int mov(int top){
  int count = top;
  for (size_t i = 0; i < count; i++) {
    st[top+1] = st[i];
    st[i] = '\0';
    top++;
  }
}

int conta(){
  n=0;
  while(st[n] !='\0') n++;
  return n;
}

char invert(){
  int x, y;
  y = conta();
  mov(y);
  x = y * 2;
  for (size_t i = 0; i < y; i++) {
    empilha(st[x]);
    x--;
  }
}

int main(int argc, char const *argv[]) {
  printf("Input: %s\n\n", st);
  invert();
  printf("Output: %s\n", st);
  return 0;
}
