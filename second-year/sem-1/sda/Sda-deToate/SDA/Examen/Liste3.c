#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct elev
{
    int varsta;
    char nume[30];
    struct elev *next;
}elev;
elev* adaugaInceput(elev *rad ,int varsta , char numeElev[30])
{
    elev *lista=(elev*)malloc(sizeof(elev));
    strcpy(lista->nume,numeElev);
    lista->varsta=varsta;
    lista->next=rad;
    rad=lista;
    return rad;
}
void afisareLista(elev *list)
{
    elev *q=list;
    while(q!=NULL)
    {
        printf("Numele elevului: %s \n Varsta acestuia : %d ",q->nume,q->varsta);
        printf("\n");
        q=q->next;
    }
}
int main()
{
    elev *lista=NULL;
    lista=adaugaInceput(lista,10,"Alex");
    lista=adaugaInceput(lista,20,"Denisa");
    afisareLista(lista);
    return 0;
}