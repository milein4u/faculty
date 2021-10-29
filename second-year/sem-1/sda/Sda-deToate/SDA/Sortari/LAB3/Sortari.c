#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#define n 2500
FILE *f;
typedef struct masuratori
{
    int index;
    float inaltime ;
    float greutate;
}masuratori;
masuratori m[2000];
//Sorteaza descrescator in functie de inaltime
void citire()
    {
        char stack[n];
        f=fopen("hw_25000r.txt","r");
        while(!f)
        {
            printf("FILE NOT FOUND!");
            fclose(f);
            exit(EXIT_FAILURE);
        }
        fgets(stack, 250 ,f);
        int i =0;
        while(!feof(f))
        {
            fscanf("%d",&m[i].index);
            fscanf("%f",&m[i].inaltime);
            fscanf("%f\n",&m[i].greutate);
        }
   }
