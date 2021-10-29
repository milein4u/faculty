#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NRMAX 50

typedef struct LAB3
{   
    char Nume[15];
    char opt[2];
}studenti;
void bubblesort(studenti s[])
{
    int i,j; 
    studenti temp;
for( i= 0; i < NRMAX; i ++)
{
    for( j= NRMAX-1; j>i; j --)
        if (s[j-1].Nume>s[j].Nume)
        {
        temp= s[j-1];   
        s[j-1]= s[j];
        s[j]= temp;
        }
    }
}
int main()
{
    int i;
    char OPTIONAL[]="c4";
    studenti s[NRMAX];
    FILE* f=fopen("Studenti2.txt","rt");
    if(!f)
    {
        perror("eroare la citire");
        exit(EXIT_FAILURE);
    }
    for( i= 0; i < NRMAX; i ++)
    {
        fgets(s[i].Nume,30,f);
        s[i].Nume[strlen(s[i].Nume)-1]='\0';
        fscanf(f,"%s\n",&s[i].opt);
    }
    bubblesort(s);
    for(i=0;i<=NRMAX;i++)
    {
    if(strcmp(s[i].opt,"c4"))
    {
        printf("%s \n",s[i].Nume);
        printf("%s\n",s[i].opt);
    }
    }
}

