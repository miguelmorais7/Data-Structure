//Tratamento de strings
#include <stdio.h>
#include <stdlib.h>
int vogais(char s[]){
	int i,n=0;
	char c;
	for(i=0;s[i]!='\0';i++){
		switch(s[i]){
			case 'A':
			case 'a': n++; break;
			case 'E':
			case 'e': n++; break;
			case 'I':
			case 'i': n++; break;
			case 'O':
			case 'o': n++; break;
			case 'U':
			case 'u': n++; break;
		}
	}
	return n;
}
//----------------------------
void separa(char *s){
	printf("Palavra separada: %c",*s++);
	while(*s!='\0'){
		printf("-%c",*s++);
	}
	printf("\n");
}
//------------------------------
char inicial(char s[]){
	return s[0];
}
//-------------------------------
void tamanho(char p[]){
	int i;
	for(i=0;p[i]!='\0';i++);
	printf("Tamanho da palavra %s: %d\n",p,i);
}
//----------------------------------
void inverte(char *p){
	int i;
	for(i=0;p[i]!='\0';i++);//procura o fim da palavra
	//escreve de trás para frente
	i--;//desconta o '\0'
	printf("Palavra invertida: ");
	for(;i>=0;i--){
		printf("%c",p[i]);
	}
	printf("\n");
}
//---------------------------
int main(){
	char palavra[16];//nome do vetor corresponde ao & da posição 0
	int resp;
	int cont=0;
	do{
		system("cls");
		printf("Digite uma palavra: ");
		scanf(" %s",palavra);//scanf(" %s",&palavra[0]);
		cont++;
		tamanho(palavra);
		separa(palavra);
		printf("Inicial da palavra: %c\n",inicial(palavra));
		printf("Vogais: %d\n",vogais(palavra));
		inverte(palavra);
		printf("\nDigite 0 para encerrar: ");
		scanf("%d",&resp);
	}while(resp!=0);
	printf("\nForam lidas %d palavras\n",cont);
}
