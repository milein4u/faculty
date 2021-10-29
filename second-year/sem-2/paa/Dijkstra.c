#include<stdio.h>
#include<stdlib.h>
#define MAX_NR_NODURI 5000
#include<stdbool.h>
//#include <limits.h>
int a[MAX_NR_NODURI][MAX_NR_NODURI],n,arc,i,j,c,cont;
int d[MAX_NR_NODURI],s[MAX_NR_NODURI],t[MAX_NR_NODURI],minim,poz,Max=100000;
int main(){
    scanf("%d",&n);
    scanf("%d",&arc);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(i==j)
        a[i][j]=0;
    else
        a[i][j]=Max;


    for(cont=1;cont<=arc;cont++){
        scanf("%d%d%d",&i,&j,&c);
        a[i][j]=c;
    }
    s[1]=1;
    for(i=1;i<=n;i++){
        d[i]=a[1][i];
        if(i!=1)
            if(d[i]<Max)
            t[i]=1;
    }
    for(i=1;i<=n-1;i++){
        minim=Max;
        for(j=1;j<=n;j++)
            if(s[j]==0)
        if(d[j]<minim){
            minim=d[j];
            poz=j;
        }
        s[poz]=1;
        for(j=1;j<=n;j++)
            if(s[j]==0)
        if(d[j]>d[poz]+a[poz][j]){
            d[j]=d[poz]+a[poz][j];
            t[j]=poz;
        }
    }
    for(i=2;i<=n;i++){
        if(d[i]<100000)
        printf("%d ",d[i]);
        else printf("0 ");
    }




return 0;}
