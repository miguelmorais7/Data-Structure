#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

int Soma(int a, int b){
	if(a<b){
		return a + Soma(++a, b);
	}
	return 0;
}

main(){
	setlocale(LC_ALL, "portuguese");
	int valorA, valorB; int soma = 0;
	printf("Digite o valor A: ");
	scanf("%i",&valorA);
	printf("Digite o valor B (maior que o valor A): ");
	scanf("%i",&valorB);
	
	soma = Soma(valorA,valorB);
	printf("O valor da soma é %i", soma);
}
