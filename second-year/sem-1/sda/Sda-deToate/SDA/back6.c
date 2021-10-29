#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME "cub.in"
/*Din fisierul cub.in se citesc de pe prima linie 2 numere naturale n si m 
si de pe urmatoarele n linii n perechi l si c unde l este lungimea laturii, 
iar c culoarea pentru n cuburi. l este numar natural, 
iar c este sir de caractere de lungime maxim 20. 
Sa se construiasca toate turnurile formate din cel putin m cuburi 
care se pot forma din cuburile citite din fisier stiind ca 
un cub se poate pune peste un altul doar daca are latura strict 
mai mica si culoarea diferita de a celui peste care vrem sa il punem. 
Sa se afiseze turnurile obtinute si turnul format din cele mai multe cuburi. 
Un turn se afiseaza incepand cu cel mai de sus cub.
Exemplu:
3 2
3 verde
4 rosu
1 rosu
Se obtin turnurile:
1 rosu
3 verde

3 verde
4 rosu
si
1 rosu
3 verde
4 rosu*/
typedef struct {int l; char c[20];} cub;
FILE *f;
cub v[100];
cub sol[100],solmax[100];
int m,n,max=0;

int valid(int pas)
{
        if(pas==0)
            return 1;
        if(sol[pas].l<sol[pas-1].l || strcmp(sol[pas].c,sol[pas-1].c)==0)
            return 0;
        return 1;
}
void afisare(int pas)
{
    int i;
    if(pas>max)
    {
        max=pas;
        for(i=0;i<=max;i++)
        {
            solmax[i]=sol[i];
        }
    }
    for(i=0;i<=pas;i++)
    {
        printf("%d %s\n",sol[i].l,sol[i].c);
    }
    printf("\n");
}
void back(int pas)
{
    int i;
    for(i=0;i<n;i++)
    {
        sol[pas]=v[i];
        if(valid(pas))
        {
            if(pas>=m-1)
            {
                afisare(pas);
            }
            back(pas+1);
        }
    }
}
int main()
{
    int i;
    if(!(f=fopen(FILENAME,"r")))
        {
            printf("Eroare la deschiderea fisierului!\n");
            return 1;
        }
    fscanf(f,"%d %d",&n,&m);
    while(!(feof(f)))
    {
        fscanf(f,"%d %s\n",&v[i].l,v[i].c);
        i++;
    }
    printf("Turnurile de cuburi care se pot creea:\n");
    back(0);
    printf("Tunul cel mai inalt:\n");
    for(int i=0;i<=max;i++)
    {
        printf("%d %s\n",solmax[i].l,solmax[i].c);
    }
    
}