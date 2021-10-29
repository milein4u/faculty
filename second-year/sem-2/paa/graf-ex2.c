#include<stdio.h>
#include<stdlib.h>
#define _GRAF_

#define MAX_NR_NODURI 100


typedef struct TipNod {
  //Ambele sunt doar niste atribute ale nodului
  //Nu influenteaza implementarea functiilor
  int cheie;
  int info;
} Nod;

typedef struct TipArc {
    int idx_nod_1, idx_nod_2;
} Arc;

typedef struct Graf {
  int nr_noduri;
  Nod Noduri[MAX_NR_NODURI];
  int Arce[MAX_NR_NODURI][MAX_NR_NODURI];//matricea de adiacenta
} Graf;

Graf *graf;

/*typedef struct Coada {

    int prim, ultim,c[50];
} Coada;

Coada *coada;*/

void Initializare(Graf *g)
{
  g->nr_noduri = 0;
}

/*void Initializare_marc(int *x,int n) //functie pt initializare vectorilor care marcheaza vizita nodurilor in parcurgeri si le retine dupa
{
    int j;
    for(j=1;j<=n;j++)
        x[j]=0;

}*/

void InsertNod(Graf *g, Nod n)
{
  //se adauga nodul n in graf(primul nod e pe pozitia 0)
  int index_nod = g->nr_noduri;
  g->Noduri[index_nod] = n;
  g->nr_noduri++;
  //se initializeaza matricea de adiacenta pentru noul nod
  int i;
  for(i = 0; i < g->nr_noduri; i++){
    g->Arce[index_nod][i] = g->Arce[i][index_nod] = 0;
  }
}

void InsertArc(Graf *g, Arc a)
{
  g->Arce[a.idx_nod_1][a.idx_nod_2] = g->Arce[a.idx_nod_2][a.idx_nod_1] = 1;
}


/*void Cuprindere(Graf *g,int n,int *marc)                    //functia de parcurgere prin cuprindere
{
   int i,contor_aux=0,contor_marc=1,aux[g->nr_noduri];
   nrc++ ;                                                     // declar un vector marc in care voi pune nodurile parcurse si unul aux cu care parcurg
   aux[contor_aux++]=n;

   while(contor_aux)
   {
       n=aux[0];

       for(i=0;i<contor_aux;i++)
            aux[i]=aux[i+1];

       contor_aux--;

       if(marc[n]==0)
       {
           marc[n]=contor_marc;
           contor_marc++;
       }

       for(i=1;i<=g->nr_noduri;i++)
         if(marc[i]==0&&g->Arce[i][n]==1)       // daca am un nod nevizitat ,il aleg ca nod de pornire si se continua parcurgerea
            {

                marc[i]=contor_marc;
                contor_marc++;
                aux[contor_aux++]=i;
            }
    }
}*/

int viz[50];

int verificare(int viz[],int n)
{
    int i;
    for(i=1;i<=n;i++)
        if(viz[i]==0)
            return i;
    return 0;
}

int prim, ultim;
int c[50];
int nrc;

void cuprindere(Graf *g,int n,int nod)
{
    int i;
    nrc++;
    viz[nod]=1;
    prim=ultim=1;
    c[ultim]=nod;

    while(prim<=ultim)
    {
        for(i=1;i<=n;i++)
            if(g->Arce[c[prim]][i]==1&&viz[i]==0)
            {
                ultim++;
                c[ultim]=i;
                viz[i]=1;
            }

        prim++;
    }
}


void Nr_comp_conexe(Graf *g)
{
    int i;
    while(verificare(viz,g->nr_noduri)!=0)
    {
        i=verificare(viz,g->nr_noduri);
        cuprindere(g,g->nr_noduri,i);
        ciclic(i,g);
    }
}

int viz_prim;
int ok;

void ciclic(int nod,Graf *g)
{

    /*for(i=1;i<=n;i++)
        viz[i]=0;*/
    int i;
    ok=0;


    for(i=1;i<=g->nr_noduri;i++)
        if(i!=viz_prim&&g->Arce[nod][i]==1)
                {
                    viz_prim=nod;
                    ok=1;
                    ciclic(i,g);

                }
}



int main()
{
    int i,j,n,m;
    Nod nd[20]; Arc a[20];
    scanf("%d",&n);
    scanf("%d",&m);
    graf=(Graf *)malloc(sizeof(struct Graf));
    Initializare(graf);
    for(i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        a[i].idx_nod_1=x; a[i].idx_nod_2=y;

    }
    for(j=1;j<=n;j++)
    {
        nd[j].cheie=j;
        InsertNod(graf,nd[j]);
    }
    for(i=1;i<=m;i++)
    {
        InsertArc(graf,a[i]);
    }

     Nr_comp_conexe(graf);
     printf("%d",nrc);
    printf(" %d",ok);


}
