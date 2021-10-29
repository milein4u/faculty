 /*I. Fie un sistem de gestionare a unor cozi de mesaje. Un mesaj este caracterizat printr-un ID (intreg), o prioritate (intreg) și mesajul propriu zis (șir de caractere).
Să se scrie și sa se implementeze un planificator pentru deservirea mesajelor bazat pe o structura  de tip multilistă. Structura multilistă va conține o listă ordonată de categorii de priorități implementată static (cu tablou), și fiecare categorie va avea o coadă circulară, implementată dinamic (cu pointeri), pentru retinerea mesajelor din acea categorie.

 Sa se implementeze următoarele funcționalități:

 Adăugare categorie de priorități (se va adăuga o categorie nouă, menținând lista ordonată)

 Adăugare mesaj (se va adaugă un mesaj in coada corespunzătoare priorității sale)

 Deservire mesaj (se va scoate cel mai vechi mesaj din cea mai prioritara categorie a cărei cozi nu este goala)


II. Implementati problema de mai sus in varianta in care lista de prioritati este implementata cu pointeri si coada de mesaje este implementata static (cu tablou de maxim 10 elemente). (Obs: functionalitatiile sunt aceleasi cu cele de la problema precedenta).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define len 10

typedef struct mesaj{
	int ID;
	int prioritate;
	char text[150];
}txt;

typedef struct planificator{
	int prt;
	int cnt;
	struct mesaj list[len];
	struct planificator *next;
}plan;

plan *add_priority(plan *rad,int P){
	plan *nou = (plan*)malloc(sizeof(plan));
	nou->cnt = 0;
	nou->prt = P;
	if (rad == NULL){
		nou->next = NULL;
		rad = nou;
		return rad;
	}
	if (nou->prt < rad->prt){
		nou->next = rad;
		rad = nou;
		return rad;
	}
	if (rad->next == NULL){
		nou->next = NULL;
		rad->next = nou;
		return rad;
	}
	plan *p;
	for (p = rad; p->next != NULL; p = p->next){
		if (nou->prt < p->next->prt)
		{
			nou->next = p->next;
			p->next = nou;
			return rad;
		}
	}
	nou->next = NULL;
	p->next = nou;
	return rad;
}

txt *init_mesaj(int P,char *mes){
	txt *nou = (txt*)malloc(sizeof(txt));
	nou->ID = rand() % 100;
	nou->prioritate = P;
	strcpy(nou->text, mes);
	return nou;
}

void adauga_mesaj(plan *rad,txt *nou){
	plan *p;
	for (p = rad; p != NULL; p = p->next){
		if (p->prt == nou->prioritate){
			if (p->cnt < len){
				p->list[p->cnt] = *nou;
				p->cnt++;
				return;
			}
			else{
				printf("Nu mai e loc in coada\n");
				return;
			}
		}
	}
	printf("Nu exista o coada cu prioriatea acestui mesaj\n");
	return;
}

void deservire_mesaj(plan *rad){
	plan *p;
	for (p = rad; p != NULL; p = p->next){
		if (p->cnt != 0){
			p->cnt--;
			return;
		}
	}
}


void afisare(plan *rad){
	plan *p;
	int i;
	for (p = rad; p != NULL; p = p->next){
		printf("Prioritate Coada: %d\n", p->prt);
		if (p->cnt == 0)
			printf("Coada este goala\n");
		else
			for (i = 0; i < p->cnt; i++)
				printf("%s\nmesaj prioritate: %d\nmesaj ID: %d\n", p->list[i].text,p->list[i].prioritate,p->list[i].ID);
		printf("\n");
	}
}

int main(){
	plan *GST = NULL;
	GST = add_priority(GST, 10);
	GST = add_priority(GST, 1);
	GST = add_priority(GST, 7);
	GST = add_priority(GST, 4);
	txt *m1=NULL, *m2=NULL, *m3=NULL, *m4=NULL, *m5=NULL, *m6=NULL, *m7=NULL;
	m1=init_mesaj(1, "Ana are un mar");
	m2=init_mesaj(4, "Ana are doua mere");
	m3=init_mesaj(4, "Ana are trei mere");
	m4=init_mesaj(7, "Ana are patru mere");
	m5=init_mesaj(7, "Ana are cinci mere");
	m6=init_mesaj(10, "Ana are sase mere");
	m7=init_mesaj(10, "Ana are sapte mere");
	adauga_mesaj(GST, m1);
	adauga_mesaj(GST, m2);
	adauga_mesaj(GST, m3);
	adauga_mesaj(GST, m4);
	adauga_mesaj(GST, m5);
	adauga_mesaj(GST, m6);
	adauga_mesaj(GST, m7);
	afisare(GST);
	printf("\n\nDupa o deservire\n\n");
	deservire_mesaj(GST);
	afisare(GST);
	printf("\n\nDupa doua deserviri\n\n");
	deservire_mesaj(GST);
	afisare(GST);
	return 0;
}
