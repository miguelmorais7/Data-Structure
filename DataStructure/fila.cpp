#include <stdio.h>
#include <stdlib.h>
//#include "fila00.h"
#include "fila.h"//fila com lista
      
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Enfilera\n");       
     printf("2. Retira \n");
     printf("3. Mostra a fila\n");
     printf("4. Fim\n");
     printf("5. Conta Elementos\n");
     printf("6. Elemento central\n");//void mostraCentro(Fila *f)
}
int conta(Fila *f){
	int cont=0;
	Fila *aux=fila_cria();
	//esvazia a fila original para contar
	while(!fila_vazia(f)){
		fila_insere(aux,fila_retira(f));
		cont++;
	}
	//PÕE DE VOLTA
	while(!fila_vazia(aux))
	    fila_insere(f,fila_retira(aux));
	fila_libera(aux);
	return cont;
}   
void mostraCentro(Fila *f){
	int cont=0;
	int t=conta(f);
	t=t/2+1;
	float v,meio;
	Fila *aux=fila_cria();
	//descobre o elemento central
	while(!fila_vazia(f)){
		v=fila_retira(f);
		cont++;
		if(cont==t)
		    meio=v;
		fila_insere(aux,v);
	}
	//recoloca na fila original
	while(!fila_vazia(aux)){
		fila_insere(f,fila_retira(aux));
	}
	fila_libera(aux);
	printf("Elemento central: %.0f\n",meio);
}
main(){
 Fila *fi=fila_cria();
 int opmenu; 
 float item;
 do{
    menu(); 
    scanf("%d", &opmenu);
    switch (opmenu){
    case 1 : //insere
          printf("Digite o valor a ser enfileirado: ");
          scanf("%f", &item);
          fila_insere(fi,item); break;
    case 2 : //retira
          if(fila_vazia(fi)) 
              printf("fila vazia.\n");
          else
              printf("Elemento retirado = %.0f\n",fila_retira(fi));
          break;    
    case 3 : //mostra
          if(fila_vazia(fi)) 
              printf("fila vazia.\n");
          else
              mostra_fila(fi);
		  break;   
	case 4://libera
	        fila_libera(fi);
			break;
	case 5://conta elementos
	       printf("Total de elementos: %d\n",conta(fi));
		   break;  
    case 6://elemento central
	       mostraCentro(fi);
		   break;               
   }//switch
   printf("\n");
   system("pause"); 
 } while(opmenu!=4);
}
                                          
