#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

int BuscaElemento(int v[], int tam, int valor){
	int indice;
	for(int i=0; i<tam; i++){
		if(valor == v[i]){
			indice = v[i];
			return indice;
		}
	}
	return -1;
}

main(){
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	int tam, valor, retorno;
	
	do{
		printf("Digite o tamanho do vetor (entre 10 e 30): ");
		scanf("%i", &tam);
	}while(tam < 10 && tam >30);
	
	int vet[tam];
	for(int i=0; i<10; i++){
		vet[i] = rand()% 10+1;
		for(int j=0; j<=i-1; j++){
			if(vet[i] == vet[j]){
				vet[i] = rand()% 10+1;
			}
		}
		printf("\n%i",vet[i]);
	}
	
	printf("Digite o valor a ser buscado no vetor: ");
	scanf("%i", &valor);
	
	retorno = BuscaElemento(vet, tam, valor);
	if(retorno == -1){
		printf("Valor não encontrado");
	}
	else{
		printf("Valor encontrado no indice %i do vetor", retorno);
	}
}
	
	
