#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nod {

    int cheie;
    struct Nod *stang, *drept;
};

typedef struct Nod nod;

void adauga(nod *r,int cheie)
{
    nod *temp=NULL;
    if(r==NULL)
    {
        temp = (nod *)malloc(sizeof(nod));
        temp->stang=temp->drept= NULL;
        temp->cheie=cheie;
        r=temp;

    } else{

        if(cheie<r->cheie)
        {
            adauga(r->stang,cheie);
        }
        else if(cheie>r->cheie)
        {
            adauga(r->drept,cheie);
        }

    }


}

int inaltime(nod *r)
{
    int st,dr;
    if(r==NULL)
        return 0;
    else{

        st=inaltime(r->stang);
        dr=inaltime(r->drept);

        if(st>dr)
        {
            return (st+1);
        }
        else
        {
            return (dr+1);
        }

    }

}

void preordine(nod *r)
{
    if(r)
    {
        printf("%d ",r->cheie);
        preordine(r->stang);
        preordine(r->drept);
    }

}
int main()
{
    int i,n,cheie;
    nod *rad;
    rad=NULL;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d/n",&cheie);
        adauga(rad,cheie);
    }

    printf("%d",inaltime(rad));
    preordine(rad);
}
