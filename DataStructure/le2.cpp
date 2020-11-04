#include <stdio.h>
//uso do fscanf
int main(){
	int nl=0,nc=0;
	char c;
	FILE *fp=fopen("entrada.txt","rt");
	if(fp==NULL){
		printf("Erro de abertura!\n");
		return 1;//deu erro
	}
	//leitura caractere a caractere
	while(fscanf(fp,"%c",&c)==1){
	    if(c=='\n') nl++;//conta os enter's	
	    else
	       nc++;
	}
	fclose(fp);
	printf("Numero de linhas: %d\n",nl);
	printf("Numero de caracteres: %d\n",nc);
}
