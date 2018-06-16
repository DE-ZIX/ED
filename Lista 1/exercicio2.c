#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(int argc, char const *argv[]) {

  setlocale(LC_ALL, "");
  if ((setlocale(LC_ALL, "")) == NULL)
    printf("Não foi possível usar o setlocale\n");
  else
    printf("funcionou\n\n");
  printf("Língua do sistema é: %s\n\n", setlocale(LC_ALL, ""));
  int error = 1;
  float value = 0;
  char cin = '0', cout = '0';
  printf("Digite o tipo de temperatura de entrada (C para Celsius e F para Fahrenheit): \n\n");

  while (error == 1) {
    scanf("%c", &cin);
    printf("\n\n");
    if (cin != 'f' && cin != 'F' && cin != 'c' && cin != 'C') {
      error = 1;
      printf("Opção inválida, por favor, digite a opção corretamente: \n\n");
    }
    else{
      printf("Digite o valor da temperatura a ser convertida: \n\n");
      scanf("%f", &value);
      printf("\n\n");
      if(cin == 'c' || cin == 'C'){
        cout = 'F';
        cin = 'C';
        value = value * 1.8 + 32;
        error = 0;
      }
      if (cin == 'f' || cin == 'F') {
        cout = 'C';
        cin = 'F';
        value = (value - 32) / 1.8;
        error = 0;
      }
    }
  }
  printf("O valor convertido em %c é de: \n\n%.1f%c\n\n", cin, value, cout);
  return 0;
}
