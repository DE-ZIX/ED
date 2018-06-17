#include <stdio.h>
#include <stdlib.h>

/*Exercícios que faltam
Lista 5: 6
Lista 6: 4*/


//Estrutura da árvore binária (EI e2la)
struct no{
	int info, nvl, prof;
	char op;
	struct no* e;
	struct no* d;
};

//algoritmo que cria novo no
struct no* novono(int info) {
	struct no* no = (struct no*)
	malloc(sizeof(struct no));
	no->info = info;
	no->e = NULL;
	no->d = NULL;
	no->prof = 0;
	return no;
}

//Função que cria uma árvore balanceada dado um array ordenado
struct no* arrarv(int arr[], int ini, int fim) {
	//Caso base
	if (ini > fim)
	return NULL;
	//Recebe o valor do meio e o faz de raiz
	int meio = (ini + fim)/2;
	struct no *raiz = novono(arr[meio]);
	//Faz a construção da árvore e da subárvore a esquerda recursivamente e faz dela a filha da raiz
	raiz->e = arrarv(arr, ini, meio-1);
	//Faz a construção da árvore e da subárvore a direita recursivamente e faz dela a filha da raiz
	raiz->d = arrarv(arr, meio+1, fim);
	return raiz;
}

//Função de busca na árvore (EI e2lb)
struct no* busca(struct no* raiz, int n){
		if (raiz == NULL || raiz->info == n) return raiz;
		if (raiz->info < n) return busca(raiz->d, n);
		if (raiz->info > n) return busca(raiz->e, n);
	}

//Função para atribuir a profundidade a todos os nós (EIe2ld)
void profundidade(struct no *n){
	if(n->e) {n->e->prof = n->prof+1;profundidade(n->e);}
	if(n->d) {n->d->prof = n->prof+1;profundidade(n->d);}
	return;
}

//Função para retornar a altura da árvore
int ralt(struct no *n){
  if(n == NULL) return -1;
  int alte = ralt(n->e);
	int altd = ralt(n->d);
	if (alte > altd) return alte+1; else return altd+1;
}

//Função para retornar a proundidade de determinado nó (EIe2ld)
int rprof(struct no *raiz, int n){
	struct no* no = busca(raiz, n);
	n = no->prof;
	return n;
}

//Função recursiva para determinar o nível de um nó na árvore(L5e1)
void nivelamento (struct no *n){
  if (!n->e && !n->d) {   //Verifica se o nó é folha(não possui filhos), caso for o nível recebido é -1 e o procedimento termina
		n->nvl = -1;
		return;
	} //Caso não seje folha, o procedimento segue para os comandos abaixo
	if(n->e) nivelamento(n->e);  //Verifica recursivamente se possui um filho a esquerda, indo até o final da árvore na primeira execução
	if(n->d) nivelamento(n->d);  //Verifica recursivamente se possui um filho a direita, indo até o final da árvore na primeira execução
	if(n->e && n->d) { //Verificao caso de se o nó tem filhos em ambos os lados(2 filhos) e pega o nível daquele tem o maior nível e soma + 1
		if(n->e->nvl > n->d->nvl) n->nvl = n->e->nvl+1;//Basicamente: "Se o nível do filho da esquerda(n->e->nvl) é maior do que o do filho da direita(n->d->nvl), então o nível é igual ao do filho da esquerda + 1"
		else  n->nvl = n->d->nvl+1; //Caso a afirmação acima seje falsa, o nível será o do filho da direita + 1. Não é necessário criar um caso para se os níveis forem iguais pois não fará diferença de que filho iremos tomar.
	}
	else{ //Caso Tenha apenas 1 filho
		if(n->e) n->nvl = n->e->nvl + 1; //Verifica se é um filho da esquerda e atribui seu nível + 1
		else n->nvl = n->d->nvl + 1 ;//Verifica se é um filho da direita e atribui seu nível + 1
	}
}

//Função que imprimi os nós por nível(L5e2)
void impriminvl (struct no* n, int nvl){
	if (n->nvl == nvl) printf("%d ", n->info);
	if (n->e) impriminvl(n->e, nvl);
	if (n->d) impriminvl(n->d, nvl);
}
void printperlvl (struct no* no){
	int n = -1;
	while (n<=no->nvl) {impriminvl(no, n);n++;}
}

void troca(struct no *n){
}

//Função para inserir um nó na árvore (EI e2lb)
struct no* insere(struct no *no, int n){
  if (no == NULL) return novono(n);
  if (n < no->info)
      no->e  = insere(no->e, n);
  else if (n > no->info)
      no->d = insere(no->d, n);
  return no;
	profundidade(no);
	nivelamento(no);
}

//Função que retornar o menor valor da árvore (L6e1)
struct no* minvalue(struct no* no){
    while (no->e != NULL)
        no = no->e;
    return no;
}

//Função para remover um nó na árvore (EI e2lb)
struct no* remover(struct no* no, int n){
    // base case
    if (no == NULL) return no;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (n < no->info)
        no->e = remover(no->e, n);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (n > no->info)
        no->d = remover(no->d, n);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (no->e == NULL)
        {
            struct no *temp = no->d;
            free(no);
            return temp;
        }
        else if (no->d == NULL)
        {
            struct no *temp = no->e;
            free(no);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct no* temp = minvalue(no->d);

        // Copy the inorder successor's content to this node
        no->info = temp->info;

        // Delete the inorder successor
        no->d = remover(no->d, temp->info);
    }
    return no;
}

//Função que retornar o maior valor da árvore (L6e2)
struct no* maxvalue(struct no* no){
    while (no->d != NULL)
        no = no->d;
    return no;
}

//Função que retorna valor total de uma árvore artimética (L5e6)
int valtree (struct no *n){
  if(n->info == NULL || n->info == 0)
		if(n->op == '+') return valtree(n->e) + valtree(n->d);
		if(n->op == '*') return valtree(n->e) * valtree(n->d);
		if(n->op == '-') return valtree(n->e) - valtree(n->d);
		if(n->op == '/') return valtree(n->e) / valtree(n->d);
	else return n->info;
}

//Função que retorna o próximo nó com valor maior dado nó (L6e3)
struct no* next(struct no* no){
	if (no->d) {
		no = no->d;
		while (no->e) {
			no = no->e;
		}
		return no;
	}
	else return no;

}

//Função que retorna o próximovalor maior dado nó (L6e3)
int rnext(struct no* no){
	if (no->d) {
		no = no->d;
		while (no->e) {
			no = no->e;
		}
		return no->info;
	}
	else return no->info;
}

//Função que retorna o nó com valor imediatamente menor dado um nó (L6e5)
struct no* previous(struct no* no){
	if (no->e) {
		no = no->e;
		while (no->d) {
			no = no->d;
		}
		return no;
	}
	else return no;
}

//Função que encontra o nó com valor imediatamente menor dado um nó e o remove (L6e5)
struct no* removeprv(struct no* no){
	if (no->e) {
		no = no->e;
		while (no->d) {
			no = no->d;
		}
		remover(no, no->info);
	}
	else return no;
}

//Função que retorna o valor imediatamente menor dado um nó (L6e5)
int rprevious(struct no* no){
	if (no->e) {
		no = no->e;
		while (no->d) {
			no = no->d;
		}
		return no->info;
	}
	else return no->info;
}

//Função que retornar o número de nós da árvore(L5e3)
int h;
int contanos(struct no* n){
	if(n->e){h++;contanos(n->e);}
	if(n->d){h++;contanos(n->d);}
	return h;
}
int tam(struct no* no){
	if (h!=0) h=0;
	return contanos(no);
}

//Função para retornar o primeiro nó da pré-ordem (L5e5)
int fpre(struct no *n){
	if (n->prof == 0) return n->info;
}
//Função para retornar o primeiro nó de em ordem (L5e5)
int fem(struct no *n){
	if(n->e) return fem(n->e);
	if(!n->e) return n->info;
}
//Função para retornar o primeiro nó da pós-ordem (L5e5)
int fpos(struct no *n){
	if(n->e) return fpos(n->e);
	if(!n->e) return n->info;
}

//Função para imprimir em pré-ordem (visita, e, d)
void pre(struct no* no) {
	if (no == NULL) return;
	printf("%d ", no->info);
	pre(no->e);
	pre(no->d);
}
//Função para imprimir em ordem (e, visita, d)
void em(struct no * n){
	if(n->e) em(n->e);
	printf("%d ", n->info);
	if(n->d) em(n->d);
}
//Função para imprimir em pós-ordem (e, d, visita)
void pos(struct no * n){
	if(n->e) pos(n->e);
	if(n->d) pos(n->d);
	printf("%d ", n->info);
}

//Função que retornar o valor minimo e o máximo da árvore (L5e4)
void minmax(struct no *n,	int *a, int *b){
	struct no *min;
	struct no *max;
	min = n;
	max = n;
	while(min->e != NULL) min = min->e;
	while(max->d != NULL) max = max->d;
	*a=min->info;
	*b=max->info;
}

int main(int argc, char const *argv[]) {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	//int n = sizeof(arr)/sizeof(arr[0]);

	//Sequência de inserções e remoções solicitadas no (EIe2lc)
	struct no *raiz = novono(50);
	insere(raiz, 30);
	insere(raiz, 2);
	insere(raiz, 34);
	insere(raiz, 80);
	insere(raiz, 77);
	insere(raiz, 110);
	remover(raiz, 50);
	insere(raiz, 150);
	insere(raiz, 66);
	remover(raiz, 110);
	profundidade(raiz);
	nivelamento(raiz);
	//atribuição dos níveis as folhas
	pre(raiz);
	printf("\n\n");
	em(raiz);
	printf("\n\n");
	pos(raiz);
	printf("\n\n");
	printf("%d", fpre(raiz));
	printf("\n\n");
	printf("%d", fem(raiz));
	printf("\n\n");
	printf("%d", fpos(raiz));
	printf("\n\n");
	printperlvl(raiz);
	printf("\n\n");
  return 0;
}
