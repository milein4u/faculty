#include <stdio.h>
#include <stdlib.h>
typedef struct
{
};

void bubblesort(int a[], int n)
{
    int i,j, temp;
    for( i= 0; i <n; i ++)
    {                                            
      for( j= n-1; j>i; j --)
        if (a[j-1]>a[j])
          {
            temp= a[j-1]; 
            a[j-1]= a[j]; 
            a[j]= temp;
          }  
    }  
} 
void Afisare(int Vector[],  int n)
{
    for(int i =1 ; i<n; i++)
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
  
    bubblesort(VECTOR,n);
    Afisare(VECTOR,n);
}