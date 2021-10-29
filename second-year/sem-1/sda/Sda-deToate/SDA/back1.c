#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Se citeste un numar natural n>=4. Sa se afiseze toate 
permutarile multimii {1, 2, ... n} care au proprietatea ca 
diferenta absoluta a oricaror 2 
elemente alaturate este cel putin egala cu 2.
Ex: Pentru n=4 se obtin permutarile 2 4 1 3 si 3 1 4 2.*/
int n=4;
int sol[50];
int valid(int pas)
{
    int i;
    for(i=0;i<pas;i++)
    {
        if(sol[i]==sol[pas])
            return 0;
    }
    if(pas==0)
        return 1;
    if(abs(sol[pas]-sol[pas-1])<2)
        return 0;
    return 1;

}
void afisare()
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",sol[i]);
    }
    printf("\n");
}
void back(int pas)
{
    int i;
    for(i=1;i<=n;i++)
    {
        sol[pas]=i;
        if(valid(pas))
        {
            if(pas==n-1)
            {
                afisare();
            }
            else back(pas+1);
        }
    }
}
int main()
{
    back(0);
}