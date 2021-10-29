#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cod;
    char ocupatie[351];
}Ocupatii;

Ocupatii o[4248];

void citire() {
    FILE* f ;
    f= fopen("COR_Descrescator.txt", "r");
    if(f==NULL) {
        printf("Error!");
        exit(1);
    }


    char *data[4248];
    int i, n;

    for ( i = 0; i < 4248; i++)
    {
      data[i] = NULL;
      size_t n = 0;

      getline(&data[i], &n, f);

      /*if ( ferror( f ) )
        goto error_read_file;*/

    }

    for (size_t i = 0; i < 4248; i++)
    {
      printf("%s", data[i]);
      free(data[i]);
    }

  fclose(f);

}

int cautareOcupatie_cod(Ocupatii o[4248],int cod)
{
    int m, s=0, d=4246;
      while(s <= d) {
        m = (s+d) / 2;
        if(o[m].cod == cod) {
            printf("%s\n", o[m].ocupatie);
        } else {
            if(o[m].cod > cod)
                s = m+1;
            else
                d = m-1;
        }
      }
      printf("COD INEXISTENT!");



}

void cautareOcupatie_cuvant(Ocupatii o[4248], char cuvantDat[], int x)
{
    int i;
    char copie[351];
    for ( i = 0; i < 4248; i++)
    {
        strcpy(copie,o[i].ocupatie);
        if(!strcmp(strtok(copie, " "),cuvantDat))
            printf("%s\n", o[i].ocupatie);
    }


}

int main()
{
    int n,cod;
    char cuvant[100];
    citire();
    scanf("%d", &cod);
    cautareOcupatie_cod(o,cod);
    scanf("%c",cuvant);
    cautareOcupatie_cuvant(o,cuvant,n);

}

