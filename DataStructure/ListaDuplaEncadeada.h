#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//lista duplamente encadeada
typedef struct lista{
	int num;
	struct lista *ant;//***
	struct lista *prox;
}Lista;//lista dupla

Lista *lista_cria(){
	return NULL;
}
Lista *lista_insere(Lista *l, int valor){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=valor;
	novo->prox=l;
	novo->ant=NULL;//**
	if(l!=NULL) //** não é o primeiro
	   l->ant=novo;//**
	return novo;
}
//Opcionalmente pode-se inserir na lista de forma ordenada
Lista* lista_insere_ordenado(Lista* l, int v){
    Lista* novo;
    Lista* anterior=NULL;
    Lista* p=l;
    
    //cria novo elemento
    novo=(Lista*)malloc(sizeof(Lista));
    novo->num=v;
            
    //procura posição de inserção
    while (p!=NULL && p->num < v)  {
          anterior=p;
          p=p->prox;
    }     
    //encadeia o elemento
    if(anterior==NULL) {//insere no inicio
	     if(l!=NULL) l->ant=novo;
         novo->prox=l;
         novo->ant=NULL;
	     l=novo;
    }      
    else  {//insere no meio ou no fim da lista
            novo->prox=anterior->prox;
            novo->ant=anterior;
            if (anterior->prox!=NULL)
                 anterior->prox->ant=novo;
            anterior->prox=novo;
           }
   return l;
} 

void lista_exibe(Lista *l){
	Lista *aux;
	if(l==NULL) 
	   printf("Lista vazia");
	else{
	    printf("\nLista\n");
	  	for(aux=l;aux!=NULL;aux=aux->prox){
	    	printf("%d\t",aux->num);
	    }
	}
	printf("\n");
}
void lista_reversa(Lista *l){
	if(l==NULL)
	   printf("\nLista vazia\n");
	else{
	    printf("\nLista reversa\n");
		Lista *a;
		//procura o ultimo (elemento com prox=NULL)
		for(a=l;a->prox!=NULL;a=a->prox);
		//percorre no sentido inverso 
		while(a!=NULL){
			printf("%d\t",a->num);
			a=a->ant;
		} 	  	
	}
	printf("\n");
}
/* retorna 1 se vazia ou zero se falso*/
int lista_vazia(Lista* l){     
    return (l==NULL);//retorna o resultado da comparação
}
Lista *buscalista(Lista *l,int valor){
	Lista *a;//ponteiro auxiliar
	a=l;
	while(a!=NULL){
		if(a->num==valor)
		    return a;	
		a=a->prox;
	}
	return NULL;
}
void lista_libera(Lista *l){
     Lista *p,*t;
     p=l;
     while(p!=NULL){
       t=p->prox;
       free(p);//libera um item por vez
       p=t;
     } 
} 
/* retorna o novo inicio ou a lista original*/
Lista* lista_retira(Lista* l, int valor){
      //procura o elemento na lista usando a função busca
      Lista* aux=buscalista(l, valor);
      if (aux==NULL) //não achou o elemento
          return l; 
      //retira o elemento encadeado
      if(l==aux) //verifica se é o primeiro da lista
        l=aux->prox;
      else
        aux->ant->prox=aux->prox;
      //testa para ver se é o ultimo da lista
      if (aux->prox!=NULL)        
          aux->prox->ant=aux->ant;
      free(aux);
      return l;
}
int contaElementos(Lista *l){
	int conta=0;
	Lista *a;
	for(a=l;a!=NULL;a=a->prox)
	   conta++;
	return conta;
}
Lista *insere_sem_repetir(Lista *l, int valor){
	Lista *aux=buscalista(l,valor);
	if(aux==NULL)//pode inserir
	  l=lista_insere_ordenado(l,valor);
	else
	  printf("Item repetido\n");
	return l;
}
void vizinhos(Lista *item){
	
	if(item -> ant == NULL )		
		printf("\nNao tem anterior\n");
	else
	    printf("Anterior: %d\n",item->ant->num);

	if(item -> prox == NULL)				
		printf("\nNao tem proximo\n");		
	else
		printf("Proximo: %d\n",item->prox->num);	
}

