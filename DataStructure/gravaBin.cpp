#include <stdio.h>
#include <stdlib.h>
//uso do fseek

int main(){
    FILE *fp;
    int num[20];
    int vet[5];
    for(int i=0;i<20;i++)
       num[i]=i;
    fp=fopen("vetBin.bin","a+b");
    fwrite(num, sizeof(int),20,fp); //gravação em binário (gera novo arq)
   // fclose(fp);
   // fp=fopen("vetBin.bin","rb");
    rewind(fp);
   // fseek(fp,-5*sizeof(int),SEEK_END); //SEEK_CUR ou SEEK_SET
 	printf("\nVetor resultante\n");
    while(fread(vet, sizeof(int),5,fp)) {//leitura de binário 
   
    for(int i=0; i<5;i++){
	        printf("%d\t",vet[i]);
	    }
    printf("\n"); 
}
    fclose(fp);

   
    return 0;
}

