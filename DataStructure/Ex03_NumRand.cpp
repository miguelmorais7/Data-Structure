#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

main(){
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	int vet[10];
	
	for(int i=0; i<10; i++){
		vet[i] = rand()% 10+1;
		for(int j=0; j<=i-1; j++){
			if(vet[i] == vet[j]){
				vet[i] = rand()% 10+1;
			}
		}
		printf("\n%i",vet[i]);
	}
	
}
