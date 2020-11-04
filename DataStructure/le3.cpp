#include <stdio.h>
//uso do fscanf com palavras
int main(){
	int np=0;
	char c[20];
	FILE *fp=fopen("entrada.txt","rt");
	if(fp==NULL){
		printf("Erro de abertura!\n");
		return 1;//deu erro
	}
	//leitura caractere a caractere
	while(fscanf(fp,"%s",c)==1){
	  printf("%s\n",c);
	  np++;
	}
	fclose(fp);
	printf("\nNumero de palavras: %d\n",np);

}
