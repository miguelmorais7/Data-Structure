#include <stdio.h>
#include <stdlib.h>

void contaLetras(char *p){
	int i, cont[26] = {0}, x;
	
	for(i=0;p[i]!='\0';i++){
		if(p[i]>='a' && p[i]<='z'){
			x = p[i] - 'a';
			cont[x]++;
		}
	}
	
	for(i=0;i<26;i++)
		if(cont[i]>0)
			printf("%c aparece %d vezes na palavra.\n", i + 'a', cont[i]);
}

int main(){
	char *palavra = (char*) malloc(sizeof(char)*15);
	
	printf("Digite uma palavra: ");
	scanf(" %s", palavra);
	
	contaLetras(palavra);
}
