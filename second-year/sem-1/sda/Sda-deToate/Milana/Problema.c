#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxCap 15
#define maxStudenti 10

typedef struct {
    char nume[maxCap];
    char prenume[maxCap];
    char gen;
    int medieAnuala;
} student;


void bubbleSort(student *studenti, int n)
{
    int i, j;

    for ( i = n - 2; i >= 0; i--)
    {
        studenti[n] = studenti[i];

        j = i + 1;

        while (studenti[j].medieAnuala > studenti[n].medieAnuala)
        {
            studenti[j - 1] = studenti[j];
            j++;
        }
        studenti[j - 1] = studenti[n];
    }
}

int genComparare(student st1 , student st2) {
    return strcmp( &st1.gen, &st2.gen);
}

int medieComparare(student st1, student st2) {
    return st1.medieAnuala - st2.medieAnuala;
}

void qsortnerec(student *studenti, int n)
{
    int i, j, s, d;
    student x ;
    student temp;
    unsigned char is;
    
    struct {
        int s, d;
    }
    
    stiva[n];
    is = 1;
    stiva[0].s = 0;
    stiva[0].d = n - 1;

    do {
        s = stiva[is - (1)].s;
        d = stiva[is - (1)].d;
        is = is - 1;

        do {
            i = s; 
            j = d; 
            x = studenti[(s + d) / 2];
            do {
                while (studenti[i].gen < x.gen || studenti[i].medieAnuala < x.medieAnuala  || strcmp(studenti[i].nume,x.nume)>0 || strcmp(studenti[i].prenume,x.prenume)>0) 
                    i = i + 1;
                while (x.gen < studenti[j].gen ||  x.medieAnuala < studenti[j].medieAnuala || strcmp(x.nume,studenti[j].nume)<0 || strcmp(x.prenume,studenti[j].prenume)<0) 
                    j = j - 1;

                if (i <= j)
                {
                    temp = studenti[i];
                    studenti[i] = studenti[j];
                    studenti[j] = temp;
                    i = i + 1;
                    j = j - 1;
                }
            } while (!(i > j));
            if (i < d)
            {

                is = is + 1;
                stiva[is - 1].s = i;
                stiva[is - 1].d = d;
            }
            d = j;
        } while (!(s >= d));
    } while (!(is == 0));
}

void printStudenti(student *studenti, int n)
{
    int i = 0;
    for (i = 0 ; i < n; i++)
        printf("%d %c %s %s\n", studenti[i].medieAnuala, studenti[i].gen, studenti[i].nume, studenti[i].prenume);
}

int main()
{
    int i, n;

    char c1_nume[maxCap];
    char c1_prenume[maxCap];
    char c2_nume[maxCap];
    char c2_prenume[maxCap];

    student studenti[maxStudenti];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%i %c %s %s", &studenti[i].medieAnuala, &studenti[i].gen, studenti[i].nume, studenti[i].prenume);

    scanf("%s %s", c1_nume, c1_prenume);
    scanf("%s %s", c2_nume, c2_prenume);

    bubbleSort(studenti, n);
    printStudenti(studenti, n);

    for (i = 0; i < n; i++)
    {
        if (strcmp(studenti[i].nume,c1_nume)==0 && strcmp(studenti[i].prenume,c1_prenume)==0)
            printf("Indexul primului element citit este %i\n", i);
    }

    qsortnerec(studenti,n);
    printStudenti(studenti, n);

    for (i = 0; i < n; i++)
    {
        if (strcmp(studenti[i].nume,c2_nume)==0 && strcmp(studenti[i].prenume,c2_prenume)==0)
            printf("Indexul celui de al doilea element citit este %i\n", i);
    }


}
