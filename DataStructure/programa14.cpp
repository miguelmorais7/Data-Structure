#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    char nome[20];
	char fone[9];
    struct lista *prox;
}Lista; //definição da lista

/* retorna uma lista vazia */
  Lista * lista_cria()
 {
    return NULL;
}

/* insere o novo dado no início da lista , e retorna a lista atualizada*/
Lista * lista_insere(Lista *li, char *nome, char *fone)
{
Lista *novo=(Lista*) malloc (sizeof(Lista));
//novo->nome = nome;
//novo->fone = fone;
strcpy(novo->nome, nome);
strcpy(novo->fone, fone);
novo->prox=li;
return novo;
}

/* percorre a lista do inicio até o fim mostrando os elementos*/
void lista_mostra(Lista* li)
{     
//variável usada para percorrer a lista
Lista *aux; 
for(aux=li;aux!=NULL;aux=aux->prox){
	printf("%s ==> %s\t", aux->nome, aux->fone);
}
}         
//
///* retorna 1 se vazia ou zero se falso*/
//int lista_vazia(Lista* li)
//{     
//    return (li==NULL);//retorna o //resultado da comparação de l com NULL
//}
//
///* retorna o elemento ou NULL se não achou*/
//Lista* lista_busca(Lista* li, int dado)
//{     
////variável usada para percorrer a lista
//Lista *a; 
//for(a=li;a!=NULL;a=a->prox)
//{ 
//    if(a->info == dado) return a;
//}         
//return NULL;
//}
//
///* retorna o elemento ou a lista original*/
//Lista* lista_retira(Lista* li, int dado)
//{
//      Lista* ant=NULL; //ponteiro para o anterior
//      Lista *aux=li;// ponteiro para percorrer a lista  
//      //procura o elemento na lista guardando seu anterior
//      while(aux!=NULL && aux->info!=dado)       {
//            ant=aux;
//            aux=aux->prox;
//      }
//      //verifica se achou o elemento
//      if(aux==NULL) {
//           printf("\nNao localizado\n");         
//           return li; //não achou - retorna a lista
//      }
//      //retira o elemento
//      if (ant==NULL) //primeiro da lista
//         li=aux->prox;
//      else
//        //retira do meio/fim da lista
//        ant->prox=aux->prox;
//      free(aux);
//      return li;
//}
//
//Lista* lista_ordenada(Lista* li, int v)
//{
//    Lista* ant=NULL;
//    Lista* p=li;
//    //cria novo elemento
//    Lista*  novo=(Lista*)malloc(sizeof(Lista));
//    novo->info=v;
//     //procura posição de inserção
//    while (p!=NULL && p->info < v) {
//          ant=p;
//          p=p->prox;
//    }     
//    //encadeia o elemento
//    if(ant==NULL) {//insere no inicio  
//         novo->prox=li;
//         li=novo;
//    }
//    else //insere no meio ou no fim da lista
//    {
//         novo->prox=ant->prox;
//         ant->prox=novo;
//     }
//     return li;
//}        
//
//void lista_libera(Lista *li){
//     Lista *p,*t;
//     p=li;
//     while(p!=NULL){
//       t=p->prox;
//       free(p);//libera um item por vez
//       p=t;
//     } 
//}



void mostraFone(Lista *l, char *nome){
	Lista *aux=l;// ponteiro para percorrer a lista
	int x = 1;
    
    while(aux != NULL){
    	for(int i = 0;aux->nome[i]!='\0';i++){
    		if(aux->nome[i] != nome[i])
    			x = 0;
		}
		if(x == 1){
			printf("Telefone = %s", aux->fone);
			return;
		}
		aux=aux->prox;
	}
	printf("Nome nao encontrado");
}

int main(){
	Lista *lst = lista_cria();
	char teste1[] = "teste1";
	char fone1[] = "1010";

	lst = lista_insere(lst, teste1, fone1);
	
	char nome[20];
	
	printf("Digite um nome: ");
	scanf(" %s", nome);
	
	mostraFone(lst, nome);
}
