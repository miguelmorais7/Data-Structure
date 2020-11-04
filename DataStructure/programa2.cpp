#include <stdio.h>
#include <stdlib.h>

void palindromo(char *palavra){
	int i,j;
	
	for(i=0;palavra[i]!='\0';i++);
	i--;
	
	char aux[i];
	
	for(j=0;i>=0;j++,i--){
		aux[j]=palavra[i];
		if(palavra[j]==aux[j]){
			continue;
		}else{
			printf("Nao e palindromo.");
			return;
		}
	}
	printf("E palindromo");
}

int main(){
	char *palavra = (char*) malloc(sizeof(char)*15);
	
	printf("Digite uma palavra: ");
	scanf(" %s", palavra);
	
	palindromo(palavra);
}
