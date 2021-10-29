#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Magazin
{
    long int codBare;
    char numeProdus[30];
    struct Magazin *next;
}Magazin;
Magazin *head=NULL;
Magazin *curent=NULL; 
void addLista(char numeProdus[30],long int codBare)
{
    Magazin *link=(Magazin*)malloc(sizeof(Magazin));
    strcpy(link->numeProdus,numeProdus);
    link->codBare=codBare;
    link->next=head;
    head=link;
}
void afisareLista()
{
    Magazin *nod=head;
    while(nod!=NULL)
    {
        printf("Nume Produs: %s \nCod bare: %ld",nod->numeProdus,nod->codBare);
        printf("\n");
        nod=nod->next;
    }
}
Magazin* gasesteDupaCod(long int Codbare)
{
    curent=head;
    int contor=0;
    if(head==NULL)
    {
        printf("Lista de produse goala");
    }
    while(curent->codBare!=Codbare)
    {
        if(curent->next==NULL)
        {
                printf("Produsul nu exista in lista magazinului!");
                break;
        }
            else
            {
                curent=curent->next;
                if(curent->codBare==Codbare)
                {
                    printf("\nProdusul cautat de dumneavoastra este: \n");
                    printf("Nume produs: %s \nCod Bare %ld",curent->numeProdus,curent->codBare);   
                    contor++;
                }
            }
    }
        printf("\nNumarul de produse cu codul de bare aferent cautarii este: %d\n",contor);
    return curent;
}
Magazin* stergereLista(long int cod)
{
    curent=head;
    int contor=0;
    if(head==NULL)
    {
        printf("\nLista de produse goala\n");
    }

        while(curent->codBare!=cod)
        {
               curent=curent->next;
               if(curent->codBare==cod)
               {
                head=head->next;
                free(curent);
                contor++;
               }
        }
        printf("\nElementul sters este :%s %ld\n",curent->numeProdus,curent->codBare);
        printf("numarul elementelor sterse este : %d\n",contor);
    return head;
}
int main()
{
    addLista("Pufuleti",199921L);
    addLista("Banane",3213190L);
    addLista("Iaurt",88823567L);
    addLista("Lapte",88012214L);
    afisareLista();
    gasesteDupaCod(3213190L);
    stergereLista(199921L);
    return 0;
}
