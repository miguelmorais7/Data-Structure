/*Ex04_N2_EstruturaDeDados
Programador: Miguel Costa de Morais
Data: 18/11/2018
	Enunciado: Escreva uma função que mostre a matricula e a nota dos 
	elementos da árvore que tenham nota acima da nota passada por parâmetro. 
	
Protótipo:  void mostraNotas(Arv *Tree, float nota)  
*/

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>

typedef struct arv{
	int matricula;
	float nota;
	struct arv *left, *right;
}Arv;

Arv *arv_cria(){
	return NULL; 
}
void mostraNotas(Arv *Tree, float nota){ //Parametros: arvore e nota
	if(Tree != NULL){ //Se a arvore não estiver vazia
		//Se o valor nota contido na arvore, for maior que o valor passado como parâmetro
		if(Tree->nota > nota){
			printf("Matricula: %d\t\tNota: %.1f\n",Tree->matricula, Tree->nota); 
			//Exibe matriculas com as notas maiores que a nota passada como parâmetro
		}
		mostraNotas(Tree->left,nota); //Chamadas recursivas
		mostraNotas(Tree->right,nota);
	}
}

Arv *arv_insere(Arv *a, int matricula, float nota){
	if(a==NULL){ 
		a=(Arv *)malloc(sizeof(Arv)); 
		a->matricula = matricula;     
		a->nota = nota;               
		a->left = a->right = NULL;    
	} else if (nota < a->nota)
		a->left = arv_insere(a->left,matricula,nota);
	else
		a->right = arv_insere(a->right,matricula,nota);
	return a;
}

int main(){
	srand(time(NULL));
	float nota;
	Arv *a = arv_cria();
	
	for(int cont=0;cont<15;cont++){
		a = arv_insere(a,rand()%999+1001,rand()%11);
	}
	printf("Procurar notas acima de: ");
	scanf("%f",&nota);
	mostraNotas(a,nota);
}
