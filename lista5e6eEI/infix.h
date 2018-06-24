#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack type
struct Stack{
    int intop;
    unsigned capacity;
    int* array;
};

// Stack Operations
struct Stack* createStack( unsigned capacity ){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->intop = -1;
    stack->capacity = capacity;

    stack->array = (int*) malloc(stack->capacity * sizeof(int));

    if (!stack->array)
        return NULL;
    return stack;
}
int isEmpty(struct Stack* stack){
    return stack->intop == -1 ;
}
char peek(struct Stack* stack){
    return stack->array[stack->intop];
}
char inpop(struct Stack* stack){
    if (!isEmpty(stack))
        return stack->array[stack->intop--] ;
    return '$';
}
void inpush(struct Stack* stack, char op){
    stack->array[++stack->intop] = op;
}


// A utility function to check if the given character is operand
int isOperand(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int Prec(char ch){
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}


// The main function that converts given infix expression
// to postfix expression.
char infixtopostfix(char* expr){
    int i, k;

    // Create a stack of capacity equal to expression size
    struct Stack* stack = createStack(strlen(expr));
    if(!stack) // See if stack was created successfully
        return -1 ;

    for (i = 0, k = -1; expr[i]; ++i)
    {
        // If the scanned character is an operand, add it to output.
        if (isOperand(expr[i]))
            expr[++k] = expr[i];

        // If the scanned character is an ‘(‘, ininpush it to the stack.
        else if (expr[i] == '(')
            inpush(stack, expr[i]);

        // If the scanned character is an ‘)’, pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (expr[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                expr[++k] = inpop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; // invalid expression
            else
                inpop(stack);
        }
        else // an operator is encountered
        {
            while (!isEmpty(stack) && Prec(expr[i]) <= Prec(peek(stack)))
                expr[++k] = inpop(stack);
            inpush(stack, expr[i]);
        }

    }

    // pop all the operators from the stack
    while (!isEmpty(stack))
        expr[++k] = inpop(stack );

    expr[++k] = '\0';
    printf( "%s", expr );
}
