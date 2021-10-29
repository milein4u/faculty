#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int cod;
    char ocupatie[351];
}Ocupatie;

Ocupatie o[4248];
FILE *f;

void citire() {

    int k= 0;
    char l[351];
    if((f = fopen("COR_Descrescator.txt", "r"))==NULL) {
        printf("Error!");
        exit(EXIT_FAILURE);
    }
    fgets(l,351,f);
    while(!feof(f)) {
        k++;
    }
    fclose(f);
}

void cautaCod(Ocupatie o[],int cod) {
      int s=0,d=4247,m;
      while(s<=d){
        m=(s+d)/2;
        if(o[m].cod == cod)
            printf("%s\n",o[m].ocupatie);
            else{
            if(o[m].cod > cod)
                s=m+1;
            else
                d=m-1;
        }
      }
      printf("COD INEXISTENT");
}
void cautaCuvant(Ocupatie o[],const char* cuvant) {
    for(int i = 0; i < 4247; i++) {
        int k = 0;
        for(int j=0;j<strlen(cuvant);j++) {
            if(o[i].ocupatie[j]==cuvant[j])
                k++;
        }
        if(k==strlen(cuvant)) {
            printf("%s\n", o[i].ocupatie);
        }
    }
}
int main() {

    int c;
    char cuv[100];
    citire();
    scanf("%d",&c);
    cautaCod(o,c);
    scanf("%s",&cuv);
    cautaCuvant(o,cuv);

}
