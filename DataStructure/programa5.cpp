#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void empilhaPilha(Pilha *p1, Pilha *p2){
	Pilha *aux=pilha_cria();
	float v;
	
	while(!pilha_vazia(p2)){
		pilha_push(aux,pilha_pop(p2));
	}
	
	while(!pilha_vazia(aux)){
		v=pilha_pop(aux);
		pilha_push(p1,v);
		pilha_push(p2,v);
	}
	
	pilha_libera(aux);
	
	mostra_pilha(p1);
}

int main(){
	Pilha *p1=pilha_cria();
	Pilha *p2=pilha_cria();
	
	pilha_push(p1,1);
	pilha_push(p1,2);
	pilha_push(p1,3);
	pilha_push(p1,4);
	
	pilha_push(p2,10);
	pilha_push(p2,20);
	pilha_push(p2,30);
	
	empilhaPilha(p1,p2);
}
