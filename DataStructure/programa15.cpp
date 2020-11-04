#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
	int matricula;
	float nota;
	struct lista *ant;//**
	struct lista *prox;
}Lista;//Lista dupla

Lista *lista_cria(){
	return NULL;
}
Lista *lista_insere(Lista *li, int matricula, float nota){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->matricula=matricula;
	novo->nota=nota;
	novo->prox=li;
	novo->ant=NULL;//**
	if(li!=NULL)
		li->ant=novo;//**
	return novo;
}
//void lista_exibe(Lista *li){
//	Lista *aux;
//	if(li==NULL)
//		printf("Lista Vazia");
//	else{
//		printf("\nLista\n");
//		for(aux=li;aux!=NULL;aux=aux->prox){
//			printf("%d\t",aux->info);
//		}
//	}
//	printf("\n");
//}
/* retorna 1 se vazia ou zero se falso*/
int lista_vazia(Lista* li)
{     
    return (li==NULL);//retorna o //resultado da comparação de l com NULL
}
 
Lista *lista_busca(Lista *li,int dado){
	Lista *a;//ponteiro auxiliar
	a=li;
	while(a!=NULL){
		if(a->matricula==dado)
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

int contaElementos(Lista *li){
	int conta=0;
	Lista *a;
	for(a=li;a!=NULL;a=a->prox)
	  conta++;
	return conta;
}
//Opcionalmente pode-se inserir na lista de forma ordenada
//Lista* lista_insere_ordenado(Lista* li, int v){
//    Lista* novo;
//    Lista* anterior=NULL;
//    Lista* p=li;
//    
//    //cria novo elemento
//    novo=(Lista*)malloc(sizeof(Lista));
//    novo->info=v;
//            
//    //procura posição de inserção
//    while (p!=NULL && p->info < v)  {
//          anterior=p;
//          p=p->prox;
//    }     
//    //encadeia o elemento
//    if(anterior==NULL) {//insere no inicio
//	     if(li!=NULL) li->ant=novo;
//         novo->prox=li;
//         novo->ant=NULL;
//	     li=novo;
//    }      
//    else  {//insere no meio ou no fim da lista
//            novo->prox=anterior->prox;
//            novo->ant=anterior;
//            if (anterior->prox!=NULL)
//                 anterior->prox->ant=novo;
//            anterior->prox=novo;
//           }
//   return li;
//} 
     
/* retorna o novo inicio ou a lista original*/
Lista* lista_retira(Lista* li, int dado){
      //procura o elemento na lista usando a função busca
      Lista* aux=lista_busca(li, dado);
      if (aux==NULL) //não achou o elemento
          return li; 
      //retira o elemento encadeado
      if(li==aux) //verifica se é o primeiro da lista
        li=aux->prox;
      else
        aux->ant->prox=aux->prox;
      //testa para ver se é o ultimo da lista
      if (aux->prox!=NULL)        
          aux->prox->ant=aux->ant;
      free(aux);
      return li;
}

float retornaNota(Lista *l, int mat){
	Lista *aux=lista_busca(l, mat);
	
	if(aux==NULL)
		return -1;
	else
		return aux->nota;
}

float media(Lista *l){
	Lista *aux=l;
	float media=0;
	int a=0;
	
	while(aux!=NULL){
		media+=aux->nota;
		a++;
		aux=aux->prox;
	}
	
	return media/a;
}

int notasMaiores(Lista *l, float n){
	Lista *aux=l;
	int cont=0;
	
	while(aux!=NULL){
		if(aux->nota>n){
			cont++;
		}
		aux=aux->prox;
	}
	
	return cont;
}

int main(){
	Lista *lst=lista_cria();
	int mat;
	float n;
	
	lst = lista_insere(lst, 10, 9);
	lst = lista_insere(lst, 20, 8);
	lst = lista_insere(lst, 30, 10);
	lst = lista_insere(lst, 40, 8);
	lst = lista_insere(lst, 50, 9);
	
	printf("Digite a matricula: ");
	scanf("%d", &mat);
	
	float nota = retornaNota(lst,mat);
	
	if(nota==-1)
		printf("Matricula nao encontrada.\n");
	else
		printf("Nota = %.2f\n", nota);

	printf("Media = %.2f\n", media(lst));
	
	printf("Digite a nota: ");
	scanf("%f", &n);
	
	printf("%d aluno(s) tem nota maior que %.2f: \n", notasMaiores(lst,n), n);
}
