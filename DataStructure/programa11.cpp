#include <stdio.h>
#include <stdlib.h>
#include "filaCircular.h"

Fila *intercala_fila (Fila *f1, Fila *f2){
	Fila *aux1=fila_cria();
	Fila *aux2=fila_cria();
	Fila *f=fila_cria();
	float v;
	
	while(!fila_vazia(f1) or !fila_vazia(f2)){
		if(!fila_vazia(f1))
			fila_insere(aux1,fila_retira(f1));
		
		if(!fila_vazia(f2))
			fila_insere(aux2,fila_retira(f2));
	}
	
	while(!fila_vazia(aux1) or !fila_vazia(aux2)){
		if(!fila_vazia(aux1)){
			v = fila_retira(aux1);
			fila_insere(f1,v);
			fila_insere(f,v);
		}
		
		if(!fila_vazia(aux2)){
			v = fila_retira(aux2);
			fila_insere(f2,v);
			fila_insere(f,v);
		}
	}
	
	fila_libera(aux1);
	fila_libera(aux2);
	
	return f;
}

int main(){
	Fila *f1=fila_cria();
	Fila *f2=fila_cria();
	
	fila_insere(f1,1);
	fila_insere(f1,2);
	fila_insere(f1,3);
	fila_insere(f1,4);
	fila_insere(f1,5);
	
	fila_insere(f2,6);
	fila_insere(f2,7);
	fila_insere(f2,8);
	fila_insere(f2,9);
	fila_insere(f2,10);
	
	mostra_fila(intercala_fila(f1,f2));
}
