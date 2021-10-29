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

void Initializare(Graf *g)
{
  g->nr_noduri = 0;
}

void Initializare_marc(int *x,int n) //functie pt initializare vectorilor care marcheaza vizita nodurilor in parcurgeri si le retine dupa
{
    int j;
    for(j=1;j<=n;j++)
        x[j]=0;

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


void Adancime(Graf *g,int n,int *marc)                                // functia de parcurgere in adancime
{
    int i,ok,contor_aux=0,contor_marc=1,aux[g->nr_noduri];          // declar un vector marc in care voi pune nodurile parcurse si unul aux cu care parcurg
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
         if(marc[i]==0&&graf->Arce[i][n]==1)            // daca am un nod nevizitat ,il aleg ca nod de pornire si se continua parcurgerea
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

void Cuprindere(Graf *g,int n,int *marc)                    //functia de parcurgere prin cuprindere
{
   int i,contor_aux=0,contor_marc=1,aux[g->nr_noduri];       // declar un vector marc in care voi pune nodurile parcurse si unul aux cu care parcurg
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
}

int verificare(int *x,int *y,int n)
{                                                           //functia de verificare intre cei 2 vectori marc cu care vizitam nodurile in parcurgere
    int i;                                                  // o vom folosi in functia propriu zisa rezolvarii problemei pentru a verifica ,pe rand
    for(i=1;i<=n;i++)                                          // daca pornind de la un nod parcurgerile se fac in aceeasi ordine
        if(x[i]!=y[i])
        return 0;
    return 1;
}

void Functie_Comparare(Graf *g)
{
    int i;
    int m1[g->nr_noduri+1],m2[g->nr_noduri+1];              // functia propriu-zisa rezolvarii problemei in care declar 2 vectori cu care vizitez nodurile
    for(i=1;i<=g->nr_noduri;i++)                                // dupa care pe rand,luam fiecare nod din graf ,ii initializam vectorii marc de vizita
    {
        Initializare_marc(m1,g->nr_noduri);                     // apelam functiile de parcurgere pentru a construii cei2 vectori
        Initializare_marc(m2,g->nr_noduri);
        Adancime(g,i,m1);
        Cuprindere(g,i,m2);
        if(verificare(m1,m2,g->nr_noduri))                      // in final folosim functia de verificare si apoi reluam pana verificam toate nodurile
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

