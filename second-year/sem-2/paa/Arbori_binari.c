#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

struct Nod {

    int cheie;
    struct Nod *stang, *drept;
};

struct Nod *rad;

Nod *creaza(int cheie)
{
    Nod *p= new Nod;
    p->cheie=cheie;
    p->stang=NULL;
    p->drept=NULL;
    return p;
}

void adauga(int cheie)
{
    if(rad==NULL)
    {
        rad=creaza(cheie);
        return rad;
    }

    queue<Nod*> q;
    q.push(rad);

    while(!q.empty())
    {
        Nod *schimb=q.front();
        q.pop();

        if(schimb->stang!=NULL)
                q.push(schimb->stang);
            else
            {
                schimb->stang=creaza(cheie);
                return rad;
            }


        if(schimb->drept!=NULL)
                q.push(schimb->drept);
            else
            {
                schimb->drept=creaza(cheie);
                return rad;
            }
    }

}

int inaltime()
{
    int h=1;
    if(rad==NULL) return 1;

    queue<Nod*> q;
    q.push(rad);

    while(1)
    {
        int nr_nod_nivel=q.size();
        if(nr_nod_nivel==0)
            return h;
        h++;

        while(nr_nod_nivel>0)
        {
            Nod *p=q.front();
            q.pop();

            if (Nod->stang!=NULL)
                q.push(nod->stang);
            if (Nod->drept!=NULL)
                q.push(Nod->drept);

            nr_nod_nivel--;

        }
    }
}
void preordine()
{

    if(rad != NULL)
    {
        return rad;
        preordine(rad->stang);
        preordine(rad->drept);
    }

}
