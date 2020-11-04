#include <stdio.h>
#include <stdlib.h>
//#include "pilha00.h"
#include "pilha.h"//pilha com lista
                                    
void menu (){
     system("cls");
     printf("Escolha a opção desejada:\n");
     printf("1. Empilha\n2. Retira\n3. Mostra\n4. Sair\n");
     printf("5. Mostra topo\n6. Conta Elementos\n");
     
}                      
float obter_valor() {
      float v;
      printf("Digite o valor: ");
      scanf("%f",&v);
      return v;
}
float mostra_topo(Pilha *p){
      float valor;
      valor=pilha_pop(p);
      pilha_push(p,valor);
      return valor;
}  
int conta(Pilha *p){
	int conta=0;
	Pilha *aux=pilha_cria();
	//esvazia a pilha original para contar
	while(!pilha_vazia(p)){
		pilha_push(aux,pilha_pop(p));
		conta++;
	}
	//recoloca na pilha original
	while(!pilha_vazia(aux))
        pilha_push(p,pilha_pop(aux));
	pilha_libera(aux);
	return conta;	
}   
int main(){
    int op;
    float v;
    Pilha *p = pilha_cria();
    do {
            menu();
            scanf("%d",&op);
            switch(op){
               case 1 : 
                    pilha_push(p,obter_valor()); break;        
               case 2 : 
                    if(pilha_vazia(p)) 
                         printf ("Pilha vazia.\n");
                    else
                        printf ("\nValor retirado = %.0f\n", pilha_pop(p));
                  
                    break;
               case 3 : 
                    pilha_mostra(p);
                    break;  
               case 4 :
                     pilha_libera(p);
                     break;
               case 5:
                     if(!pilha_vazia(p))
                        printf("\nTopo=%.0f\n",mostra_topo(p));
                     else
                        printf("\nPilha vazia!\n");
                     break;
               case 6://conta elementos
			          printf("Numero de elementos: %d\n",
					         conta(p));
					  break;      
               default : printf ("\nOpcao invalida\n"); 
               } 
               printf("\n");
               system("pause");
       }while (op!=4);      
   
     return 0;
       
}                                             
