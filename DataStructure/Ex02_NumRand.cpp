#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

void BuscaValor(int v[], int tam, int valor){
	int cont = 0;
	for(int i=0; i<tam; i++){
		if(valor == v[i]){
			printf("Elemento %i encontrado no indice %i do vetor\n", valor, v[i]);
			cont++;
		}
	}
	if(cont == 0){
		printf("\nO elemento %i não foi encontrado no vetor\n", valor);
	}
	else{
		printf("\nO elemento %i foi encontrado %i veze(s) no vetor\n", valor, cont);
	}
}

main(){
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	int tam, valor;
	
	printf("Digite o tamanho do vetor (entre 10 e 30): ");
	scanf("%i", &tam);
	
	printf("Digite o valor a ser buscado no vetor: ");
	scanf("%i", &valor);
	
	int vet[tam];
	for(int i=0; i<tam; i++){
		vet[i] = rand()% 30+1;
		printf("\n%i",vet[i]);
	}
	
	BuscaValor(vet, tam, valor);
}
