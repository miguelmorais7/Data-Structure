#include <stdio.h>
//uso do fgetc
int main(){
	int c, nl=0;
	FILE *fp=fopen("entrada.txt","rt");
	if(fp==NULL){
		printf("Erro de abertura!\n");
		return 1;//deu erro
	}
	//leitura caractere a caractere
	while((c=fgetc(fp))!=EOF){
	    if(c=='\n') nl++;//conta os enter's	
	}
	fclose(fp);
	printf("Numero de linhas: %d\n",nl);
}
