#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Jucator
{
    char *numeJucator[30];
    int *varsataJucator;
    struct Jucator *next;
}jucator;
typedef struct Echipa
{
    jucator **jucatori;
    char numeEchipa[30];
    int nrMaxJucatori;
    int nrJucatoriCurenti;
    struct Echipa *next;
}echipa;
echipa* addEchipa(echipa *echipa1,char numeE[30],int nrMaxJucatori)
{

    echipa *nou=(echipa*)malloc(sizeof(echipa));
    strcpy(nou->numeEchipa,numeE);
    nou->nrMaxJucatori=nrMaxJucatori;
    nou->next=echipa1;
    echipa1=nou;
    return echipa1;
}
void afisareListaEchipe(echipa *ech)
{
    echipa *q=ech;
    printf("Numele echipei este: %s",ech->numeEchipa);
    for(int i=0;i<ech->nrJucatoriCurenti;i++)
    {
        printf("Nume jucator %d : %s \n Varsta %d",i,ech->jucatori[i]->numeJucator,ech->jucatori[i]->varsataJucator);
    }
}
jucator* addJucator(echipa *echipa1,jucator *juc)
{
    /*if(echipa1->nrJucatoriCurenti==echipa1->nrMaxJucatori)
    {
        echipa1->nrMaxJucatori*=2;
        echipa1->jucatori=(jucator**)realloc(echipa1->jucatori,sizeof(jucator)*echipa1->nrMaxJucatori);
    }*/
    echipa1->jucatori[echipa1->nrJucatoriCurenti]=juc;
    echipa1->nrJucatoriCurenti++;
}
int main()
{
    echipa *echipaa=(echipa*)malloc(sizeof(echipa));
    echipa *echipa1=(echipa*)malloc(sizeof(echipa*));
    addEchipa(echipaa,"Echipa1",12);
    addEchipa(echipa1,"Echipa2",13);
    //
    jucator **jucatorr=NULL;
    strcpy(jucatorr->numeJucator,"Alex");
    jucatorr->varsataJucator=20;
    //
    addJucator(echipaa,jucatorr);
    afisareListaEchipe(echipaa);
    return 0;
}