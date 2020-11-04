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

Arv* abb_busca(Arv *r, int v){
    if (r==NULL) return NULL;
    if (r?info > v) 
                return abb_busca(r?esq,v);
    if (r?info < v)
                 return abb_busca(r?dir,v);
    return r; 	
}

void mostraPercursos(){
	printf("\n\nPercurso em ordem\n");
	abb_ordem(a); //imprime em ordem
	printf("\n\n");
	printf("Percurso em pre-ordem\n");
	abb_preordem(a); //imprime em ordem
	printf("\n\n");
	printf("Percurso em posordem\n");
	abb_posordem(a); //imprime em ordem
	printf("\n\n");
	printf("Altura da arvore: %d\n",abb_altura(a));
	printf("\n\n");
}

void abb_2Filhos(Arv *t){
	if(t != NULL){
		if(t->esq!=NULL && t->dir!=NULL){
			printf("%d\t",t->info)/;
		}
		abb_2Filhos(t->esq);
		abb_2Filhos(t->dir);
	}
}

/*int contaNos(Arv *t){ //Pre-ordem
	int cont = 0;;
	if(t!=NULL){
		cont += 1; //Raiz
		cont += contaNos(t->esq);
		cont += contaNos(t->dir);
	}
}

int somaNos(Arv *t){ //Pre-ordem
	int cont = 0;;
	if(t!=NULL){
		cont += t->info;
		cont += somaNos(t->esq);
		cont += somaNos(t->dir);
	}
}*/

int contaNos(Arv *t){
	if(t!=NULL){
		return 1 + contaNos(t->esq) + contaNos(t->dir);
	}
}

int somaNos(Arv *t){
	if(t!=NULL){
		return t->info + somaNos(t->esq) + somaNos(t->dir);
	}
}	



//-------------------------------------------------
int main() {
  int num;
  Arv *a=abb_cria();
  Arv *aux;
  int v;
  int op;
  //insere elementos na abb até que um -1 seja digitado
  
  do{
	op = menu();
		
	switch(op){
		case 1: //Inserir
			do{
     			printf("Entre com o valor a ser inserido, ou -1 para finalizar:\n");
     			scanf("%d", &num);
     			if(num>=0){
           			a=abb_insere(a,num);
           		}
     		}while(num>=0);
     		
			break;
			
		case 2: //Retirar
			do{
     			printf("Digite o valor a ser retirado, ou -1 para finalizar:\n");
     			scanf("%d", &num);
     			a=abb_busca(a,num);
     			a == NULL?printf("Valor não encontrado!"):num>=0?a=abb_retira(a,num):""; //operador ternario
     		}while(num>=0);
			break;
			
		case 3: //Buscar
			do{
				printf("Digite o valor a ser bucado, ou -1 para finalizar:\n");
     			scanf("%d", &num);
     			if(num >= 0){
     				if(a == NULL){
     					printf("Valor não encontrado!");
					}
					else{
						a=abb_busca(a,num);
						printf("Valor econtrado")
					}  	
				}
			}while(num>=0);
			break;
			
		case 4: //Contar nos
			printf("Numero de nos: %d\n", contaNos(a));
			break;
			
		case 5: //Somar
			printf("Soma dos nos: %d\n", somaNos(a))
			break;
			
		case 6: //Mostra no com 2 filhos
			printf("Nos com dois filhos\n");
			abb_2Filhos(a);
			break;
			
		case 7: //Mostra percurso
			mostraPercurso(a);
			break;
			
		default:
			printf("Digite uma operacao valida!");
			break;
		}	
	}while(op =! 9);
}                       
  
  

int menu(){
	int op;
	printf("Escolha alguma operacao: ");
	printf("1 - Inserir\n2 - Retirar\n3 - Buscar\n4 - Contar\n5 - Somar\n6 - Mostra nos com 2 filhos\n7 - Mostra percurso\n9 - Finalizar\n")
	scanf("%i",&op);
	return op;
}


	
	                                                                

