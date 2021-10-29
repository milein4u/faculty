#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_n 15
typedef int Cursor;

typedef struct Zona {

    int cheie;                  //cheia nodului curent

    Cursor primul_fiu, frate_drept, tata;

}Zona;

typedef struct Arbore {

    struct Zona noduri[max_n + 1];

}Arbore;

struct Arbore A;   //declar structura pentru arbore

int cheie[max_n];       //declar vectori pentru fiecare camp din structuri ca sa lucrez mai usor
int primul_fiu[max_n];
int frate_drept[max_n];
int tata[max_n];
int n;

void adauga(int ch,int p)
{
    int i;
    for(i=1;i<max_n;i++)
    {
        if(cheie[i]==p)
            tata[n]=i;  //adaug valoarea in vectorul de tati
            cheie[n]=ch;    //adaug valoarea in vectorul de chei
            if(primul_fiu[i]==0) // daca nu am nimic in vectorul de primul_fiu la pozitia i,adaug noul nod
                                    //iar daca am deja atunci voi completa in vectorul de frate_drept cheia nodului adaugat
                primul_fiu[i]=ch;
            else
                frate_drept[n-1]=ch;
            primul_fiu[n]=0; //pun valoarea 0 in vector pentru ca noul nod nu este tata
            frate_drept[n]=0;//pun valoarea 0 pentru ca nu poate exista un frate in partea dreapta
    }
}
int inaltime()
{
    int i,contor;
    for(i=1;i<=n;i++)       //parcurg vectorul de primul_fiu
    {
        contor=0;
        if(primul_fiu[i]!=0) // daca am un element nenul il iau in considerare pentru a calcula inaltimea
            contor++;
    }

    return contor+1; // adaug si radacina,nivelul incepand de la 1 ,nu de la 0



}

void grad(int n)
{
    int i,j,k,max=-1;
    for(i=1;i<=n;i++) //cu un for parcurg pe rand vectorul primul_fiu
    {
        k=0;
        if(primul_fiu[i]!=0) //daca am o valoare,atunci nu e frunza si pot incepe sa calculez gradul
        {
            k++;
            for(j=cheie[primul_fiu[i]];j<=n;j++) //cu un for de la valoarea din vectorul de chei parcurg vectorul frate_drept si cresc k pana ajung la valoarea 0
            {

                if(frate_drept[j]!=0)
                    k++;
            }

            if(k>max) max=k;
        }
    }
     printf("%d",max);

}
int main() // nu am reusit in main sa citesc cu metoda primul fiu si frate drept
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&A.noduri[i].cheie);//citesc cheia nodului
        scanf("%d",&A.noduri[i].tata);//citesc cheia parintelui
    }

    printf("%d",inaltime()); // afisez inaltimea
    grad(n);//apelez functia grad
}
