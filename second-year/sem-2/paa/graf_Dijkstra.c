#include<conio.h>
#define MAX 1000

void main()
{
	int G[MAX][MAX], i, j, n, m, k, c;

	scanf("%d", &n);
	scanf("%d", &m);

	for(i=1;i<=n;i++)                    // initializam matricea cu costuri
        for(j=1;j<=n;j++)
            if(i==j)
                G[i][j]=0;
            else
                G[i][j]=MAX;


    for(k=1;k<=m;k++)                      // citim datele si le punem in matrice
    {
        scanf("%d %d %d",&i,&j,&c);
        G[i][j]=c;
    }


	dijikstra(G,n);                     //apelam functia pt a calcula cea mai scurta cale

}

int s[MAX],d[MAX],p[MAX],min,viz,max=5000;           // initializez var globale pt functia Dijikstra

void dijikstra(int G[MAX][MAX], int n)
{
	s[1]=1;                                 // punem nodul de inceput ca fiind 1

    for(int i=1; i<=n; i++)
    {
        d[i]=G[1][i];
        if(i!=1)
            if(d[i]<max)
                p[i]=1;
    }

    for(int i=1; i<=n-1; i++)                       // calc dist caii prin toate nodurile
    {
        min=max;

        for(int j=1; j<=n; j++)
            if(s[j]==0)
                if(d[j]<min)
                {
                    min=d[j];
                    viz=j;
                }
        s[viz]=1;

        for(int j=1; j<=n; j++)
            if(s[j]==0)
                if(d[j]>d[viz]+G[viz][j])
                {
                    d[j]=d[viz]+G[viz][j];
                    p[j]=viz;
                }
    }

    for(int i=2; i<=n; i++)                 // afisez calea min pt fiecare
    {
        if(d[i]<max)
            printf("%d ",d[i]);
        else
            printf("0 ");
    }

}
