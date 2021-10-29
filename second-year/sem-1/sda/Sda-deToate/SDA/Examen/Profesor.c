#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define lungime 40
#define note 1
typedef struct student
{
    int varstaStudent;
    double bonusPrezente;
    int contor;
    int nota; 
    double medie;
    char numeStudent[lungime];
    double listaNote[note];
    struct student *next;
}stud;
typedef struct Profesor
{
    char numeProfesor[lungime];
    int contor;
    stud lista[lungime];
    struct Profesor *next;
}prof;
prof* addProfesor(prof *rad,char numeProf[lungime])
{
    prof* profesor = (prof*)malloc(sizeof(prof));
    profesor->contor=0;
    strcpy(profesor->numeProfesor,numeProf);
    profesor->next=rad;
    rad=profesor;
    return rad;
}
stud* createStudent(char numeStud[lungime],int varstaStud,double punctPrezente)
{
    stud *student=(stud*)malloc(sizeof(stud));
    strcpy(student->numeStudent,numeStud);
    student->contor=0;
    student->bonusPrezente=punc tPrezente;
    student->varstaStudent=varstaStud;
    return student;
}
void creazaSitutatie(stud *student,int nota)
{
        stud *s ;
        s=student;
        if(s->contor<note)
        {
        s->listaNote[s->contor]=nota;
        s->contor++;
        for(int i=0;i<s->contor;i++)
            {
                int sum=0;
                sum+=s->listaNote[i];
                s->medie=sum/s->contor;
                s->medie+=s->bonusPrezente;
            }
        }
        else
        {
         printf("Nu se mai accepta note!");
        } 
}
void addStudent(prof *profesor , stud *student)
{
    prof *p;
    for(p=profesor;p!=NULL;p=p->next)
    {
        if(p->contor>lungime)
        {
            printf("Nu mai exista loc in clasa");
        }
        else
        {
                p->lista[p->contor]=*student;
                p->contor++;
        }
    }
}
void afisareCatalog(prof *profesor)
{
    prof *p;
    for(p=profesor;p!=NULL;p=p->next)
    {
        printf("\nNumele profesorului: %s\n",p->numeProfesor);
        for(int i=0;i<p->contor;i++)
        {
            printf("\nNumele Studentlui: %s \n Varsta acestuia: %d\nPunctaj pe prezente: %.3f",p->lista[i].numeStudent,p->lista[i].varstaStudent,p->lista[i].bonusPrezente);
            printf("\nLista note :\n");
            printf("%.3f",p->lista[i].listaNote[i]);
            printf("\nMedia: %.4f\n",p->lista[i].medie);
        }
    }
}
int main()
{
    prof *Profesor=NULL;
    Profesor=addProfesor(Profesor,"Stangaciu Cristina");
    stud *student1 =NULL;
    stud *student2=NULL;
    stud *student3=NULL;
    //
    student1=createStudent("Contra Alexandru",21,0.8);
   
    student3=createStudent("Cojocariu Flavius",20,1.1);
    
    creazaSitutatie(student1,10.000);
    creazaSitutatie(student1,7.324);
    creazaSitutatie(student1,2.657);
    creazaSitutatie(student1,1.239);

    creazaSitutatie(student2,9.081);
    creazaSitutatie(student2,3.921);
    creazaSitutatie(student2,10.345);


  
    addStudent(Profesor,student1);
    addStudent(Profesor,student2);

    //
    afisareCatalog(Profesor);
    return 0;
}
