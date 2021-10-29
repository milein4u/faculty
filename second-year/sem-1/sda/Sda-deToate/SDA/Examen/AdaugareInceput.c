#include<stdio.h>
#include<stdlib.h>
typedef struct lista
{
    int nota ; 
     int cod;
    struct lista *next;
}lista;
lista *sfarsit=NULL;
void adaugaLista( int nota , int cod)
{
    lista * q =(lista*)malloc(sizeof(lista));
    lista *aux;
    if(q==NULL)
    {
        printf("as");
    }
    else
    {
         q->nota=nota;
         q->cod=cod;
         q->next=NULL;
         aux=sfarsit;
         while(aux!=NULL)
         {
             aux=aux->next;
             aux->next=q;
             printf("da");
         }
    }
}
void afisare(lista *l)
{
    lista *m=l;
    for(m;m!=NULL;m=m->next)
    {
        printf("%d %d",m->nota,m->cod);
        printf("\n");
        m=m->next;
    }
}
int main()
{
   
    adaugaLista(2,412);
    adaugaLista(3,12);
    adaugaLista(6,89);
    afisare(sfarsit);
}