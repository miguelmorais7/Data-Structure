#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

int GravaArquivo(int v[], int tam){
	int soma = 0;
	FILE *arq = fopen("Numeros.txt","at");
	if(arq == NULL){
		printf("Erro de abertura!");
		return 1;
	}
	for(int i=0; i<tam; i++){ 
		fflush(stdin);
		fprintf(arq,"%i\n",v[i]); 
		soma += v[i];
	}
	fclose(arq); 
	printf("\nArquivo gravado\n");
	return soma;
}

main(){
	setlocale(LC_ALL, "portuguese");
	int vet[] = {10,300,1000,-5,50,-300,20};
	int tam = 7;
	int soma;
	
	soma = GravaArquivo(vet, tam);
	if(soma == 1){
		printf("ERRO!!!");
	}
	else{
		printf("Soma dos valores no arquivo: %i",soma);
	}
}
