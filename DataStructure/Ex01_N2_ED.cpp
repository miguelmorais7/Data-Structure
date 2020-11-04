/*Ex01_N2_EstruturaDeDados
Programador: Miguel Costa de Morais
Data: 18/11/2018
	Enunciado: Escreva uma fun��o recursiva que fa�a a procura sequencial 
	de um valor passado por par�metro em uma lista duplamente encadeada cujo 
	ponteiro para o elemento inicial foi passado por par�metro. A fun��o deve 
	informar o valor encontrado, ou informar n�o encontrado se toda lista for 
	percorrida sem sucesso.
	
Prot�tipo:  void buscalista (Lista *l, int valor)    
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
		if(a->num==valor) //Se o valor passado como par�metro � igual ao valor atual na lista
		    //return a;	
		    printf("Valor encontrado!!!"); //Mensagem se encontrar o valor
		a=a->prox; //Passa para o pr�ximo item da lista
	}
	//return NULL;
	printf("Valor n�o encontrado!!!"); //Mensagem se n�o encontrar o valor
}

int main(){
	setlocale(LC_ALL, "portuguese");
	int cont = 0;
	int valor, tam, item; //Valor = valor a ser procurado; tam = tamanho da lista; item = adi��o a lista
	Lista *lst = lista_cria(); //Chamada de fun��o para criar lista
	Lista *aux; //Vari�vel auxiliar
	
	//Usu�rio digita o tamanho que a lista ter�
	printf("Digite a quantidade de valores que a Lista ir� receber: ");
	scanf("%i",&tam);
	
	//Trecho respons�vel por randomizar a entrada dos n�meros na lista
	do{
		item = rand()% 50+1; //Ser� gerado um n�mero de 0 at� 50
		lst = lista_insere(lst,item); //O numero gerado ser� inserido na lista
		cont += 1; //Conta quantas vezes foi feito o processo	
	}while(cont < tam); //Verifica��o para quando terminar a inser��o
	
	//Usu�rio digita o valor que ser� passado como par�metro para realizar a busca na lista
	printf("Digite um valor a ser procurado: ");
	scanf("%i",&valor);
	
	lista_exibe(lst); //Exibe lista
	
	buscalista(lst, valor); //Busca elemento na lista
	
}

