#include <stdio.h>
//uso do fputs
int main(){
	char frase[31];
	FILE *arq=fopen("saida2.txt","at");
	if(arq==NULL){
		printf("Erro de abertura!\n");
		return 1;//deu erro
	}
	//gravação caractere a caractere
	for(int i=0;i<3;i++){
	  printf("Digite uma frase: ");
	  fflush(stdin);
	  gets(frase);
	  fputs(frase,arq);//grava 1 frase por vez
	  fputc('\n',arq);
	 
	}
	fclose(arq);
	printf("\nArquivo gravado\n");

}
