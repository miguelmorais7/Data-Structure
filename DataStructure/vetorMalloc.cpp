#include <stdio.h>
#include <stdlib.h>
int main(){
	float *z;
	float *pz;
	int i;
	z=(float*)malloc(sizeof(float)*5);//cria um vetor de 5 floats
	pz=z;//salva o endereço inicial
	for(i=0;i<5;i++){
		z[i]=i+1;
	}
	for(i=0;i<5;i++){
	   printf("%.1f\n",*z);
	   z++;
    }  	
    printf("\n");
    z=pz;
	for(i=0;i<5;i++){
	   printf("%.1f\n",z[i]);
	   
    } 
}
