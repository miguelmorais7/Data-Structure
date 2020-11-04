#include <stdio.h>
#include <stdlib.h>
#include "listaSimples.h"

Lista * lista_impares(Lista *L1){
	Lista *aux=L1;
	Lista *a=lista_cria();
	
    while(aux != NULL){
    	if(aux->info % 2 == 1)
    		a = lista_insere(a, aux->info);
        aux=aux->prox;
	}
	
	return a;
}

int somaNumeros (Lista *L){
	Lista *aux=L;// ponteiro para percorrer a lista
	int a = 0; 
    
    while(aux != NULL){
    	a += aux->info;
        aux=aux->prox;
	}
	
	return a;
}

int menorNumero (Lista *Li){
	Lista *aux=Li;// ponteiro para percorrer a lista
	int a = aux->info; 
	
    while(aux != NULL){
    	if(aux->info < a)
    		a = aux->info;
        aux=aux->prox;
	}
	
	return a;
}

int main(){
	Lista *lst = lista_cria();
	
	lst = lista_insere(lst, 10);
	lst = lista_insere(lst, 21);
	lst = lista_insere(lst, 30);
	lst = lista_insere(lst, 41);
	lst = lista_insere(lst, 51);
	
	printf("Soma = %d\n", somaNumeros(lst));
	printf("Menor numero = %d\n", menorNumero(lst));
	Lista *a = lista_impares(lst);
	lista_mostra(a);
}
