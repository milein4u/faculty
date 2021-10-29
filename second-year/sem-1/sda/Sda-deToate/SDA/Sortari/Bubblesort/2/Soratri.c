#include<stdio.h>
#include<stdlib.h>
/*typedef struct 
{
    int index;
    char vector[25];
}studenti;
studenti a[10];*/
FILE *f;
char vec[100];
int citire()
{

    f=fopen("Studenti1.txt", "r");
    while(fgets(vec,100,f)!=NULL)
    {
        return 1;
    }
}
void bubblesort(char vector[], int n)
{
    int i,j;
    char temp;
    for( i= 0; i < n; i ++)
    {                                            
      for( j= n-1; j>i; j --)
        if(vector[j-1 ]> vector[j])
          {
            temp= vector[j-1]; 
            vector[j-1]= vector[j]; 
            vector[j]= temp;
          }  
    }  
} 
int main()
{

    citire();
    bubblesort();
    return 0;
}
