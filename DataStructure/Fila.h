typedef struct lista{
        float item;
        struct lista *next;
}Lista;
typedef struct{
        Lista *prim;
        Lista *ult;
}Fila;
Fila *fila_cria(){
      Fila *f=(Fila*) malloc(sizeof(Fila));
      f->prim=NULL;
      f->ult=NULL;
      return f;
}
void fila_insere(Fila *f, int v){
     Lista *novo=(Lista*)malloc(sizeof(Lista)); 
     novo->item=v;
     novo->next=NULL;
     if(f->prim==NULL)
        f->prim = novo;
     else
        f->ult->next=novo;
     f->ult=novo;
}
float fila_retira(Fila *f){
    Lista *a=f->prim;
    int v=a->item;
    f->prim=a->next;
    free(a);
    return v;
}
void mostra_fila(Fila *f){
     Lista *a;
     for(a=f->prim;a!=NULL;a=a->next)
         printf ("%.0f\t", a->item);
     printf("\n");
}
int fila_vazia(Fila *f){
    return(f->prim==NULL);
}
void fila_libera(Fila *fi){
     Lista *a=fi->prim;
     while(a!=NULL){
       Lista *t=a;
       a=a->next;
       free(t);
     }
     fi->prim=NULL;
     fi->ult=NULL;
}             
