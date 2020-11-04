/*Ex01_N2_EstruturaDeDados
Programador: Miguel Costa de Morais
Data: 18/11/2018
	Enunciado: Escreva uma função recursiva que faça a procura sequencial 
	de um valor passado por parâmetro em uma lista duplamente encadeada cujo 
	ponteiro para o elemento inicial foi passado por parâmetro. A função deve 
	informar o valor encontrado, ou informar não encontrado se toda lista for 
	percorrida sem sucesso.
	
Protótipo:  void buscalista (Lista *l, int valor)    
*/

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

typedef struct lista{
    int num;
    struct lista *ant;
    struct lista *prox;
}Lista;

Lista *lista_cria(){
	return NULL;
}

Lista *lista_insere(Lista *l, int dado){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=dado;
	novo->prox=l;
	novo->ant=NULL;
	if(l!=NULL){
		l->ant=novo;
	}
	return novo;
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

void buscalista(Lista *l,int valor){
	Lista *a;//ponteiro auxiliar
	a=l;
	while(a!=NULL){
		if(a->num==valor) //Se o valor passado como parâmetro é igual ao valor atual na lista
		    //return a;	
		    printf("Valor encontrado!!!"); //Mensagem se encontrar o valor
		a=a->prox; //Passa para o próximo item da lista
	}
	//return NULL;
	printf("Valor não encontrado!!!"); //Mensagem se não encontrar o valor
}

int main(){
	setlocale(LC_ALL, "portuguese");
	int cont = 0;
	int valor, tam, item; //Valor = valor a ser procurado; tam = tamanho da lista; item = adição a lista
	Lista *lst = lista_cria(); //Chamada de função para criar lista
	Lista *aux; //Variável auxiliar
	
	//Usuário digita o tamanho que a lista terá
	printf("Digite a quantidade de valores que a Lista irá receber: ");
	scanf("%i",&tam);
	
	//Trecho responsável por randomizar a entrada dos números na lista
	do{
		item = rand()% 50+1; //Será gerado um número de 0 até 50
		lst = lista_insere(lst,item); //O numero gerado será inserido na lista
		cont += 1; //Conta quantas vezes foi feito o processo	
	}while(cont < tam); //Verificação para quando terminar a inserção
	
	//Usuário digita o valor que será passado como parâmetro para realizar a busca na lista
	printf("Digite um valor a ser procurado: ");
	scanf("%i",&valor);
	
	lista_exibe(lst); //Exibe lista
	
	buscalista(lst, valor); //Busca elemento na lista
	
}

