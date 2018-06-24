#include<stdio.h>
#include<stdlib.h>

//Código por Giovani Henriques - ED para SI(2018.1) Prof. Cristina Boeres

//Estrutura da árvore binária
struct no{
	int info, nvl;
	struct no* e;
	struct no* d;
};

struct no* novono(int info);

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
//Função para criar novo nó dados a informação e dois ponteiros para esquerda e direita com valor NULL
struct no* novono(int info) {
	struct no* no = (struct no*)
	malloc(sizeof(struct no));
	no->info = info;
	no->e = NULL;
	no->d = NULL;
	return no;
}


//Função para imprimir em pré-ordem (visita, e, d)
void pre(struct no* no) {
	if (no == NULL) return;
	printf("%d(%d) ", no->info, no->nvl);
	pre(no->e);
	pre(no->d);
}

//Função para imprimir em ordem (e, visita, d)
void em(struct no * n){
	if(n->e) em(n->e);
	printf("%d(%d) ", n->info, n->nvl);
	if(n->d) em(n->d);
}
//Função para imprimir em pós-ordem (e, d, visita)
void pos(struct no * n){
	if(n->e) pos(n->e);
	if(n->d) pos(n->d);
	printf("%d(%d) ", n->info, n->nvl);
}
//Função recursiva para determinar o nível de um nó na árvore
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

//Função main
int main()
{
  //árvore de teste
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int n = sizeof(arr)/sizeof(arr[0]);

	//impressão dos dados
	struct no *raiz = arrarv(arr, 0, n-1);
  nivelamento(raiz);//atribuição dos níveis as folhas
	printf("Pre-ordem (nivel do elemento entre parenteses): ");
	pre(raiz);
  printf("\n");
  printf("\nEm ordem (nivel do elemento entre parenteses): ");
	em(raiz);
	printf("\n\nPos ordem (nivel do elemento entre parenteses): ");
	pos(raiz);
  printf("\n");
	return 0;
}

//Código por Giovani Henriques - ED para SI(2018.1) Prof.
