/*Ex02_N2_EstruturaDeDados
Programador: Miguel Costa de Morais
Data: 18/11/2018
	Enunciado: Escreva uma função que receba um vetor de números inteiros, 
	já preenchido e seu tamanho. Grave os números do vetor, um por linha, 
	em um arquivo tipo texto de nome "numeros.txt".    
*/

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>


void GravaArquivo(int vet[], int tam){ //Void responsável por gravar o vetor num arquivo txt
	FILE *arq = fopen("numeros.txt", "at"); //Abre o arquivo
	arq == NULL?printf("Erro de abertura!"):system("pause"); //Operador ternário responsável por verificar a abertura do arquivo com êxito
	
	for(int i=0; i<tam; i++){ //A gravação será feita enquanto o contador for menor que o tamanho do vetor
		fflush(stdin); //Limpa o buffer
		fprintf(arq,"%i\n",vet[i]); //Grava a informação do vetor de acordo com o indice em questão, e pula a linha
	}
	fclose(arq); //Fecha o arquivo
	printf("\nArquivo gravado\n");
}

int main(){
	srand(time(NULL)); //Coleta a hora de execução 
	int tam, i; //Variavel de tamanho, e contador
	printf("Informe o tamanho do vetor: "); //É solicitado ao usuário que forneça um tamanho para o vetor
	scanf("%i",&tam); //Captura do valor da variavel tam
	int vetor[tam]; //Declaração e atribuição de tamanho ao vetor, de acordo com o tamanho fornecido pelo usuário
	
	for(i=0;i<tam;i++){ //Preenchimento do vetor com números aleatórios
        vetor[i]= rand()% 50+1; //Numeros de 0 a 50 serão sortidos para preencher o vetor
        printf("%d\n",vetor[i]);
    }
    
    GravaArquivo(vetor, tam); //Passagem de parâmetros ao void
      
}


