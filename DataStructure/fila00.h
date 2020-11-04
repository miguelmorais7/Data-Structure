#define N 50
typedef struct { 
    float *Vetor; //ponteiro para o vetor
    int tamVetor;//tamanho do vetor
    int inicio; /* indexa o início da Fila */
    int fim;   /*indexa o final da Fila */
}Fila;
   
Fila *fila_cria(void){
      Fila *f=(Fila*)malloc(sizeof(Fila));
      f->inicio=0;
      f->fim=0;
      f->tamVetor=N;
	  f->Vetor=(float*)malloc(f->tamVetor*sizeof(float));
      return f;
}      
void compacta(Fila *f){
     int i;
     for(i=0;i<f->fim;i++)
         f->Vetor[i]=f->Vetor[i+f->inicio];
     f->fim=f->fim - f->inicio;
     f->inicio=0;
}
         
void fila_insere(Fila *f, float v){
     if(f->fim==f->tamVetor){
         //verifica se há espaço de remoções
         int tamFila= f->fim - f->inicio;
         if(tamFila==f->tamVetor){                     
             printf("Fila cheia!\n");
             return;
         }
         //tem espaço
         compacta(f);
     }
     f->Vetor[f->fim]=v;
     f->fim++;
}
     
int fila_vazia(Fila *f){
    return(f->fim==f->inicio);
}

float fila_retira(Fila *f){
     float v;
     //retira o lemento da fila
     v=f->Vetor[f->inicio];
     f->inicio++;
     return v;
}
void fila_libera(Fila *f){
     free(f->Vetor);
     free(f);
}                           
void mostra_fila(Fila *f){
     printf("Conteudo da fila\n");
     int i;
     for(i=f->inicio;i<f->fim;i++)
              printf("%.0f\n",f->Vetor[i]);
     printf("\n");
}               
