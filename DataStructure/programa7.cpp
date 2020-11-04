#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int contaMenores10 (Pilha *p){
	Pilha *aux=pilha_cria();
	float v;
	int soma = 0;
	
	while(!pilha_vazia(p)){
		pilha_push(aux,pilha_pop(p));
	}
	
	while(!pilha_vazia(aux)){
		v = pilha_pop(aux);
		pilha_push(p,v);
		if(v<10) soma += (int) v;
	}
	
	pilha_libera(aux);
	
	return soma;
}

int main(){
	Pilha *p1=pilha_cria();
	
	pilha_push(p1,1);
	pilha_push(p1,5);
	pilha_push(p1,10);
	pilha_push(p1,40);
	
	mostra_pilha(p1);
	printf("\nSoma=%d", contaMenores10(p1));
}
