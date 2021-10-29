#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void joc()
{
    int nrRunde; 
    int sumaStart;  
    printf("\nNumarul de runde este :\n");
    scanf("%d",&nrRunde);
    printf("Introduceti suma de start:\n");
    scanf("%d",&sumaStart);
    printf("Suma de start este: %d",sumaStart);
    printf("\n");
    srand(time(0));
    int b =rand()%10000;
    for(int i=0 ;i<nrRunde; i++)
    {
        printf(" %d ",b);
        if(b<sumaStart)
        {
            printf("\nAi pierdut bani!\n");
        }
    }
        if(b>sumaStart)
        {
        joc();
        }
}
int main()
{
   joc();
   return 0;
}