typedef struct lista {
    int info;
    struct lista *ant; 
    struct lista *prox;
} Lista; 
Lista * lista_cria() {
	return NULL;
}
Lista* lista_insere( Lista* li, int dado) {
	Lista *novo= (Lista*) malloc (sizeof(Lista));
    novo->info=dado;
    novo->prox=li;
    novo->ant=NULL;
    if( li!= NULL ) { //verifica se a lista não esta vazia
    	li->ant=novo;
	}
    return novo;
} 
Lista* lista_insere_ordenado(Lista* li, int v){
    Lista* novo;
    Lista* anterior=NULL;
    Lista* p=li;
    
    //cria novo elemento
    novo=(Lista*)malloc(sizeof(Lista));
    novo->info=v;
            
    //procura posição de inserção
    while (p!=NULL && p->info < v)  {
          anterior=p;
          p=p->prox;
    }     
    //encadeia o elemento
    if(anterior==NULL) {//insere no inicio
	     if(li!=NULL) li->ant=novo;
         novo->prox=li;
         novo->ant=NULL;
	     li=novo;
    }      
    else  {//insere no meio ou no fim da lista
            novo->prox=anterior->prox;
            novo->ant=anterior;
            if (anterior->prox!=NULL)
                 anterior->prox->ant=novo;
            anterior->prox=novo;
           }
   return li;
} 
int lista_vazia(Lista* li) {     
    return(li==NULL); 
}         
Lista* lista_busca(Lista* li, int dado) {     
	Lista *a; 
	for(a=li;a!=NULL;a=a->prox) { 
    	if(a->info == dado) return a;
	}         
	return NULL;
}
Lista* lista_retira(Lista* li, int dado){
    //procura o elemento na lista usando a função busca
    Lista *aux=lista_busca(li, dado);
    if (aux==NULL) { //não achou o elemento 
    	return li;
	}
    //retira o elemento encadeado
	if(li==aux) { //verifica se é o primeiro da lista
    	li=aux->prox;
	} else {
    	aux->ant->prox=aux->prox;
	}
    if (aux->prox!=NULL) { //testa para ver se é o ultimo da lista
        aux->prox->ant=aux->ant;
	}
    free(aux);
    return li;
}
