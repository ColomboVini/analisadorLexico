#include <stdio.h>
#include "analex.h"
#include "pilha.h"

int token;

void reconhece(int t);
void E();
void E_linha();
void T();
void T_linha();
void F();
void erro();


void main(){
	token = analex();
	E();
	if(token==';'){
		printf("O Resultado esta Sintaticamente Correto\n Resultato = %d \n", pop());
	}	
	else erro();
}

void reconhece(int t){
	if(t==token){
		token=analex();
	}
	else erro();
}

void erro(){
	printf("\nEncontrou um erro\n\n");
}

void F(){
	if(token==NUM){
		printf("%d ", tokenval);
		push(tokenval);
		reconhece(NUM);
	}	
	else if(token=='('){
		reconhece('(');
		E();
		reconhece(')');
	}
}

void E(){
	T();
	E_linha();
}

void E_linha(){
	switch(token){
		case '+':
			reconhece('+');
			T();
			E_linha();
			printf("+ \n");
			a = pop();
			b = pop();
			push(a + b);
			break;
		case '-':
			reconhece('-');
			T();
			E_linha();
			printf("- \n");
			a = pop();
			b = pop();
			push(b - a);
			break;
	}

   
}
void T_linha(){
	switch(token){
		case '*':
			reconhece('*');
			F();
			T_linha();
			printf("* \n");
			a = pop();
			b = pop();
			push(a * b);
			break;
		case '/':
			reconhece('/');
			F();
			T_linha();
			printf("/ \n");
			a = pop();
			b = pop();
			push(b / a);
			break;
	}
}
void T(){
	F();
	T_linha();
}
