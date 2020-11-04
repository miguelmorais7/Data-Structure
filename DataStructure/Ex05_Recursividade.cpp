#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

void bolha_rec(int *vet, int tam){
	int aux;
	if(tam==1){
		return;	
	}
	for(int i=0; i<tam-1; i++){
		if(vet[i] > vet[i+1]){
			//swap(vet[i], vet[i+1]);
			vet[i] = aux;
			vet[i] = vet[i+1];
			vet[i+1] = aux;
		}
	}
	bolha_rec(vet, tam-1);
	for(int a=0; a<tam; a++){
		printf("%i\t", vet[a]);
	}
}

main(){
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	int tam;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%i", &tam);
	
	int vet[tam];
	
	for(int i=0; i<tam; i++){
		vet[i] = rand()% 10+1;
		printf("%i\t", vet[i]);
	}
	
	bolha_rec(vet, tam);
}
