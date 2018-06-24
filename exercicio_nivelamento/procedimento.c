#include<stdio.h>
#include<stdlib.h>
//Código por Giovani Henriques - ED para SI(2018.1) Prof. Cristina Boeres

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
