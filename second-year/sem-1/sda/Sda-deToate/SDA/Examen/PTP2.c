#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define lungime 30
#define MAX 45
#define len 8
typedef struct elev 
{
    int varsta;
    double note[len];
    char nume[MAX];
}el;
typedef struct profesor
{
    int contor;
    char nume[MAX];
    char numeMaterie[MAX];
    struct elev lista[lungime];
    struct profesor *next;
}prof;
prof* adaugaProf(prof *head,char nume[MAX] ,char numeMaterie[MAX])
{
    prof *p =(prof*)malloc(sizeof(prof));
    strcpy(p->nume,nume);
    strcpy(p->numeMaterie,numeMaterie);
    p->next=head;
    head=p;
    return p;
}
el* adaugaElev(int varsta, char nume[MAX],double note[MAX])
{
    el* elNou= (el*)malloc(sizeof(el));
    strcpy(elNou->nume,nume);
    elNou->varsta=varsta;
    for(int i=0;i<len;i++)
    {
        elNou->note[i]=note[i];
    }
    return elNou;
}
double calculMedieElevi(prof *p)
{
    prof *t=p;
    double suma=0;
    int count=0;
   
    for(int j=0;j<t->contor;j++)
    {
         size_t size=sizeof(t->lista[j].note[j]);
        for(int i=0;i<size;i++)
        {
            suma+=t->lista[j].note[i];
            count++;
        }
    }
    double medie=0;
    medie+=suma/count;
    return medie;
}
void addElev(prof *p, el *elev)
{
    prof *pp;
    for(pp=p;pp!=NULL;pp=pp->next)
    {
        if(pp->contor<lungime)
        {
            pp->lista[pp->contor]=*elev;
            pp->contor++;
            return;
        }
        else 
        {
            printf("\nNu mai este loc pentru a adauga studenti!");
            return;
        }
    }
}
void bubbleSort(prof *P,int n)
{
    char temp[MAX];
    for (int j=0; j<n-1; j++) 
    {
        for (int i=j+1; i<n; i++) 
        { 
            if (strcmp(P->lista[j].nume, P->lista[i].nume) > 0)
            {
                strcpy(temp,P->lista[j].nume); 
                strcpy(P->lista[j].nume,P->lista[i].nume); 
                strcpy(P->lista[i].nume,temp); 
            }
        }
    }
}
void afisareLista(prof *head)
{
    prof *lista=head;
    int n;
    n=lista->contor;
    bubbleSort(lista,n);
    for(lista;lista!=NULL;lista=lista->next)
    {
        printf("Nume Profesor :%s \nNume disciplina: %s\nElevi:",lista->nume,lista->numeMaterie);
        printf("\n");
        for(int i=0;i<lista->contor;i++)
        {
            printf("Nume elev : %s\n Varsta elev: %d\n Note elev: \n",lista->lista[i].nume,lista->lista[i].varsta);
            size_t size = sizeof(lista->lista[i].note[i]);
           for(int j=0;j<size;j++)
           {
               printf("%f \n",lista->lista[i].note[j]);
           }
            printf("\n");
        }
    }
}
int main()
{
    prof *p=NULL;
    el *e1 = NULL,*e2=NULL,*e3=NULL,*e4=NULL,*e5=NULL;
    double note[]={7.2,3.4,5.6,10.0,9,8,6.7,3.4};
    double note2[]={3.4,4.5,10.0,9.4};
    double note3[]={9.0,8.7,5.6,10};
    double note4[]={2.3,6.7,8.9,2.4,5.6,7.8,2.1,8.77};
    double note5[]={5.66,7.7,10,8,9,1.2,4.55,8.99};
    e1=adaugaElev(14,"Popescu Andrei",note);
    e2=adaugaElev(16,"Pop Vlad",note2);
    e3=adaugaElev(13,"Contra Patrik",note3);
    e4=adaugaElev(20,"Suciu Denisa",note4);
    e5=adaugaElev(23,"Avramescu Andrei",note5);
    p=adaugaProf(p,"Contra Alex","SDA");
    addElev(p,e1);
    addElev(p,e2);
    addElev(p,e3);
    addElev(p,e4);
    addElev(p,e5);
   afisareLista(p);
    printf("Media tuturor elevilor este: %f \n",calculMedieElevi(p));
    return 0;
}