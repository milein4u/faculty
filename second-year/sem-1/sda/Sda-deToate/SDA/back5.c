#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Se citeste un numar natural n<30. 
Sa se afiseze toate modalitatile de a-l calcula prin adunari sau scaderi ale numerelor 1,2, ...n. 
Fiecare numar de la 1 la n va aparea o singura data �n descompunerea lui n. 
Daca acest lucru nu este posibil, se va afisa mesajul �Imposibil�.
Exemplu:
5=1+2+3+4-5
5=1-2-3+4+5
5=-1+2+3-4+5*/
int v[10000];
int n=11;
int sol[500];
int s(int a[],int n)
{
    int s=0;
    for(;n>=0;s+=a[n--]);
    return s;
}


int valid(int pas)
{
    if(pas==0)
        return 1;
    
    if(abs(sol[pas])-abs(sol[pas-1])==1)
        return 1;
    return 0;
}
void afisare(int pas)
{
    int i;
    printf("%d=%d",n,sol[0]);
    for(i=1;i<=pas;i++)
    {   
        if(sol[i]<=0)
            printf("%d",sol[i]);
            else 
                printf("+%d",sol[i]);
    }
    printf("\n");
}
void back(int pas)
{
    int i;
    for(i=0;i<n*2;i++)
    {
        sol[pas]=v[i];
        if(valid(pas))
        {
            if(pas==n-1 && s(sol,pas)==n)
            {
                afisare(pas);
            }
            else back(pas+1);
        }
    }
}



int main()
{
    int i;
    for(i=0;i<n;i++)
    {
        v[i]=i+1;
    }
    for(i=n;i<2*n;i++)
    {
        v[i]=(i%n+1)*(-1);
    }
    back(0);
    return 0;
}