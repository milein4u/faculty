#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct elev
{
    int varsta;
    char nume[30];
    struct elev *next;
}elev;
elev *curentLista=NULL;
void afisareLista(elev *Elevi)
{
    elev *q=Elevi;
    while(q!=NULL)
    {
        printf("\nNumele elevului: %s \nVarsta elevului: %d",q->nume,q->varsta);
        printf("\n");
        q=q->next;
    }
}
elev* adaugareLaInceput(elev *Elev,int varstaElev,char numeElev[30])
{
    elev *nou=(elev*)malloc(sizeof(elev)); 
    strcpy(nou->nume,numeElev);
    nou->varsta=varstaElev;
    nou->next=Elev;
    Elev=nou;
    return Elev;
}
/*elev* adaugareLaSfarsit(elev *Elevi ,int varstaElev,char numeElev[30])
{
    elev *nou=(elev*)malloc(sizeof(elev));
    
    strcpy(nou->nume,numeElev);
    nou->varsta=varstaElev;
    nou->next=NULL;
    if(Elevi==NULL)
    {
        Elevi=nou;
    }
    else
    {
        elev *curent=Elevi;
        while(curent->next!=NULL)
        {
            curent=curent->next;
            curent->next=nou;
        }
    }
    return Elevi;
}*/
elev* cautareDupaNume(elev *lista, char numeElev[40])
{
    elev* ll = NULL;
    ll=lista;
    if(lista==NULL)
    {
        printf("Lista inexistenta!");
    }
    while(strcmp(ll->nume,numeElev)!=0)
    {
        if(ll->next==NULL)
        {
            printf("Nu exista elevul in sistem!\n");
            break;
        }
        else
        {
            ll=ll->next;
                if(strcmp(ll->nume,numeElev)==0)
                {
                printf("Elevul cautat de dumneavoastra este:\n");
                printf("Numele: %s\nVarsta:%d\n",ll->nume,ll->varsta);
                }
        }
    }
    return ll;
}
elev* stergereLista(elev *lista , char numeElev[40])
{
    elev *l,*p= NULL;
    l=lista;
    if(lista==NULL)
    {
        printf("Lista de elevi este goala");
    }
    while(l->next!=NULL)
    {
        l=l->next;
        if(strcmp(l->nume,numeElev)==0)
        {
            p=l->next;
            l->next=l->next->next;
            free(p);
            break;
        }
    }
    printf("Elevul sters din lista este: %s",l->nume);
    return lista;
}
int main()
{
    elev *Lista=NULL;
    Lista=adaugareLaInceput(Lista,13,"Patrik");
    Lista=adaugareLaInceput(Lista,17,"Alex");
    Lista=adaugareLaInceput(Lista,20,"Denisa");
    Lista=adaugareLaInceput(Lista,15,"Andrei");
    afisareLista(Lista);
    printf("\n");
    elev *Lista2=NULL;
    Lista2=adaugareLaInceput(Lista2,20,"Andreea");
    Lista2=adaugareLaInceput(Lista2,12,"Marian");
    afisareLista(Lista2);
    printf("\n");
    cautareDupaNume(Lista2,"Patrik");
    cautareDupaNume(Lista,"Marian");
    cautareDupaNume(Lista,"Alex");
    stergereLista(Lista,"Alex");
    afisareLista(Lista);
    return 0;
}