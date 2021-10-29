#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Muchie {
    int src, dest, cost;
};

struct Graf {
    int n, m;
    struct Muchie* muchie;
};
struct Graf *graf;

struct Graf* initializare(int n, int m)
{
    struct Graf* graf= (struct Graf*)(malloc(sizeof(struct Graf)));
    graf->n= n;
    graf->m= m;

    graf->muchie= (struct Muchie*)malloc(sizeof( struct Muchie));

    return graf;
}

struct subset {
    int parent;
    int rank;
};

int gasit(struct subset s[], int i)
{

    if (s[i].parent!=i)
        s[i].parent=gasit(s,s[i].parent);

    return s[i].parent;
}

void Union(struct subset s[], int x, int y)
{
    int xrad=gasit(s, x);
    int yrad=gasit(s, y);

    if (s[xrad].rank < s[yrad].rank)
        s[xrad].parent = yrad;
        else if(s[xrad].rank > s[yrad].rank)
                s[yrad].parent = xrad;
            else
                {
                    s[yrad].parent = xrad;
                    s[xrad].rank++;
                }
}

int compara(const void* a, const void* b)
{
    struct Muchie* a1 = (struct Muchie*)a;
    struct Muchie* b1 = (struct Muchie*)b;
    return a1->cost > b1->cost;
}


void Kruskal(struct Graf* graf)
{
    int n= graf->n;
    int i=0,e=0;
    struct Muchie rez[n];

    qsort(graf->muchie, graf->m, sizeof(graf->muchie[0]),compara);

    // Allocate memory for creating V ssubsets
    struct subset* s=(struct subset*)malloc(n * sizeof(struct subset));


    for (int j=0;j<n;j++)
    {
        s[j].parent=n;
        s[j].rank=0;
    }

    while (e < n- 1 && i < graf->m)
    {
        struct Muchie urm = graf->muchie[i++];

        int x = gasit(s, urm.src);
        int y = gasit(s, urm.dest);

        if (x != y)
        {
            rez[e++] = urm;
            Union(s, x, y);
        }

    }

    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        minimumCost += rez[i].cost;
    }

    printf("%d",minimumCost);

    return;
}
 int main()
 {
    int i,j,n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    struct Graf* graf = initializare(n,m);
    for(i=1;i<=n;i++)
    {
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        graf->muchie[i].src = x;
        graf->muchie[i].dest = y;
        graf->muchie[i].cost = c;

    }


    Kruskal(graf);

 }
