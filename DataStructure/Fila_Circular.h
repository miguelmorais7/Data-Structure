//fila circular
typedef struct{
	float *Vetor; //ponteiro para o vetor
	int tamVetor; //tamanho do vetor
	//----------------------------
	int tamFila;  //tamanho da fila
	//----------------------------
	int inicio;   //posição de inicio
	int fim;      //posição final
} Fila;

Fila *fila_cria(){
	Fila *f=(Fila*)malloc(sizeof(Fila)); //Aloca a fila
	f->tamVetor=5; //tamanho do vetor
	f->tamFila=0; //inicializa o tamanho com zero
	f->inicio=0;
	f->fim=0;
	f->Vetor=(float*)malloc(sizeof(float)*f->tamVetor); //Aloca o vetor
	return f;
}

int fila_vazia(Fila *f){ //Teste de fila vazia
	if(f->tamFila==0) return 1;
	return 0;
}

void fila_insere(Fila *f, float v){
	if(f->tamFila==f->tamVetor){
		printf("Fila cheia\n");
		return;
		//Então cabe!!
	}
	if(f->fim==f->tamVetor){ //Se a ultima posição estiver ocupada 
		f->fim=0; //Liga o aspecto circular da fila
	}
	f->Vetor[f->fim]=v; //Coloca o elemento na posição apontada pelo fim 
	f->fim++; //Incrementa o fim
	f->tamFila++; //Incrementa o tamanho da fila
}

float fila_retira(Fila *f){
	float v;
	v=f->Vetor[f->inicio];
	if(f->inicio==f->tamVetor-1){ //Ultima indice
		f->inicio=0; //fila deixa de circular
	}
	else{
		f->inicio++;
	}
	f->tamFila--; //Diminui o tamanho da fila
	return v;
}

void fila_libera(Fila *f){
	free(f->Vetor); //Libera o espaço ocupado pelo vetor
	free(f); //Libera a fila
}

void mostra_fila(Fila *f){
	if(f->tamFila==0){
		printf("Fila vazia!\n");
	}
	else{
		if(f->inicio < f->fim){ //Não circulou!!
			for(int i = f->inicio; i < f->fim; i++){
				printf("%.0f\n", f->Vetor[i]);
			}
		}
		else{ //Circulou!!
			for(int i = f->inicio; i < f->tamVetor; i++){
				printf("%.0f\n", f->Vetor[i]);
			}
			for(int i = 0; i < f->fim; i++){
				printf("%.0f\n", f->Vetor[i]);
			}
		}
	}
}

















