#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NRMAX 5000

typedef struct
{
    char Nume[36];
    char opt[3];
}studenti;

studenti stud[5000];
int cautare(char nume[])
{
    int i=0,comp=0;
    for(i=0; (i < NRMAX - 1) && (stud[i].Nume != nume); i++);
    {   comp++;
        if (stud[i].Nume == nume ) {

        printf("%d",comp);
    } else {
        return 0;
    }
    }

}
int main()
{
    int i;
    char nume[36];
    studenti s[NRMAX];
    FILE* f=fopen("Studenti.txt","rt");
    if(!f)
    {
        perror("eroare la citire");
        exit(EXIT_FAILURE);
    }
    for( i= 0; i < NRMAX; i ++)
    {
        fgets(s[i].Nume,36,f);
        s[i].Nume[strlen(s[i].Nume)-1]='\0';
        fscanf(f,"%s\n",&s[i].opt);
    }
    scanf("%c",nume);
    cautare(nume);

}

