#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

typedef struct lista{
	int info;
	struct lista *prox;
}Lista;

Lista *lista_cria(){
	return NULL;
}

Lista *lista_insere(Lista *li, int dado){
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->info = dado;
	novo->prox = li;
	return novo;
}

void lista_exibe(Lista *li){
	Lista *aux;
	for(aux = li; aux!=NULL; aux=aux->prox){
		printf("%d\t", aux->info);
	}
	printf("\n");
}

//----------------------------------------------------

void buscalista (Lista *l, int valor){
	Lista *a;
	a = l;
	while(a!=NULL){
		if(a->info==valor){
			//return a;
			printf("Posição na lista: %i", a->info);
		}
		a = buscalista(l + 1, valor);
	}
	
}

main(){
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	Lista *lst = lista_cria();
	Lista *aux;
	int item, tam, valor;
	
	printf("Digite a quantidade de valores na lista: ");
	scanf("%i", &tam);
	
	for(int i=0; i<tam; i++){
		item = rand()% 50+1;
		lst = lista_insere(lst, item);
	}
	lista_exibe(lst);
	
	printf("\nDigite o valor a ser buscado no vetor: ");
	scanf("%i", &valor);
	buscalista(lst, valor);
	
}
