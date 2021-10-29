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
    int idx_nod_1, idx_nod_2,cost;
} Arc;

typedef struct Graf {
  int nr_noduri;
  Nod Noduri[MAX_NR_NODURI];
  int Arce[MAX_NR_NODURI][MAX_NR_NODURI];//matricea de adiacenta
} Graf;

Graf *graf;

void Initializare(Graf *g)
{
  g->nr_noduri = 0;
}

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





int main()
{
    int i,j,n,m,c;
    Nod nd[20]; Arc a[20];
    scanf("%d",&n);
    scanf("%d",&m);
    graf=(Graf *)malloc(sizeof(struct Graf));
    Initializare(graf);
    for(i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d %d %d",&x,&y,&c);
        a[i].idx_nod_1=x;
        a[i].idx_nod_2=y;
        a[i].cost=c;
        graf->Arce[x][y]=graf->Arce[y][x]=c;


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



}
