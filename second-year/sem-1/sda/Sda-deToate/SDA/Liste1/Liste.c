#include<stdio.h>
#include<stdlib.h>
typedef struct biblioteca
{
    char *titluCarte;
    char *autorCarte;
    char *numeCititor;
    char *adresaCititor;
    int termen;
    struct biblioteca *urmator;
}biblioteca;
int vidare()
{
    int contor=0;
    contor++;
    return contor;
}
biblioteca*imprumut_nou(biblioteca* rad,char titluCarte,char autorCarte,char numeCititor,char adresaCititor,int termen )
{
    biblioteca *p;
    if(p->numeCititor!=numeCititor)
    {
    p = (biblioteca*)malloc(sizeof(biblioteca));
    p->titluCarte= (char*) malloc(strlen(titluCarte)+1);
    strcpy(p->titluCarte,titluCarte);

    p->autorCarte=(char*) malloc(strlen(autorCarte)+1);
    strcpy(p->autorCarte,autorCarte);

    p->numeCititor=(char*) malloc(strlen(numeCititor)+1);
    strcpy(p->numeCititor,numeCititor);

    p->adresaCititor=(char*)malloc(strlen(adresaCititor)+1);
    strcpy(p->adresaCititor,adresaCititor);

    p->termen=(char*)malloc(strlen(termen)+1);
    strcpy(p->termen,termen);

    p->urmator=NULL;
    vidare();
    }
    else
    {
        printf("Nu se poate efectua imprumutul");
        exit(0);
    }
}
biblioteca* returnare(biblioteca* rad , char *nume)
{
    biblioteca *rad1,*q;
    if(rad1!=NULL)
    {
        if(strcmp(rad->numeCititor,nume)==0)
        {
            rad1=rad;
            rad=rad->urmator;
            free(rad1->numeCititor);
            free(rad);
            return rad;
        }
        rad1=rad;
        while(rad1!=NULL && strcmp(rad1->numeCititor,nume)!=0)
        {
            rad1=rad->urmator;
        }
        if(rad1!=NULL && strcmp(rad1->numeCititor,nume)==0)
        {
            rad1=q->urmator;
            q->urmator=q->urmator->urmator;
            free(rad1->numeCititor);
            free(rad1);
        }
        return rad;
    }
    else
    return rad;
}
void afisare(biblioteca* rad)
{
    biblioteca *q=rad;
    while(rad!=NULL)
    {
        printf("\nTitlu Carte:\n%s \nAutor Carte:\n%s \nNume Citior\n%s \nTermenul:%d",q->titluCarte,q->autorCarte,q->numeCititor,q->termen);
        q=q->urmator;
    }
}
int main(){
char opt;
biblioteca *prim,*p;
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
