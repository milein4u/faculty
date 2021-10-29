#include<stdio.h>
#include<stdlib.h>
typedef struct Lista
{
    int data;
    struct Lista *next;
}Lista;
Lista* add(Lista *l,int data)
{
    Lista *m= (Lista*)malloc(sizeof(Lista));
    m->data=data;
    m->next=l;
    l=m;
    return m;
}
void functie(Lista* start)
{

    if(start == NULL)
        return;
    printf("%d ", start->data);

    if(start->next != NULL )
    functie(start->next->next);

    printf("%d ", start->data);
}
void afisareLista(Lista *l)
{
    Lista *m=l;
    for(m;m!=NULL;m=m->next)
    {
        printf(" %d ",m->data);
    }
}
int main()
{
    Lista *l=NULL;

    l=add(l,4);
    l=add(l,3);
    l=add(l,2);
    l=add(l,1);
    afisareLista(l);
    functie(l);
    return 0;
}
