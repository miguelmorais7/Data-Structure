#include <stdio.h>
#include <stdlib.h>
//lista simplesmente encadeada
typedef struct lista{
	int info;
	struct lista *prox;
}Lista;

Lista *lista_cria(){
	return NULL;
}
Lista *lista_insere(Lista *li, int dado){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->info=dado;
	novo->prox=li;
	return novo;
}
void lista_exibe(Lista *li){
	Lista *aux;
	for(aux=li;aux!=NULL;aux=aux->prox){
		printf("%d\t",aux->info);
	}
	printf("\n");
}
/* retorna 1 se vazia ou zero se falso*/
int lista_vazia(Lista* li)
{     
    return (li==NULL);//retorna o //resultado da comparação de l com NULL
}
 
Lista *lista_busca(Lista *li,int dado){
	Lista *a;//ponteiro auxiliar
	a=li;
	while(a!=NULL){
		if(a->info==dado)
		    return a;
		a=a->prox;
	}
	return NULL;
}
void lista_libera(Lista *li){
     Lista *p,*t;
     p=li;
     while(p!=NULL){
       t=p->prox;
       free(p);//libera um item por vez
       p=t;
     } 
} 
Lista* lista_retira(Lista* li, int dado)
{
      Lista* ant=NULL; //ponteiro para o anterior
      Lista *aux=li;// ponteiro para percorrer a lista  
      //procura o elemento na lista guardando seu anterior
      while(aux!=NULL && aux->info!=dado)       {
            ant=aux;
            aux=aux->prox;
      }
      //verifica se achou o elemento
      if(aux==NULL) {
           printf("\nNao localizado\n");         
           return li; //não achou - retorna a lista
      }
      //retira o elemento
      if (ant==NULL) //primeiro da lista
         li=aux->prox;
      else
        //retira do meio/fim da lista
        ant->prox=aux->prox;
      free(aux);
      return li;
}
int contaElementos(Lista *li){
	int conta=0;
	Lista *a;
	for(a=li;a!=NULL;a=a->prox)
	  conta++;
	return conta;
}
Lista* lista_ordenada(Lista* li, int v)
{
    Lista* ant=NULL;
    Lista* p=li;
    //cria novo elemento
    Lista*  novo=(Lista*)malloc(sizeof(Lista));
    novo->info=v;
     //procura posição de inserção
    while (p!=NULL && p->info < v) {
          ant=p;
          p=p->prox;
    }     
    //encadeia o elemento
    if(ant==NULL) {//insere no inicio  
         novo->prox=li;
         li=novo;
    }
    else //insere no meio ou no fim da lista
    {
         novo->prox=ant->prox;
         ant->prox=novo;
     }
     return li;
}        

void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Insere\n");       
     printf("2. Retira \n");
     printf("3. Mostra a lista\n");
     printf("4. Busca elemento\n");
     printf("5. Conta elementos\n");//int contaElementos(Lista *t)
     printf("6. Soma elementos\n");//int somaElementos(Lista *t)
     printf("7. Ultimo elemento\n");//int ultimoElemento (Lista *t)
	 printf("9. Fim\n");
}     
main(){
 Lista *lst=lista_cria();
 Lista *aux;//ponteiro auxiliar para a lista
 int opmenu;
 int item;
 do{
    menu(); 
    scanf("%d", &opmenu);
    switch (opmenu){
    case 1 : //insere
          printf("Digite o valor a ser inserido: ");
          scanf("%d", &item);
          //lst=lista_insere(lst,item);
		   lst=lista_ordenada(lst,item);
		   break;
    case 2 : //retira
          if(lista_vazia(lst)) 
              printf("lista vazia.\n");
          else{
          	printf("Digite o valor a ser retirado: ");
            scanf("%d", &item);
          //lst=lista_insere(l
          	lst=lista_retira(lst,item);
		  }
          break;    
    case 3 : //mostra
          lista_exibe(lst);  break;
	
	case 4://busca elemenento
	      printf("Digite o valor a ser procurado: ");
	      scanf("%d",&item);
	      aux=lista_busca(lst,item);
	      if(aux==NULL)
	      	printf("Nao encontrado na lista\n");
	      else
	        printf("Encontrado!!\n");
	      break;
	case 5://conta elementos
	      printf("Numero de elementos: %d\n",contaElementos(lst)) ;
	      break;
		                    
   }//switch
   printf("\n");
   system("pause"); 
 } while(opmenu!=9);
}



