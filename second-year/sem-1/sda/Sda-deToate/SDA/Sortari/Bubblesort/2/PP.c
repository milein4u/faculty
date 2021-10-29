#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NRMAX 6
typedef struct PP
{
    char primulrand[NRMAX];
    int vec;
}numar;

FILE *f;
void bubblesort(numar a[])
{
    int i,j;
   numar temp;
    for( i= 0; i < NRMAX; i ++)
    {                                            
      for( j= NRMAX-1; j>i; j --)
      {
        if(a[j-1 ].vec< a[j].vec)
          {
            temp= a[j-1]; 
            a[j-1]= a[j]; 
            a[j]= temp;
          } 
      }
    } 
}
void sortare_prin_selectie(numar s[])
{
int i,j,max=9999;
    numar temp;
    for( i= 0; i <= NRMAX-2; i ++)
    {
        max= i; temp= s[i];
    for( j= i+1; j < NRMAX; j ++)
    if (s[j].vec>temp.vec)
    {
        max= j; 
        temp= s[j];
    }
        s[max]= s[i];
        s[i]= temp;
    }
}
int main()
{
    numar vect[NRMAX];
    char VECTLS[NRMAX];
    
     f=fopen("Numere.txt", "rt");
     if(!f)
     {
         perror("FILE CANNOT BE OPEN");
         exit(1);
     }
         for(int i=0;i<=NRMAX;i++)
         {
            fgets(vect[i].primulrand,30,f);
            vect[i].primulrand[strlen(vect[i].primulrand-1)]=='\0';
            fscanf(f,"%d \n",&vect[i].vec);
         }
     for(int i=0;i<=NRMAX;i++)
        {
        printf("%s\n",vect[i].primulrand);
        printf("%d\n",vect[i].vec);
        }
       
        bubblesort(vect);
        printf("BUBBLESORT: \n");
        for(int i=0;i<=NRMAX-1;i++)
        {
        printf("%d\n",vect[i].vec);
        }

        //

        printf("SORTARE PRIN INSERTIE:\n");
         sortare_prin_selectie(vect);
         for(int i=0;i<=NRMAX-1;i++)
        {
        printf("%d\n",vect[i].vec);
        }
        printf("\n");
        
}