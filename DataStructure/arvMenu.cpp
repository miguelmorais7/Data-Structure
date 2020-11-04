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
//busca um elemento na Abb – outra versão
 Arv* abb_busca(Arv *r, int v){
    if (r==NULL) return NULL;
    if (r->info > v) 
                return abb_busca(r->esq,v);
    if (r->info < v)
                 return abb_busca(r->dir,v);
    return r; 	
}
//retira um elemento da árvore
Arv* abb_retira(Arv *r, int v) {
     if (r==NULL) return NULL;
     if(r->info > v) r->esq = abb_retira(r->esq, v);
     else if (r->info < v) r->dir = abb_retira(r->dir, v);
          else {      //achou o elemento 
                if ( r->esq ==NULL && r->dir ==NULL) { // no sem filhos
                     free(r);
                     r=NULL;   } 
                else  if (r->esq ==NULL) { //filho a direita            
                          Arv *t = r;
                          r=r->dir;
                          free(t);      }
                      else if( r->dir ==NULL) { //filho a esquerda
                                 Arv *t=r;
                                 r=r->esq;
                                 free(t);     }
                               else { //tem 2 filhos     
                                      Arv *f=r->esq;
                                      while (f->dir != NULL)f=f->dir;
                                      r->info =f->info;
                                      f->info=v;
                                      r->esq=abb_retira(r->esq,v);    }
                    }
                    return r;                           
}

void menu(){
	system("cls");
	printf("*** Menu ***\n");
	printf("1 - inserir\n");
	printf("2 - retirar\n");
	printf("3 - buscar\n");
	printf("4 - contar\n");
	printf("5 - somar\n");
	printf("6 - mostra nos com 2 filhos\n");
	printf("7 - percursos\n");
	printf("8 - altura\n");
	printf("9 - fim\n\n");
	printf("==> ");
}
void abb_2Filhos(Arv *t){
	if(t!=NULL){
		if(t->esq!=NULL && t->dir!=NULL)//tem 2 filhos
		   printf("%d\t",t->info);
		abb_2Filhos(t->esq);
		abb_2Filhos(t->dir);
	}
}
/*int contaNos(Arv *t){//pre-ordem
	int cont=0;
	if(t!=NULL){
	   cont=cont+1;//raiz
	   cont=cont+contaNos(t->esq);
	   cont=cont+contaNos(t->dir);	
	}
	return cont;
}
int somaNos(Arv *t){//pre-ordem
	int cont=0;
	if(t!=NULL){
	   cont=cont+t->info;//raiz
	   cont=cont+somaNos(t->esq);
	   cont=cont+somaNos(t->dir);	
	}
	return cont;
}*/
int contaNos(Arv *t){
	if(t!=NULL)
	   return 1+contaNos(t->esq)+contaNos(t->dir);
}
int somaNos(Arv *t){
	if(t!=NULL)
	   return t->info+somaNos(t->esq)+somaNos(t->dir);
}
//-------------------------------------------------
int main() {
  int num;
  int op;//opcao do menu
  Arv *a=abb_cria();
  Arv *aux;//variavel auxiliar do tipo árvore(busca)
  do{
   	  menu();
   	  scanf("%d",&op);
   	  switch(op){
   	  	case 1: //inserir
   	  	     printf("Digite o valor a inserir: ");
   	  	     scanf("%d",&num);
   	  	     a=abb_insere(a,num);
   	  	     break;
		 
		 case 2: //retirar
   	  	     printf("Digite o valor a retirar: ");
   	  	     scanf("%d",&num);
   	  	     a=abb_retira(a,num);
   	  	     break;
		 
		 case 3: //buscar
   	  	     printf("Digite o valor a buscar: ");
   	  	     scanf("%d",&num);
   	  	     aux=abb_busca(a,num);
   	  	     if(aux==NULL)
   	  	        printf("Elemento %d NAO encontrado\n",num);
   	  	     else
   	  	        printf("Encontrado\n");
   	  	     break;
   	  	 case 4://conta nos
   	  	      printf("\nNumero de nos: %d\n",contaNos(a));
   	  	      break;
		 case 5://soma nos
		 	  printf("\nSoma dos nos: %d\n",somaNos(a));
   	  	      break;
		 case 6: //2 filhos
		       printf("\nNos com 2 filhos\n");
		       abb_2Filhos(a);
		       break;
		 case 7: //percursos
		    if(abb_vazia(a))
		      printf("Arvore vazia!\n");
		    else{
			    printf("\nPercurso em ordem\n");
		    	abb_ordem(a);
   	  	    	printf("\n\nPrecurso em pre-ordem\n");
   				abb_preordem(a); //imprime em ordem
   				printf("\n\nPrecurso em posordem\n");
   				abb_posordem(a); //imprime em ordem
   				printf("\n\n");
   			}
   			break;
   		 case 8://altura
  			printf("Altura da arvore: %d\n\n",abb_altura(a));
            break;
		 }
		 printf("\n\n");
		 system("pause");
   }while(op!=9);
}                                                                                        

