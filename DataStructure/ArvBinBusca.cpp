#include <stdio.h>
#include <stdlib.h>
//arvore binária de busca (abb)
typedef struct arv{
	int info;
	struct arv *esq;
	struct arv *dir;
}Arv;

Arv *abb_cria(){
	return NULL;
}

int abb_vazia(Arv *a){
	return(a==NULL);//retorna 1 se vazia ou 0
}
//inserção recursiva na ABB
Arv* abb_insere(Arv *a, int v){
    if (a==NULL){
       a=(Arv*) malloc(sizeof(Arv));
	   a->info=v;
	   a->esq=a->dir=NULL;
     } 
     else if (v < a->info)
                   a->esq=abb_insere(a->esq,v);
             else    
                   a->dir=abb_insere(a->dir,v);
     return a;
} 
//percurso em ordem
void abb_ordem(Arv *a){ //esq - raiz - dir
	if(a!=NULL){
		abb_ordem(a->esq);
		printf("%d\t",a->info);//raiz
		abb_ordem(a->dir);
	}
}
//percurso em pre-ordem
void abb_preordem(Arv *a){ //raiz - esq - dir
	if(a!=NULL){
		printf("%d\t",a->info);//raiz
		abb_preordem(a->esq);
		abb_preordem(a->dir);	
	}
}
//percurso em pos-ordem
void abb_posordem(Arv *a){  // esq  - dir - raiz
	if(a!=NULL){
		abb_posordem(a->esq);
		abb_posordem(a->dir);
		printf("%d\t",a->info);//raiz
	}
}
//altura da arvore
int max2 (int a, int b){
       return (a>b)?a:b;//if ternário.Compara a com b, se 
       //verdadeiro retorna a, senao retorna b
}       

int abb_altura(Arv *a){
       if (abb_vazia(a))
           return -1;
       return 1+ max2(abb_altura(a->esq),abb_altura(a->dir));   
}              

//-------------------------------------------------
int main() {
  int num;
  Arv *a=abb_cria();
  int v;
  //insere elementos na abb até que um -1 seja digitado
  do{
     printf("Entre com o valor a ser inserido, ou -1 para finalizar:\n");
     scanf("%d", &num);
     if(num>=0)
           a=abb_insere(a,num);
     }while(num>=0);
     
   printf("\n\nPrecurso em ordem\n");
   abb_ordem(a); //imprime em ordem
   printf("\n\n");
   printf("Precurso em pre-ordem\n");
   abb_preordem(a); //imprime em ordem
   printf("\n\n");
   printf("Precurso em posordem\n");
   abb_posordem(a); //imprime em ordem
   printf("\n\n");
   printf("Altura da arvore: %d\n",abb_altura(a));
   printf("\n\n");
}                                                                                        

