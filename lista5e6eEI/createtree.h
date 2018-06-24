#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>


#define size 20

struct no{
	int info, nvl, prof;
	char op;
	struct no* e;
	struct no* d;
};

			/*stack stores the operand nos of the tree*/
struct no *stack[size];

int top;

struct no *create(char exp[])

{

struct no *temp;

int pos;

char ch;


void push(struct no*);

struct no *pop();

pos=0;

ch=exp[pos];

while(ch!='\0')

{
			/*create new no*/

temp=((struct no*)malloc(sizeof(struct no)));

temp->e=temp->d=NULL;

temp->op=ch;

if(isalpha(ch))

push(temp);

else if(ch=='+' ||ch=='-' || ch=='*' || ch=='/')

{ temp->d=pop();

temp->e=pop();

push(temp);

}
 else

printf("\n Invalid char Expression\n");

pos++;

ch=exp[pos];

}

 temp=pop();

return(temp);

}

void push(struct no *no)

{

if(top+1

>=size)

printf("Error:Stack is full\n");

top++;

stack[top]=no;

}

struct no* pop()

{

struct no *no;

if(top==-1)

printf("\nerror: stack is empty..\n");

no =stack[top];

top--;

return(no);

}


/* functions for tree traversal*/

void inorder(struct no *root)


{

struct no *temp;

temp=root;

if(temp!=NULL)

{ inorder(temp->e);

printf("%c",temp->op);

inorder(temp->d);

}}

void preorder(struct no *root)

{

struct no *temp;

temp=root;

if(temp!=NULL)

{

printf("%c",temp->op);

preorder(temp->e);

preorder(temp->d);

}}

void postorder(struct no *root)

{

struct no *temp;

temp=root;

if(temp!=NULL)

{
postorder(temp->e);

postorder(temp->d);

printf("%c",temp->op);

}}
