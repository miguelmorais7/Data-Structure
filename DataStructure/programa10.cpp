#include <stdio.h>
#include <stdlib.h>
#include "filaComp.h"

int primeiroDaFila (Fila *f){
	Fila *aux=fila_cria();
	float v;
	
	while(!fila_vazia(f))
		fila_insere(aux,fila_retira(f));
		
	v = fila_retira(aux);
	fila_insere(f,v);
	
	while(!fila_vazia(aux))
		fila_insere(f,fila_retira(aux));
	
	fila_libera(aux);
	
	return (int)v;
}

int main(){
	Fila *f1=fila_cria();
	
	fila_insere(f1,1);
	fila_insere(f1,2);
	fila_insere(f1,3);
	fila_insere(f1,4);
	fila_insere(f1,5);
	
	printf("Primeiro valor da fila = %d", primeiroDaFila(f1));
}
