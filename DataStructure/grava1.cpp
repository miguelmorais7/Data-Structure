#include <stdio.h>
//uso do fputc
int main(){
	char frase[]="Estrutura de Dados";
	FILE *arq=fopen("saida.txt","at");
	if(arq==NULL){
		printf("Erro de abertura!\n");
		return 1;//deu erro
	}
	//gravação caractere a caractere
	for(int i=0;frase[i]!='\0';i++){
	  fputc(frase[i],arq);//grava 1 caracter por vez
	}
	fclose(arq);
	printf("\nArquivo gravado\n");

}
