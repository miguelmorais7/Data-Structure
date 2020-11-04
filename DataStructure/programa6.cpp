#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* dividePilha(Pilha *p){
	Pilha *aux=pilha_cria();
	Pilha *p1=pilha_cria();
	float v;
	
	while(!pilha_vazia(p)){
		pilha_push(aux,pilha_pop(p));
	}
	
	while(!pilha_vazia(aux)){
		v = pilha_pop(aux);
		pilha_push(p,v);
		pilha_push(p1,v/2);
	}
	
	pilha_libera(aux);
	
	return p1;
}

int main(){
	Pilha *p1=pilha_cria();
	
	pilha_push(p1,10);
	pilha_push(p1,20);
	pilha_push(p1,30);
	pilha_push(p1,40);
	
	Pilha *p=dividePilha(p1);
	
	mostra_pilha(p);
}
