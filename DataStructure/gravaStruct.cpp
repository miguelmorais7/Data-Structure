#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
     int num; 
     char nome[10];
     float nota;
     }Aluno;   
int main(){
    FILE *fp;
    Aluno a,b; 
    a.num=233;
    strcpy(a.nome, "Ze");
    a.nota=0;
    fp=fopen("saidaBin.bin","a+b");
    fwrite(&a, sizeof(Aluno),1,fp); //gravação em binário
    //fclose(fp);
   // fp=fopen("saidaBin.bin","rb");
    //rewind(fp);//volta pro inicio
    fseek(fp,0,SEEK_SET);
    while(fread(&b, sizeof(Aluno),1,fp)){ //leitura de binário
    printf("\nDados gravados:\nNum: %d, Nome: %s, Nota=%.1f\n\n",
	          b.num,b.nome,b.nota);  
	}
    system("pause");
    return 0;
}

