#include <stdio.h>
//uso do fgets
int main(){
	int np=0;
	char c[41];
	FILE *fp=fopen("entrada.txt","rt");
	if(fp==NULL){
		printf("Erro de abertura!\n");
		return 1;//deu erro
	}
	//leitura caractere a caractere
	while(fgets(c,40,fp)!=NULL){
	  printf("%s",c);
	  np++;
	}
	fclose(fp);
	printf("\nNumero de frases: %d\n",np);

}
