#include <stdio.h>
#include <stdlib.h>
/*Sa se scrie un program care genereaza si scrie intr-un 
fisier toate cuvintele formate din n vocale mici (n numar 
natural citit de la tastatura, n<10), ordonate alfabetic. 
De exemplu, pentru n=3 se vor scrie in fisier:*/
int n=3;
char sol[50];
char vocale[]={'a','e','i','o','u'};

void afisare()
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%c ",sol[i]);
    }
    printf("\n");
}
void back(int pas)
{
    int i;
    for(i=0;i<5;i++)
    {
        sol[pas]=vocale[i];
            if(pas==n-1)
            {
                afisare();
            }
            else back(pas+1);
    }
}
int main()
{
    back(0);
}