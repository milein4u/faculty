#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cod;
    char ocupatie[351];
}Ocupatii;
Ocupatii o[4247];
void citire() {
    FILE* f = fopen("COR_Descrescator.txt", "r");
    if(!f) {
        printf("Error!");
        exit(EXIT_FAILURE);
    }
    int counter = 0;
    char aux1[10];
    char aux2[10];
    fscanf(f, "%s %[^\n]s\n", aux1, aux2);
    while(fscanf(f, "%d %[^\n]s\n", &o[counter].cod, &o[counter].ocupatie) != EOF) {
        counter++;
    }
    fclose(f);
}
void cautareOcupatie_cod(int cod) {
      int m, s=0, d=4246;
      while(s <= d) {
        m = (s+d) / 2;
        if(o[m].cod == cod) {
            printf("%d\t%s\n", o[m].cod, o[m].ocupatie);
            return;
        } else {
            if(o[m].cod > cod)
                s = m+1;
            else
                d = m-1;
        }
      }
      printf("COD INEXISTENT!");
}
void cautareOcupatie_cuvant(const char* cuvant) {
    for(int i = 0; i < 4247; i++) {
        int counter = 0;
        for(int j = 0; j < strlen(cuvant); j++) {
            if(o[i].ocupatie[j] == cuvant[j])
                counter++;
        }
        if(counter == strlen(cuvant)) {
            printf("%s\n", o[i].ocupatie);
        }
    }
}
int main() {
    citire();
    cautareOcupatie_cod(265438);
    cautareOcupatie_cuvant("miner");
    return 0;
}

