#include <stdio.h>
#include <stdlib.h>
#include "filaComp.h"

void concatena_fila (Fila *f1, Fila *f2){
	Fila *aux=fila_cria();
	float v;
	
	while(!fila_vazia(f2))
		fila_insere(aux,fila_retira(f2));
	
	while(!fila_vazia(aux)){
		v = fila_retira(aux);
		fila_insere(f1,v);
		fila_insere(f2,v);
	}
	
	fila_libera(aux);
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
	
	concatena_fila(f1,f2);
	
	mostra_fila(f1);
}
