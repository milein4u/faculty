#include<stdio.h>
#include <stdlib.h>
void BubbleSort(int Vector[], int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j= N-1; j>i; j --)
        {
            if(Vector[j-1]>Vector[j])
            {
                int aux =Vector[j-1];
                Vector[j-1]=Vector[j];
                Vector[j]=aux;
            }
        }
    }
}
void Afisare(int Vector[],  int n)
{
    for(int i = 0 ; i<n; i++)
    {
        printf("%d " , Vector[i]);
       
    }   
}
int main()
{
    int VECTOR[10];
    int n;
    printf("introduceti nr =");
    scanf("%d",&n);
    for(int i=0 ;i<n;i++)
    {
        scanf("%d ", &VECTOR[i]);
       
    }
  
    BubbleSort(VECTOR,n);
    Afisare(VECTOR,n);
}

