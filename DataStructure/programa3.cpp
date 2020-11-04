#include <stdio.h>
#include <stdlib.h>

void retira_brancos(char *frase){
	int i,j;
	
	for(i=0;frase[i]!='\0';i++){
		if(frase[i]==' '){
			for(j=i;frase[j]!='\0';j++){
				frase[j]=frase[j+1];
			}
		}
	}
	printf("Nova frase: %s", frase);
}

int main(){
	char *frase = (char*) malloc(sizeof(char)*15);
	
	printf("Digite uma frase: ");
	gets(frase);
	
	retira_brancos(frase);
}
