#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Se citeste un numar natural n.
Sa se afiseze toate modalitatile de a-l descompune ca
suma de numere naturale consecutive.
Daca acest lucru nu este posibil, se va afisa mesajul "Imposibil".
Exemplu:
Numarul 15 se poate scrie ca urmatoarele sume:
1+2+3+4+5 , 4+5+6 sau 7+8.
Numarul 8 nu poate fi scris ca suma de numere consecutive.
*/
int n=1024;
int sol[50];

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
    if(sol[pas]-sol[pas-1]==1 && s(sol,pas)<=n)
        return 1;
    return 0;
}
void afisare(int pas)
{
    int i;
    for(i=0;i<=pas;i++)
    {
        if(i==0)
            printf("%d",sol[i]);
        else printf("+%d",sol[i]);
    }
    printf("\n");
}
void back(int pas)
{
    int i;
    for(i=1;i<n;i++)
    {
        sol[pas]=i;
        if(valid(pas))
        {
            if(s(sol,pas)==n)
            {
                afisare(pas);
            }
            else back(pas+1);
        }
    }
}

int sb(int a)
{
    int i;
    for(i=a&1;a>0;i+=(a>>=1)&1);
    printf("%d\n",i);
    return i;
}


int main()
{
    if(sb(n)==1)
    {
        printf("Imposibil!");
        return 1;
    }
    back(0);
    return 0;
}

