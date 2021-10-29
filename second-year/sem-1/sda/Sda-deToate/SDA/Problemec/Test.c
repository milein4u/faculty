#include<stdio.h>
#include<stdlib.h>
#define MAX 40
typedef struct elev
{
    char nume[40];
    int varsta;
}elev;
typedef struct student
{
    char numeStudent[40];
    int varsta;
}student;

typedef struct profesor
{
    char *numeCursanti;
    int *varsta;
}profesor;

  profesor* adaugaElev(char st)
  {
    int contor=0;
    if(contor>MAX)
    {
        return 0;
    }
    profesor numeCursanti=st;
        contor++;
        return numeCursanti;
}    
int main()
{
    return 0;
}