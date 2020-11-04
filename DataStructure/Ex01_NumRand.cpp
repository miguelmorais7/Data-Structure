#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

main(){
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	int tam;
	
	do{
		printf("Digite o tamanho do vetor (entre 10 e 30): ");
		scanf("%i", &tam);
	}while(tam < 10 && tam >30);
	
	int vet[tam];
	for(int i=0; i<tam; i++){
		vet[i] = rand()% 30+1;
		printf("%i\n",vet[i]);
	}
	
}
