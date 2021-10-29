/*/*Se citeste un numar natural n. 
Sa se afiseze toate modalitatile de a-l descompune ca 
suma de numere naturale consecutive. 
Daca acest lucru nu este posibil, se va afisa mesajul "Imposibil".
Exemplu: 
Numarul 15 se poate scrie ca urmatoarele sume: 
1+2+3+4+5 , 4+5+6 sau 7+8. 
Numarul 8 nu poate fi scris ca suma de numere consecutive.
*/
#include<stdlib.h>
#include<stdio.h>
int sol[50];
int n=4;
int valid(int pos)
{
    for(int i=0;i<pos;i++)
    {
        if(sol[i]==sol[pos])
        {
            return 0;
        }
    }
    if(pos==0)
    {
        return 0;
    }
    return 1;
}
void afisare()
{
    for(int i=0;i<n;i++)
    {
        printf("%d",sol[i]);
    }
    printf("\n");
}
void backTracking(int pos)
{
   
    for(int i=0;i<n;i++)
    {
        sol[pos]=i;
        if(valid(pos))
        {
            afisare();
        }
        if(pos==n)
        {
            afisare();
        }
        else
        {
            backTracking(pos+1);
        }
    }
}
int main()
{
    backTracking(1);
}