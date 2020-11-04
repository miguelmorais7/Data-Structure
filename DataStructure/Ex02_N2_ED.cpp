/*Ex02_N2_EstruturaDeDados
Programador: Miguel Costa de Morais
Data: 18/11/2018
	Enunciado: Escreva uma fun��o que receba um vetor de n�meros inteiros, 
	j� preenchido e seu tamanho. Grave os n�meros do vetor, um por linha, 
	em um arquivo tipo texto de nome "numeros.txt".    
*/

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>


void GravaArquivo(int vet[], int tam){ //Void respons�vel por gravar o vetor num arquivo txt
	FILE *arq = fopen("numeros.txt", "at"); //Abre o arquivo
	arq == NULL?printf("Erro de abertura!"):system("pause"); //Operador tern�rio respons�vel por verificar a abertura do arquivo com �xito
	
	for(int i=0; i<tam; i++){ //A grava��o ser� feita enquanto o contador for menor que o tamanho do vetor
		fflush(stdin); //Limpa o buffer
		fprintf(arq,"%i\n",vet[i]); //Grava a informa��o do vetor de acordo com o indice em quest�o, e pula a linha
	}
	fclose(arq); //Fecha o arquivo
	printf("\nArquivo gravado\n");
}

int main(){
	srand(time(NULL)); //Coleta a hora de execu��o 
	int tam, i; //Variavel de tamanho, e contador
	printf("Informe o tamanho do vetor: "); //� solicitado ao usu�rio que forne�a um tamanho para o vetor
	scanf("%i",&tam); //Captura do valor da variavel tam
	int vetor[tam]; //Declara��o e atribui��o de tamanho ao vetor, de acordo com o tamanho fornecido pelo usu�rio
	
	for(i=0;i<tam;i++){ //Preenchimento do vetor com n�meros aleat�rios
        vetor[i]= rand()% 50+1; //Numeros de 0 a 50 ser�o sortidos para preencher o vetor
        printf("%d\n",vetor[i]);
    }
    
    GravaArquivo(vetor, tam); //Passagem de par�metros ao void
      
}


