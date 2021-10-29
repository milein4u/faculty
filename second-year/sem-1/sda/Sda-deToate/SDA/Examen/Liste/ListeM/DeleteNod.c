#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define lungime 200
#define MAX_N 40
typedef struct Student
{
    float nota;
    int ID;
    char numeStudent[MAX_N];
}Student;
typedef struct Catalog
{
    int contor;
    char numeSectie[MAX_N];
    struct Catalog *next;
    Student listaStudenti[lungime];
}Catalog;

Catalog* createNewCat(Catalog *c,char numeSectie[MAX_N])
{
    Catalog *new = (Catalog*)malloc(sizeof(Catalog));
    strcpy(new->numeSectie,numeSectie);
    new->next=c;
    c=new;
    return new;
}
Student* createStud(int ID,float nota,char numeStudent[MAX_N])
{
    Student *stud =(Student*)malloc(sizeof(Student));
    stud->nota=nota;
    strcpy(stud->numeStudent,numeStudent);
    stud->ID=ID;
    return stud;
}

void bubblesort(Student tablou[lungime],int size)
{    
        for(int i=0;i<size-1;++i)
        {
            for(int j=0;j<(size-i-1);++j)
            {
                if(tablou[j].nota < tablou[j+1].nota)
                {
                   float aux = tablou[j].nota;
                   tablou[j].nota=tablou[j+1].nota;
                   tablou[j+1].nota=aux;
                }
            }
        }
}
void addStud(Catalog *c ,Student *stud)
{
    Catalog *heap=c;
    for(heap;heap!=NULL;heap=heap->next)
    {
        if(heap->contor<lungime)
        {
            heap->listaStudenti[heap->contor]=*stud;
            heap->contor++;
        }
    }
}
float calculMedie(Catalog *C)
{
    Catalog *c = C;
    int count=0;
    float suma=0;
    for(c;c!=NULL;c=c->next)
    {
        for(int i=0;i<c->contor;i++)
        {
            suma=suma+c->listaStudenti[i].nota;
            count++;
        }
    }
    float medie=(float)suma/count; 
    return medie;
}
void stergeElev(Student tablou[lungime],int ID,int size)
{
    int pos=0;
        for(int i=0;i<size;i++)
        {
            if(tablou[i].ID==ID)
            {
                pos+=i;  
            }
        }
        if(pos>=size+1)
        {
            return;
        }
        else
        {
          for(int i=pos-1;i<size-1;i++)
        {
            tablou[i]=tablou[i+1];
        }
        }
}
void afisareCatalog(Catalog *C)
{
    Catalog *c= C;
    for(c;c!=NULL;c=c->next)
    {
        printf(" Numele sectiei este: %s \n",c->numeSectie);
        for(int i=0;i<c->contor;i++)
        {
            printf("Studentul cu ID : %d  %s are media %.2f",c->listaStudenti[i].ID,c->listaStudenti[i].numeStudent,c->listaStudenti[i].nota);
            printf("\n");
        }
    }
}
int main()
{
    Catalog *c=NULL,*c1=NULL;
    Student *s1 =NULL,*s2=NULL,*s3=NULL,*s4=NULL;
    Student *m1=NULL,*m2=NULL,*m3=NULL,*m4=NULL,*m5=NULL;
    //lista 1
    c=createNewCat(c,"Anul 2 CTI-RO");
    s1=createStud(11,7.8,"Alex Contra");
    s2=createStud(45,9.7,"Constatin Ion Iasmin");
    s3=createStud(23,8.44,"Fedorca Stelian");
    s4=createStud(9,8.9,"Cojocariu Flavius");
    addStud(c,s1);
     addStud(c,s2);
      addStud(c,s3);
       addStud(c,s4);
       int size1=sizeof(c->listaStudenti)/sizeof(c->listaStudenti[0]);
       bubblesort(c->listaStudenti,size1);
    afisareCatalog(c);
    printf("Media pe secita %s :%.2f\n\n",c->numeSectie,calculMedie(c));
    //lista 2 
    c1=createNewCat(c1,"Anul 3 CTI-RO");
    m1=createStud(67,5.66,"Constantin Iulia");
    m2=createStud(101,7.6,"Colhon Bogdan");
    m3=createStud(245,9.11,"Corlan Iulian");
    m4=createStud(47,4.5,"Ciulica Horia");
    m5=createStud(32,9.90,"Codnurari Radu");
    addStud(c1,m1);
    addStud(c1,m2);
    addStud(c1,m3);
    addStud(c1,m4);
    addStud(c1,m5);
    int size=sizeof(c1->listaStudenti)/sizeof(c1->listaStudenti[0]);
    bubblesort(c1->listaStudenti,size);
    afisareCatalog(c1);
    printf("\nMedia pe sectia %s : %.2f ",c1->numeSectie,calculMedie(c1));
    Catalog *c2=c->next;
    stergeElev(c1->listaStudenti,245,size);
    afisareCatalog(c1);
    return 0;
}