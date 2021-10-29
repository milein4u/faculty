#include<stdio.h>
#include<stdlib.h>
typedef struct bibliotecar
{
char *titlu;
char *autor;
char *nume;
char *adresa;
int termen;
struct bibliotecar *urm;
}nod;

nod *imprumut_nou(nod*prim,char *titlu, char *autor, char *nume, char *adresa, int termen)
{
    nod *q,*p;
    p=(nod*)malloc(sizeof(nod));
    p->titlu=(char*)malloc(strlen(titlu)+1);
    strcpy(p->titlu,titlu);
    p->autor=(char*)malloc(strlen(autor)+1);
    strcpy(p->autor,autor);
    p->nume=(char*)malloc(strlen(nume)+1);
    strcpy(p->nume,nume);
    p->adresa=(char*)malloc(strlen(adresa)+1);
    strcpy(p->adresa,adresa);
    p->termen=termen;
    p->urm=NULL;
    if(p==NULL || p->autor==NULL)
    {
    printf("Eroare la alocare!");
    exit(0); 
    }
    if(p==NULL || p->titlu==NULL)   
    {
    printf("Eroare la alocare!");
    exit(0); 
    }

    if(p==NULL || p->nume==NULL)
    {
    printf("Eroare la alocare!");
    exit(0);
     }

    if(p==NULL || p->adresa==NULL)
    {
    printf("Eroare la alocare!");
    exit(0); 
    }

    if(prim==NULL)
    return p;
    else
    if(strcmp(prim->autor,p->autor)>0)
    {
    p->urm=prim;
    return p; 
    }
    else {
    q=prim;
    while(q->urm!=NULL && strcmp(q->urm->autor,p->autor)<0)
    q=q->urm;
    p->urm=q->urm;
    q->urm=p;
    return prim;
    }

if(prim==NULL)
return p;
else
if(strcmp(prim->titlu,p->titlu)>0)
{
p->urm=prim;
return p; }
else {
q=prim;
while(q->urm!=NULL && strcmp(q->urm->titlu,p->titlu)<0)
q=q->urm;
p->urm=q->urm;
q->urm=p;
return prim;
}

if(prim==NULL)
return p;
else
if(strcmp(prim->nume,p->nume)>0)
{
p->urm=prim;
return p; }
else {
q=prim;
while(q->urm!=NULL && strcmp(q->urm->nume,p->nume)<0)
q=q->urm;
p->urm=q->urm;
q->urm=p;
return prim;
}

if(prim==NULL)
return p;
else
if(strcmp(prim->adresa,p->adresa)>0)
{
p->urm=prim;
return p; }
else {
q=prim;
while(q->urm!=NULL && strcmp(q->urm->adresa,p->adresa)<0)
q=q->urm;
p->urm=q->urm;
q->urm=p;
return prim;
}
}

void afisare(nod *prim){
nod *q;
q=prim;
while(q!=NULL)
{
printf(" %s\n %s\n %s \n%s \n%d \n",q->autor,q->titlu, q->nume, q->adresa, q->termen);
q=q->urm; 
}
}
nod* returnare(nod *prim,char *nume){
nod *q,*p;
    if(prim!=NULL)
    {
    if(strcmp(prim->nume,nume)==0)
    {
    q=prim;
    prim=prim->urm;
    free(q->nume);
    free(q);
    return prim;
    }
    q=prim;

    while(q->urm!=NULL && strcmp(q->urm->nume,nume)!=0)
    q=q->urm;

if(q->urm!=NULL && strcmp(q->urm->nume,nume)==0)
{
p=q->urm;
q->urm=q->urm->urm;
free(p->nume);
free(p);
}
return prim;
}
else
return prim;
}
int main(){
char opt;
nod *prim,*p;
char titlu[10];
char autor[10];
char adresa[10];
char nume[10];
int termen;
prim=NULL;
while(1){

printf("\n1. Imprumut nou");
printf("\n2. Afisarea");
printf("\n3. Returnare");
printf("\n4. Iesire\n");
scanf("%s",&opt);
// fflush(stdin);
switch(opt)
{
case '1':
printf("Titlu:\n");
scanf("%s", &titlu);
printf("Autor:\n");
scanf("%s",&autor);
printf("Nume cititor:\n");
scanf("%s",&nume);
printf("Adresa:\n");
scanf("%s",&adresa);
printf("Termen:\n");
scanf("%d",&termen);

prim=imprumut_nou(prim,titlu,autor, nume, adresa, termen);
break;

case '2':
afisare(prim);
break;

case '3':printf("Introduceti numele cititorului:");
scanf("%s", nume);
prim=returnare(prim,nume);
afisare(prim);
break;

case '4':exit(1);
}
getchar();
}
return 0;
}

