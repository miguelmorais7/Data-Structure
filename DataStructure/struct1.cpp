#include <stdio.h>
#include <stdlib.h>
/*
typedef struct{
	int codigo;
	char nome[16];
	int qtd;
	float preco;
}Produto;*/
struct produto{
	int codigo;
	char nome[16];
	int qtd;
	float preco;
};
typedef struct produto Produto;

int main(){
	Produto p[3];//vetor de 3 produtos
	int i;
	for(i=0;i<3;i++){//preenche os dados do vetor
		printf ("Digite o codigo: ");
		scanf("%d",&p[i].codigo);
		printf ("Digite o nome: ");
		scanf(" %s",p[i].nome);
		printf ("Digite a quantidade: ");
		scanf("%d",&p[i].qtd);
		printf ("Digite o preco: ");
		scanf("%f",&p[i].preco);
		printf("\n");
	}
	system("cls");
	printf("**Produto**\n\n");//mostra os produtos
	for(i=0;i<3;i++){
		printf("Codigo: %d\nNome:%s\nQtd:%d\nPreco:R$%.2f\nTotal:R$%.2f\n\n",
	         p[i].codigo,p[i].nome,p[i].qtd,p[i].preco,p[i].qtd*p[i].preco);
	}
}
