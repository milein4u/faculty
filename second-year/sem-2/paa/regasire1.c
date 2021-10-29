#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*int niv=0;                  // declar variabila globala niv si compar pt a afla inaltimea
int compar=0;
*/

typedef struct Nod{
	struct Nod *alfabet[27];
}Nod;

Nod *radacina;

void Initializare(Nod *n)
{
	char c;
	for (c = 'a'; c <= '{'; c++)
		n->alfabet[c - 'a'] = NULL;
}

void Atribuie(Nod *n, char c, Nod *p)
{
	n->alfabet[c - 'a'] = p;
}

Nod *Valoare(Nod *n, char c)
{
	return n->alfabet[c - 'a'];
}

void NodNou(Nod *n, char c)
{
	n->alfabet[c - 'a'] = (Nod *)malloc(sizeof(struct Nod));
	Initializare(n->alfabet[c - 'a']);
}

void Adauga(char *x, Nod *rad)  //x=cuvantul,
                                //rad=radacina arborelui de regasire

{

	unsigned i;
	Nod *nou;
	nou=rad;

	for (i = 0; i < strlen(x);i++)
	{

		if (Valoare(nou, x[i]) == NULL) //nodul curent nu are fiu pentru caracterul x[i], deci se creaza unul nou
            NodNou(nou, x[i]);
            nou=Valoare(nou, x[i]); //trec mai departe in arborele de regasire

	}

	Atribuie(nou, '{', nou); //se face o bucla pentru '{', pentru a marca un nod terminal

}


/*void Inaltime(Nod *n, char cuv[])
{
	char c;
	int niv=0;
	for (c = 'A'; c <= 'Z'; c++)		//pentru toate literele considerate
	{
		if (Valoare(n, c))			//daca am legatura in dictionar
		{
			cuv[niv] = c;
			niv=niv+1;				      //cresc nivelul
			Parcurge(Valoare(n, c),cuv); //avansez
		}
	}


}*/

/*int p=0;                                            //declar o variabila globala p ,pentru a numara nr de pagini
void numar_pagini(struct Nod *n)
{

    char c;
    p++;
    for (c = 'a'; c <= 'z'; c++)                        //parcurg toate literele din vectorul considerat - alfabet
       {
            if(Valoare(n, c))                               //din nou,la fel ca la functia de inaltime,daca am legatura ,
                                                        //trec mai departe si maresc contorul pt numarul de pagini
                numar_pagini(Valoare(n, c));

        }



}

void inaltime(int niv,struct Nod *n)
{
    char c;
    for (c = 'a'; c <= 'z'; c++)               //parcurg toate literele din vectorul considerat - alfabet
        {
            if(Valoare(n, c))
                inaltime(niv+1,Valoare(n, c));
        }
                                            //daca am legatura ,trec mai departe si cresc nivelul
        if(Valoare(n,'{'))
           {
               niv++;
               if(compar<niv)               //compar cu maximul de la alte cuvinte
                    compar=niv;

           }


}
*/
int niv=0;
char compara[30];

void ordine_lexicografica(char cuv[],int niv,Nod *n)
{
    char c;
    for (c = 'z'; c >= 'a'; c--)     // parcurg toate literele din vectorul considerat - alfabet
    {
        if(Valoare(n, c))       // verific daca am legatura in dictionar
           {
                cuv[niv]=c;         //retin litera cea mai mare
                ordine_lexicografica(cuv,niv+1,Valoare(n,c));   //trec mai departe
           }
    }
        if(Valoare(n,'{'))              // daca e pag terminala
                {
                    cuv[niv]='\0';
                    if(strcmp(cuv,compara)>0)           //compar cu cuvintele de dinainte si retin cea mai mare
                    strcpy(compara,cuv);

                }


}
int main()
{
	int i, n;
	char v[30];
	char cuv[30];
    scanf("%d",&n);
	radacina = (Nod *)malloc(sizeof(struct Nod));
	Initializare(radacina);
	for (i = 1; i <= n; i++)
    {
        scanf("%s",&v);
        Adauga(v,radacina);
    }

    /*inaltime(0,radacina);
    printf("%d ",compar);
    numar_pagini(radacina);
    printf("%d",p);*/
    ordine_lexicografica(cuv,0,radacina);
    printf("%s",compara);




	return 0;
}
