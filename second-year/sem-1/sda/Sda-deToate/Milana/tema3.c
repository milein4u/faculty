#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char nume[35];
float medie;
}student;
void citire(student s[],char a[])
{   int i=0;
    FILE *f=fopen("Studenti2.txt","r");
    if(!f)
    {
        printf("eroare la citire");
        exit(EXIT_FAILURE);
    }
    while(i<5000)
    {
        fgets(a,35,f);
        a[strcspn(a,"\n")]='\0';
        strcpy(s[i].nume,a);
        fscanf(f,"%f\n",&s[i].medie);
        i++;
    }
    free(s);
}
void sortareSelectie(student s[])
{
int i,j,min=5000;
student temp;
    for( i= 0; i <=min-2; i ++)
    {
        min= i; temp= s[i];
    for( j= i+1; j < min; j ++)
    if (s[j].medie>temp.medie)
    {
        min= j;
        temp= s[j];
    }
        s[min]= s[i];
        s[i]= temp;
    }
}
void sortareSelectie2(student s[])
{
    int i, j, first,max = 5000;
    student temp;
        for (i= max - 1; i > 0; i--)
      {
              first = 0;
              for (j=1; j<=i; j++)
             {
                      if (s[j].medie < s[first].medie)
                      first = j;
             }
        temp = s[first];
        s[first] = s[i];
        s[i] = temp;
     }

}

void bubblesort(student s[])
{
    int i,j,max=5000;
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

int main()
{

    student s[5000];
    char a[35];
    citire(s,a);
    sortareSelectie(s);
    for(int i=0;i<5000;i++)
    {
        printf("%d. %s \n",i,s[i].nume);
        printf("%f\n",s[i].medie);
    }
    sortareSelectie2(s);
    for(int i=0;i<5000;i++)
    {
        printf("%d. %s \n",i,s[i].nume);
        printf("%f\n",s[i].medie);
    }
    bubblesort(s);
    for(int i=0;i<5000;i++)
    {
        printf("%d. %s \n",i,s[i].nume);
        printf("%f\n",s[i].medie);
    }

    return 0;
}
