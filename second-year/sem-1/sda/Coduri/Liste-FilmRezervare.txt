#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 40
#define min 20
#define lungime 100
typedef struct rezervare
{
    char numeRezervare[MAX];
    char data[min];
}rezervare;
typedef struct film
{
    int contor;
    char nume[MAX];
    char categorie[min];
    rezervare listaRezervari[lungime];
    struct film *next;
}film;
film* addMovie(film *radacina,char nume[MAX],char categorie[MAX])
{
    film *mov = (film*)malloc(sizeof(film));
    strcpy(mov->nume,nume);
    strcpy(mov->categorie,categorie);
    mov->next=radacina;
    radacina=mov;
    return mov;
}
rezervare* addBooking(char numeRezervare[MAX],char data[min])
{
    rezervare *booking = (rezervare*)malloc(sizeof(rezervare));
    strcpy(booking->numeRezervare,numeRezervare);
    strcpy(booking->data,data);
    return booking;
}
void addBookingForMovie(film *film ,rezervare *booking)
{
    for(film;film!=NULL;film=film->next)
    {
        if(film->contor>lungime)
        {
            printf("Nu se mai pot face rezervari!");
        }
        else
        {
            film->listaRezervari[film->contor]=*booking;
            film->contor++;
        }
    }
}
void bubbleSort(film *film,int n)
{
    char aux[MAX];
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(strcmp(film->listaRezervari[i].numeRezervare,film->listaRezervari[j].numeRezervare)>0)
            {
                strcpy(aux,film->listaRezervari[i].numeRezervare);
                strcpy(film->listaRezervari[i].numeRezervare,film->listaRezervari[j].numeRezervare);
                strcpy(film->listaRezervari[j].numeRezervare,aux);
            }
        }
    }
}
void afisareFilm(film *flm)
{
    film *film=flm;
    int n;
    n=film->contor;
    bubbleSort(film,n);
    for(film;film!=NULL;film=film->next)
    {
        printf("Numele filmului este: %s \n Din categoria : %s\n",film->nume,film->categorie);
        printf("Lista rezervarilor este : \n");
        printf("\n");
        printf("\n");
        for(int i=0;i<film->contor;i++)
        {
            printf(" Numele pe care s-a facut rezervarea: %s\n Data rezervarii: %s",film->listaRezervari[i].numeRezervare,film->listaRezervari[i].data);
            printf("\n");
        }
    }
}

int main()
{
    film *f1 =NULL,*f2=NULL,*f3=NULL;
    rezervare *r1=NULL,*r2=NULL,*r3=NULL,*r4=NULL,*r5=NULL,*r6=NULL,*r7=NULL,*r8=NULL,*r9=NULL;
    f1=addMovie(f1,"Fast and Fourious 9","Actiune");
    f2=addMovie(f2,"American Pie","Comedie");
    f3=addMovie(f3,"dsad","Thriller");
    r1=addBooking("Contra Alex","18.03.2020");
    r2=addBooking("Suciu Denisa","14.04.2020");
    r3=addBooking("Contra Patrik","25.03.2020");
    r4=addBooking("Pop Vasile","08.01.2020");
    r5=addBooking("Popescu Andrei","12.04.2020");
    r6=addBooking("Popovici Maria","13.02.2020");
    r7=addBooking("Avramescu Marian","08.01.2020");
    r8=addBooking("Pop Daniela","12.04.2020");
    r9=addBooking("Ciuta Andrei","13.02.2020");
    addBookingForMovie(f1,r1);
    addBookingForMovie(f1,r2);
    addBookingForMovie(f1,r3);
    addBookingForMovie(f2,r4);
    addBookingForMovie(f2,r5);
    addBookingForMovie(f2,r6);
    addBookingForMovie(f3,r7);
    addBookingForMovie(f3,r8);
    addBookingForMovie(f3,r9);
    afisareFilm(f1);
    afisareFilm(f2);
    afisareFilm(f3);
    return 0;
}
