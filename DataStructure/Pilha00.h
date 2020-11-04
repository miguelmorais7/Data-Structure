#define N 50 //modificado do slide original

typedef struct pilha{
        int topo;
        float vet[N];
        }Pilha;

Pilha *pilha_cria(void){
      Pilha *p=(Pilha*)malloc(sizeof(Pilha));
      p->topo= -1;
      return p;
}      
int pilha_cheia(Pilha *p){
    return(p->topo==N-1);
}        
void pilha_push(Pilha *p, float v){
    if(pilha_cheia(p)){
      printf("Capacidade da pilha esgotada.\n");
      //exit (1); //aborta o programa
      return;
      }
      //insere novo elemento
      p->topo++;
      p->vet[p->topo]=v;
       
}              
int pilha_vazia(Pilha *p){
    return(p->topo == -1);
}

float pilha_pop(Pilha *p){
     float v;
     
     //retira o elemento da pilha
     v=p->vet[p->topo];  
     p->topo--;
     return v;
}
void pilha_libera(Pilha *p){
     free(p);
}                           
void pilha_mostra(Pilha *p){
     printf("\nConteudo da pilha\n");
     for(int i=p->topo;i>=0;i--)
         printf("%.0f\n",p->vet[i]);
     printf("\n");
}               
