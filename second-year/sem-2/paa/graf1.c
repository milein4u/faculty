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

/*typedef struct Coada{
    int c[MAX_NR_NODURI];
    int primul,ultimul;
} Coada;*/

void Initializare(Graf *g){
  g->nr_noduri = 0;
}

void Initializare_marc(int *x,int n)
{
    int j;
    for(j=1;j<=n;j++)
        x[j]=0;

}
void InsertNod(Graf *g, Nod n){
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

void InsertArc(Graf *g, Arc a){
  g->Arce[a.idx_nod_1][a.idx_nod_2] = g->Arce[a.idx_nod_2][a.idx_nod_1] = 1;
}


/*void Afiseaza_Arce(Graf *g){
  int i,j;
  for(i = 0; i < g->nr_noduri; i++){
    for(j = 0; j < g->nr_noduri; j++)
      printf("%d ", g->Arce[i][j]);
    printf("\n");
  }
}*/
//int marc[MAX_NR_NODURI];

void Adancime(Graf *g,int n,int *marc)
{
    int i,ok,contor_marc=1,contor_aux=0,aux[g->nr_noduri];
    aux[contor_aux++]=n;
    while(contor_aux)
    {
        n=aux[contor_aux-1];
        ok=0;

        if(marc[n]==0)
        {
            marc[n]=contor_marc;
            contor_marc++;
        }

        for(i=1;i<=g->nr_noduri&&ok==0;i++)
            if(marc[i]==0&&g->Arce[i][n]==1)
            {
                marc[i]=contor_marc;
                contor_marc++;
                aux[contor_aux++]=i;
                ok=1;
            }

        if(ok==0)
            contor_aux--;
    }
}

void Cuprindere(Graf *g,int n,int *marc)
{
    int i,contor_marc=1,contor_aux=0,aux[g->nr_noduri];
    aux[contor_aux++]=n;
    while(contor_aux)
    {
        n=aux[0];

        for(i=1;i<=contor_aux;i++);
            aux[i]=aux[i+1];

        contor_aux--;

        if(marc[n]==0)
        {
            marc[n]=contor_marc;
            contor_marc++;
        }

        for(i=1;i<=g->nr_noduri;i++)
            if(marc[i]==0&&g->Arce[i][n]==1)
            {
                marc[i]=contor_marc;
                contor_marc++;
                aux[contor_aux++]=i;
            }
    }
}

int verificare(int *x,int *y,int n)
{
    int i;
    for(i=1;i<=n;i++)
        if(x[i]!=y[i])
            return 0;
    return 1;

}

void Functie_Comparare(Graf *g)
{
    int i;
    int m1[g->nr_noduri],m2[g->nr_noduri];


    for(i=1;i<=g->nr_noduri;i++)
    {
        Initializare_marc(m1,g->nr_noduri);
        Initializare_marc(m2,g->nr_noduri);
        Adancime(g,i,m1);
        Cuprindere(g,i,m2);

        if(verificare(m1,m2,g->nr_noduri))
            printf("%d ",i);
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

    Functie_Comparare(graf);

}
