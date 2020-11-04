#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

int buscavetor(int *vet, int tam, int valor){
	int indice;
	if()
}


main(){
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	int tam, valor, indice;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%i", &tam);
	printf("\nDigite o valor a ser procurado no vetor: ");
	scanf("%i", &valor);
	
	int vetor[tam];
	
	for(int i=0; i<tam; i++){
		vetor[i] = rand()% 10+1;
		printf("\n%i",vetor[i]);
	}
	
	indice = buscavetor(vetor, tam, valor);
	
	
	
	
	
}
