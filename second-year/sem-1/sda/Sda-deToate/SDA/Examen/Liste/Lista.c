#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define lungime 10
#define MAX 30
typedef struct Muncitor
{
    int cheie;
}Muncitor;
typedef struct Echipa
{
    char nume[MAX];
    int contor;
    Muncitor echipa[lungime];
    struct Echipa *next;
}Echipa;
Echipa* addEchipa(Echipa *ech,char nume[MAX])
{   
    Echipa *nou = (Echipa*)malloc(sizeof(Echipa));
    strcpy(nou->nume,nume);
    nou->next=ech;
    ech=nou;
    return nou;
}
Muncitor* addMuncitor( int cheie)
{
    Muncitor *m = (Muncitor*)malloc(sizeof(Muncitor));
    m->cheie=cheie;
    return m;
}
void addMinE(Echipa *e,Muncitor *m)
{
    Echipa *ee;
    for(ee=e;e!=NULL;e=e->next)
    {
        if(ee->contor<lungime)
        {
            ee->echipa[ee->contor]=*m;
            ee->contor++;
            return;
        }   
    }
}
void afisare(Echipa *ech)
{
    Echipa *e = ech;
    for(e;e!=NULL;e=e->next)
    {
        printf("Numele echipei este: %s\n",e->nume);
        for(int i=0;i<e->contor;i++)
        {
            printf("ID muncitor %d %d\n",i,e->echipa[i].cheie);
        }
    }
}
void concediaza(Echipa *ech,int ID)
{
   Echipa *aux = ech;
   Echipa *prev;
    for(int j=0;j<aux->contor;j++){
    if(aux !=NULL && aux->echipa[j].cheie==ID)
       {
           ech=aux->next;
           free(aux);
           return;
       }
    }
    for(int i=0;i<aux->contor;i++)
    {
        while(aux !=NULL && aux->echipa[i].cheie==ID)
        {
            prev=aux;
            aux=aux->next;
        }
    }
    if(aux==NULL)
    {
        return;
    }
    prev->next=aux->next;
    free(aux);
   
}
int main()
{
    Echipa *ech = NULL;
    ech=addEchipa(ech,"SC Muncitori SRL");
    Muncitor *m1=NULL ,*m2=NULL,*m3=NULL,*m4=NULL;
    m1=addMuncitor(23);
    m2=addMuncitor(76);
    m3=addMuncitor(76);
    m4=addMuncitor(12);
    addMinE(ech,m1);
    addMinE(ech,m2);
    addMinE(ech,m3);
    addMinE(ech,m4);
    concediaza(ech,23);
    afisare(ech);
    return 0;
}