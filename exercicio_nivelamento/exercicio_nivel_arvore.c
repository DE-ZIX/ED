#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int info;
  int altura;
  struct no *esq;
  struct no *dir;
}no;

no *head;
no *pt;

int posordem (no *pt2){
  int alt1, alt2;
  if (pt2 == NULL)
    pt2 -> altura = -1;
  else{
    alt1 = posordem(pt2 -> esq);
    alt2 = posordem(pt2 -> dir);
    if (alt1 > alt2)
      pt2 -> altura = alt1+1;
    else
      pt2 -> altura = alt2+1;
    }
}

void exibirEmOrdem(no *pRaiz){
    if(pRaiz != NULL){
        exibirEmOrdem(pRaiz->esq);
        exibirEmOrdem(pRaiz->dir);
        printf("\n%i", pRaiz->info);
    }
}

void criarArvore(no **pRaiz){
    *pRaiz = NULL;
    head = *pRaiz;
}

void insercao(no **Raiz, int numero){
	if (*Raiz==NULL){
	*Raiz=(no *)malloc(sizeof (no));
	(*Raiz)->esq=NULL;
	(*Raiz)->dir=NULL;
	(*Raiz)->info=numero;
	}else {
		if (numero<((*Raiz)->info)){
			insercao(&((*Raiz)->esq), numero);
      head = *Raiz;
		}else{
			insercao(&((*Raiz)->dir), numero);
      head = *Raiz;
		}
	}
}



int main(int argc, char const *argv[]) {
  criarArvore(&head);
  int n, aux=0;
  printf("Digite a quantidade de numeros a inserir: ");
  scanf("%d", &n);
  printf("\n\n");
  for (size_t i = 0; i < n; i++) {
    //printf("Digite o %d elemento: ", i+1);
    //scanf("%d", &aux);
    //printf("\n\n");
    aux++;
    insercao(&head,aux);
  }
  printf("%i", head);
  pt = head;
  //posordem(pt);
  exibirEmOrdem(head);

  return 0;
}
