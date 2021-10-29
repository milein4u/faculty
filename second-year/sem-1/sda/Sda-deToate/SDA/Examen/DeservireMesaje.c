#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define lungime 10
typedef struct mesaj
{
    int ID;
    int prioritate;
    char mesaj[100];
}msg;
typedef struct planificator
{
    int contor;
    int prioritate;
    struct mesaj lista[lungime];
    struct plan *next;
}plan;
plan* addProprity(plan *rad , int P)
{
    plan *nou=(plan*)malloc(sizeof(plan));
    nou->contor=0;
    nou->prioritate=P;
    nou->next=rad;
    rad=nou;
}
msg* addMesaj(int ID , int prioritate, char mesaj[100])
{
    msg *nou=(msg*)malloc(sizeof(msg*));
    nou->ID=ID;
    nou->prioritate=prioritate;
    strcpy(nou->mesaj,mesaj);
    return nou;
}
void Mesaj(plan* rad, msg *mesaj)
{
    plan *plan;
    for(plan=rad;plan!=NULL;plan=plan->next)
    {
        if(plan->prioritate==mesaj->prioritate)
        {
            if(plan->contor<lungime)
            {
                plan->lista[plan->contor]=*mesaj;
                plan->contor++;
                return;
            }
            else
            {
                printf("Nu mai este loc!");
                return;
            }
        }
    }
}
void afisare(plan *rad)
{
    plan *p=rad;
    for(p;p!=NULL;p=p->next)
    {
        printf("prioritate coada %d\n",p->prioritate);
        if(p->prioritate==0)
        {
            printf("coada goala\n");
        }
    else
    {
        for(int i=0;i<p->contor;i++)
        {
        printf("MESAJ:\n%s\nPrioritate mesaj: %d\nID mesaj:%d",p->lista[i].mesaj,p->lista[i].prioritate,p->lista[i].ID);
        printf("\n");
        }
    }
}
}
int main()
{
    plan *GESTIUNE=NULL;
    GESTIUNE=addProprity(GESTIUNE,5);
    GESTIUNE=addProprity(GESTIUNE,2);
    GESTIUNE=addProprity(GESTIUNE,9);
    msg *t1=NULL, *t2=NULL,*t3=NULL,*t4=NULL;
    t1=addMesaj(23341,5,"Salut ,cf?");
    t2=addMesaj(122009,2,"BN uh?");
    t3=addMesaj(488977,9,"Cacat");
    t4=addMesaj(90009,5,"Ce ma ? esti prost?");
    Mesaj(GESTIUNE,t1);
    Mesaj(GESTIUNE,t2);
    Mesaj(GESTIUNE,t3);
    Mesaj(GESTIUNE,t4);
    afisare(GESTIUNE);
}
