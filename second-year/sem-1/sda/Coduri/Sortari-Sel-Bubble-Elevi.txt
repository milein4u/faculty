#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
char nume[35];
float medie;
}student;

void sortareSelectie(student s[])
{
int i,j,max=5000;
student temp;
    for( i= 0; i <=max-2; i ++)
    {
        max= i; temp= s[i];
    for( j= i+1; j < max; j ++)
    if (s[j].medie>temp.medie)
    {
        max= j;
        temp= s[j];
    }
        s[max]= s[i];
        s[i]= temp;
    }
}

void bubblesort(student s[])
{
    int i,j,max=500;
    student temp;
for( i= 0; i < max; i ++)
{
    for( j= max-1; j>i; j --)
        if (s[j-1].nume>s[j].nume)
        {
        temp= s[j-1];
        s[j-1]= s[j];
        s[j]= temp;
        }
    }
}

/*int main()
{
    int i;
    student s[5000];
    FILE* f=fopen("Studenti2.txt","rt");
    if(!f)
    {
        perror("eroare la citire");
        exit(EXIT_FAILURE);
    }
    for( i= 0; i < 5000; i ++)
    {
        fgets(s[i].nume,35,f);
        s[i].nume[strlen(s[i].nume)-1]='\0';
        fscanf(f,"%f\n",&s[i].medie);
    }
    bubblesort(s);
    sortareSelectie(s);

    for(i=0;i<5000;i++)
    {
        printf("%d. %s \n",i,s[i].nume);
        printf("%f\n",s[i].medie);
    }
    for( i=5000; i>0; i--)
    {
        fgets(s[i].nume,35,f);
        s[i].nume[strlen(s[i].nume)-1]='\0';
        fscanf(f,"%f\n",&s[i].medie);
    }
    bubblesort(s);
    sortareSelectie(s);

    for(i=0;i<5000;i++)
    {
        printf("%d. %s \n",i,s[i].nume);
        printf("%f\n",s[i].medie);
    }
}*/
