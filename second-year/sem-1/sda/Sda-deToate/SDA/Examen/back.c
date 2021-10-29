#include<stdio.h>
#include<stdlib.h>
#define len
int n,p,sol[10];
void back(int k)
{
    if(k==p+1)
    {
        for(int i=0;i<=p;i++)
        {
            printf("%d \n",sol[i]);
        }
    }
        else
        {
                if(k>1)
                {
                    sol[k]=sol[k-1];
                }else
                {
                 sol[k]=0;
                 while(sol[k]<n-p+k)
                 {
                     sol[k]++;
                     back(k+1);
                 }   
                }
        }
        
    
}
void afisare()
{
    size_t size = sizeof(sol);
    for(int i=0;i<size;i++)
    {
        printf("%d \n",sol[i]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    back(1);
    afisare();
    return 0;
}