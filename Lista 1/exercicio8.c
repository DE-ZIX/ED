#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_OF_CHARS 256

/* Returns an array of size 256 containg count
   of characters in the passed char array */
int *getCharCountArray(char *str){
   int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
   int i;
   for (i = 0; *(str+i);  i++)
      count[*(str+i)]++;
   return count;
}

/* removeDirtyChars takes two string as arguments: First
string (str)  is the one from where function removes dirty
characters. Second  string is the string which contain all
dirty characters which need to be removed  from first string */
char *removeDirtyChars(char *str, char *mask_str){
  int *count  = getCharCountArray(mask_str);
  int ip_ind  = 0, res_ind = 0;
  while (*(str + ip_ind))
  {
    char temp = *(str + ip_ind);
    if (count[temp] == 0)
    {
        *(str + res_ind) = *(str + ip_ind);
        res_ind++;
    }
    ip_ind++;
  }

  /* After above step string is ngring.
    Removing extra "iittg" after string*/
  *(str+res_ind) = '\0';

  return str;
}

/*removes duplicates in a string, useful when using
"removeDirtyChars" function as input parameter, so the End
result will only be the characters that do not contain in The
first string, without duplicates*/
/*char *removeequals(char *c){
  for (size_t i = 0; i < 1000; i++) {
    for (size_t j = 0; j < 1000; j++) {
      if (c[i] == c[j] && j != i) {
        if (i<j)
          c[j]='\0';
        if (j<i)
          c[i]='\0';
      }
    }
  }
  return c;
}*/

char *removeDuplicate(char str[], int n)
{
   // Used as index in the modified string
   int index = 0;

   // Traverse through all characters
   for (int i=0; i<n; i++) {

     // Check if str[i] is present before it
     int j;
     for (j=0; j<i; j++)
        if (str[i] == str[j])
           break;

     // If not present, then add it to
     // result.
     if (j == i)
        str[index++] = str[i];
   }

   return str;
}

//main function
int main(int argc, char const *argv[]) {
  char c1[1000], c2[1000];
  int j = 0, h = 0, k = 0;
  printf("Digite a primeira palavra ou frase: ");
  fgets(c1,1000,stdin);
  printf("Digite a segunda palavra ou frase: ");
  fgets(c2,1000,stdin);
  printf("%s\n", removeDuplicate(removeDirtyChars(c1,c2), 256));
  
  return 0;
}
