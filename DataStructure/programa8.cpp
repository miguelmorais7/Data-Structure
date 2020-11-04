#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

float base(Pilha *pi){
	float v,base=0;;
	Pilha *aux=pilha_cria();
	
	while(!pilha_vazia(pi)){
		v=pilha_pop(pi);
		pilha_push(aux,v);
	}
	
	base = v;
	
	while(!pilha_vazia(aux)){
		v=pilha_pop(aux);
		pilha_push(pi,v);
	}
	pilha_libera(aux);
	
	return base;
}

int main(){
	Pilha *p1=pilha_cria();
	
	pilha_push(p1,10);
	pilha_push(p1,20);
	pilha_push(p1,30);
	pilha_push(p1,40);
	
	printf("Base da pilha = %.0f", base(p1));
}
