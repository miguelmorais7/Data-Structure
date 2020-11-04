#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

void GravaPalavra(char palavras[], int tam){
	FILE *arq = fopen("palavras.txt","at");
	if(arq == NULL){
		printf("Erro de abertura!");
		system("pause");
	}
	for(int i=0; i<tam; i++){ 
		fflush(stdin);
		fprintf(arq,"%s\n",palavras[i]); 
	}
	fclose(arq); 
	printf("\nArquivo gravado\n");
}

void ContaPalavra(char palavras[], int tam){
	int cont = 0;
	FILE *arq = fopen("palavras.txt","at");
	if(arq == NULL){
		printf("Erro de abertura!");
		system("pause");
	}
	while(fscanf(arq, "%s", palavras)==1){
		cont++;
	}
	fclose(arq);
	printf("Número de palavras = %i", cont);
}

main(){
	setlocale(LC_ALL, "portuguese");
	char palavras[] = {'mesa','carro','bola','copo','bola','prego','cadeira','pia','janela','bola'};
	int tam = 10;
	
	GravaPalavra(palavras, tam);
	ContaPalavra(palavras, tam);
}
