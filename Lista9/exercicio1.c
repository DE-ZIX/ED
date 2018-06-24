#include <stdio.h>
#include <stdlib.h>

#define m 4

typedef struct pag {
  int n;
  int vet[m];
  struct pag *filho[m];
  struct pag *pai;
}pag;

pag* novapag(int n, pag* pai){
  pag* p = (pag*)malloc(sizeof(pag));
  p->vet[0] = n;
  p->n = 1;
  p->filho[0] = NULL;
  p->pai = pai;
  return p;
}

void ordenar(int *vet){
  int x=vet[0], j=0;
  int y = 15;
  int arr[y];
  for (size_t i = 0; i < y; i++) arr[i]=0;
  for (size_t k = 0; k < y; k++) {
    for (size_t i = 0; i < y; i++) {
      if (x > vet[i] && vet[i]!=0){
        x=vet[i];
        j=i;
      }
    }
    arr[k] = vet[j];
    vet[j] = 0;
    x=1000;
  }
  for (size_t i = 0; i < 15; i++) vet[i] = arr[i];
  return;
}

int buscabin(int* v, int min, int max, int x) {
  if (max == min) return min;
  int meio = (max-min)/2;
  if (v[meio] == x) return meio;
  if (v[meio] < x) return buscabin(v, meio+1, max, x);
  if (v[meio] > x) return buscabin(v, min, meio-1, x);
}

int min(pag* pag){
  if(pag->filho[0] != NULL) return min(pag->filho[0]);
  else return pag->vet[0];
}

pag* busca(pag* p, int n){
  if(p==NULL){return NULL;}
  else{
    int pos = buscabin(p->vet, 0, p->n-1, n);
    if (n == p->vet[pos]) {
      return p;
    }
    if (n < p->vet[pos]) return busca(p->filho[pos], n);
    if (n > p->vet[pos]) return busca(p->filho[pos+1], n);
  }
}

pag* split(pag* p){
  int e[m], d[m], j=0;
  for (size_t i = 0; i < m/2; i++) e[i] = p->vet[i];
  for (size_t i = m/2+1; i < m; i++) {d[j] = p->vet[i];j++;}
  p->filho[0] = novapag(e[0], p);
  p->filho[1] = novapag(d[0], p);
  p->vet[0] = p->vet[m/2];
  for (size_t i = 1; i < m; i++)p->vet[i] = 0;
  for (size_t i = 1; i < m; i++){p->filho[0]->vet[i] = e[i];p->filho[1]->vet[i] = d[i];}
  return p;
}

void insere(pag* p3, int n){
  pag* p5 = busca(p3, n);
  int j;
  if(p5->n == 4) {
    p5->vet[p5->n+1] = n;
    p5->n = p5->n+1;
    ordenar(p5->vet);
    p5 = split(p5);
  }
  else if(p5->n+1 == 4 && p5->pai){
    int j;
    p5=split(p5);
    pag* p1 = p5->pai;

    p1->vet[p1->n] = p5->vet[0];
    p1->n = (p1->n)+1;

    for (size_t i = 0; i < m; i++) if (p1->vet[i] < p1->vet[p1->n-1]) j=i;

    int aux = p1->vet[j];
    p1->vet[j] = p1->vet[p1->n-1];
    p1->vet[p1->n-1] = aux;

    p1->filho[(p1->n)-1] = p1->filho[j];
    p1->filho[(p1->n)] = p1->filho[j+1];
    p1->filho[j] = p5->filho[0];
    p1->filho[j+1] = p5->filho[1];
  }

  else if(p5->n+1 < m){
    p5->vet[p5->n] == n;
    p5->n = (p5->n)+1;
    ordenar(p5->vet);
    return;
  }

}

int main(int argc, char const *argv[]) {
  pag* raiz = novapag(25, NULL);
  insere(raiz, 8);
  insere(raiz, 3);
  printf("%d\n", min(raiz));
  return 0;
}
