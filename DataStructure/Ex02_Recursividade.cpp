#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

double juroscompostos(double valor, double taxa, int meses){
	double valorTotal;
	if(meses == 0){
		return valorTotal;
	}
	else{
		valorTotal += (valor * (taxa / 100));
		meses--;
		valorTotal = juroscompostos(valor,taxa,meses);
		return valorTotal;
	}
}  

main(){
	setlocale(LC_ALL, "portuguese");
	double valorInicial = 0; double taxa; double valorFinal; int meses;
	
	printf("Digite o valor inicial: ");
	scanf("%lf", &valorInicial);
	printf("Digite o valor da taxa: ");
	scanf("%lf", &taxa);
	printf("Digite a quantidade de meses: ");
	scanf("%i", &meses);
	
	valorFinal = juroscompostos(valorInicial, taxa, meses);
	printf("O valor final será de %.2lf", valorFinal);
	
	
}
