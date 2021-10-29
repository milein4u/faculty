#include "timer.h"
#include<stdio.h>
#include<stdlib.h>
FILE *f;

int Fibo(int n){
    int a=0,b=1,c,i;
    if(n<=1)return n;
    for(i=2;i<n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return a;
}
int Fiborec(int n){
    if(n<2) return n;
    else{
            return Fiborec(n-1)+Fiborec(n-2);
    }
}

void main(){
    int ex1,ex2;
    float t1,t2;
    f=fopen("afisare.txt","w");
    starton(); ex1=Fibo(50); t1=startoff();
    fprintf(f,"Algoritm %d , timp executie %f \n",ex1,t1);
    starton(); ex2=Fiborec(50); t2=startoff();
    fprintf(f,"Algoritm %d , timp executie %f",ex2,t2);

}
