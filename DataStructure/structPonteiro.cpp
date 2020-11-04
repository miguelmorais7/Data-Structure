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
	Produto *p;//ponteiro para produto
	p=(Produto*)malloc(sizeof(Produto)*3);//3 produtos
	int i;
	Produto *x = p;//ponteiro auxiliar
	for(i=0;i<3;i++,p++){//preenche os dados do vetor
		printf ("Digite o codigo: ");
		scanf("%d",&p->codigo);
		printf ("Digite o nome: ");
		scanf(" %s",p->nome);
		printf ("Digite a quantidade: ");
		scanf("%d",&p->qtd);
		printf ("Digite o preco: ");
		scanf("%f",&p->preco);
		printf("\n");
	}
	system("cls");
	p =x;
	printf("** Produtos **\n\n");//mostra os produtos
	for(i=0;i<3;i++, p++){
		printf("Codigo: %d\nNome:%s\nQtd:%d\nPreco:R$%.2f\nTotal:R$%.2f\n\n",
	         p->codigo,p->nome,p->qtd,p->preco,p->qtd*p->preco);
	}
}
