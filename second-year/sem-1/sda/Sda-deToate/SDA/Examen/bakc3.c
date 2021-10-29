#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Se cere sa se permute un cuvant de tip String dintr-o lista de cuvinte de tip String*/
typedef struct cuvinte
{
    char cuv[30];
    struct cuvinte *next;
}cuvant;
cuvant* addCuvant(cuvant *radacina , char cuv[30])
{
    cuvant *c= (cuvant*)malloc(sizeof(cuvant));
    strcpy(c->cuv,cuv);
    c->next=radacina;
    radacina=c;
    return c;
}
void afisareList(cuvant *cuv)
{
    cuvant *nou;
        for(nou=cuv;nou!=NULL;nou=nou->next)
    {
        printf("%s",nou->cuv);
        printf("\n");
    }
}
void swap(cuvant *cuv,char x[20] ,char y[20])
{
    int n=strlen(cuv->cuv);
    for(int i=0;i<n;i++)
    {
        char temp;
        temp=x[i];
        x[i]=y[i];
        y[i]=temp;
    }
}
void backTracking(cuvant *c,char *a,int l,int pos)
{
    int n= strlen(a);
    if(l==pos)
    { 
        printf("%s\n",a);
        /*for(int i=0;i<n;i++)
        {
            printf("%s\n",a);
        }*/
    }
    for(int i=l;i<pos;i++)
    {
        swap(c,(a+1),(a+i));
        backTracking(c,a,l+1,pos);
        swap(c,(a+1),(a+i));
    }
}
int main()
{
    cuvant *c= NULL;
    c=addCuvant(c,"Alex");
    c=addCuvant(c,"Andrei");
    c=addCuvant(c,"Prost");
    int n=strlen(c->cuv);
    backTracking(c,c->cuv,0,n-1);

}