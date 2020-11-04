#include <stdio.h>
#include <stdlib.h>

int trocaCarac(char *f, char m, char p){
	int i,cont=0;
	
	for(i=0;f[i]!='\0';i++){
		if(f[i]==m){
			f[i]=p;
			cont++;
		}
	}
	return cont;
}

int main(){
	char *palavra = (char*) malloc(sizeof(int)*15);
	char m,p;
	
	printf("Digite uma palavra: ");
	scanf(" %s", palavra);
	printf("Digite a letra a ser trocada: ");
	scanf(" %c", &m);
	printf("Digite a letra substituta: ");
	scanf(" %c", &p);
	
	printf("A letra %c foi trocada pela letra %c %d vezes. A nova palavra e: %s", m,p,trocaCarac(palavra,m,p),palavra);
}
