/*Ex03_N2_EstruturaDeDados
Programador: Miguel Costa de Morais
Data: 18/11/2018
	Enunciado: Escreva uma função que efetue a busca de um determinado 
	elemento (valor) em um vetor (v) de tamanho (tam), já preenchido 
	(pode haver repetição). A função deve retornar o número de vezes que o 
	elemento foi encontrado, ou 0, caso contrário.
	
Protótipo:  int buscaElemento(int  v[], int valor, int tam)  
*/

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>

int buscaElemento(int v[], int valor, int tam){ //Parametros: vetor, valor a ser buscado e tamanho do vetor
	int cont = 0; //Inicializa o contador como 0
	
	//Será realizado o loop enquanto o contador for menor que o tamanho do vetor
	for(int i=0; i<tam; i++){ 
		if(v[i] == valor){ //Se o valor na posição atual do vetor for igual ao parâmetro de busca
			cont++; //Adiciona o numero de vezes que o valor foi encontrado no vetor
		}
	}
	return cont; //Retorna o numero de vezes que o elemento apareceu no vetor
	//Caso o valor não seja encontrado, a função retornará 0, para assim ser feita a verificação no main
}

int main(){
	srand(time(NULL)); //Coleta a hora de execução 
	int tam, i, valor, vezes; //Variavel de tamanho, e contador
	printf("Informe o tamanho do vetor: "); //É solicitado ao usuário que forneça um tamanho para o vetor
	scanf("%i",&tam); //Captura do valor da variavel tam
	
	printf("Informe o valor a ser buscado: ");
	scanf("%i",&valor);
	
	int vetor[tam]; //Declaração e atribuição de tamanho ao vetor, de acordo com o tamanho fornecido pelo usuário
	
	
	for(i=0;i<tam;i++){ //Preenchimento do vetor com números aleatórios
        vetor[i]= rand()% 50+1; //Numeros de 0 a 50 serão sortidos para preencher o vetor
        printf("%d\n",vetor[i]);
    }
    
    vezes = buscaElemento(vetor, valor, tam); 
    printf("O valor requisitado apareceu %i vezes no vetor",vezes);
      
}
