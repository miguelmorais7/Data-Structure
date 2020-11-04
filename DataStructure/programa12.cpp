#include <stdio.h>
#include <stdlib.h>
#include "filaComp.h"

void  mostraImpares (Fila *f){
	Fila *aux=fila_cria();
	int v;
	
	while(!fila_vazia(f))
		fila_insere(aux,fila_retira(f));
		
	printf("Numeros Impares\n");
	
	while(!fila_vazia(aux)){
		v = fila_retira(aux);
		if (v % 2 == 1)
			printf("%d\n", v);
		fila_insere(f,v);
	}
	
	fila_libera(aux);
}

int main(){
	Fila *f1=fila_cria();
	
	fila_insere(f1,1);
	fila_insere(f1,2);
	fila_insere(f1,5);
	fila_insere(f1,4);
	fila_insere(f1,5);
	
	mostraImpares(f1);
}
