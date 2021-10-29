#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int N;
char ALF[100];
char MUST[100];
char PASS[100];

char sir[100];
char sirParolaNoua[100];
int c;
int x;

int parolaCorecta()
{
    if(strlen(PASS)!=strlen(sir))
            return 0;
        else
            return 1;
}

int verificareParola()
{
    int ok,i,j;

    for(i=0;i<strlen(MUST);i++)
    {
        ok=0;
        for(j=0;j<strlen(sir);j++)
        {
            if(sir[j]==MUST[i])
            ok=1;
        }
        if (ok!=1)
        return 0;
    }
    return 1;
}

void backtracking(int x)
{
    if(parolaCorecta() && verificareParola()!=0)
            c++;
        else{
                for(int i=0;i<strlen(ALF);i++)
                    {
                        if(x<N)
                        {
                            sir[x]=ALF[i];
                            sir[x+1]=0;
                            backtracking(x+1);
                        }
                    }
            }
}

void criptare(char sir2[50])
{
    char sir[50];
    if(N==x)
        sirParolaNoua[x]=NULL;
    else{
            if(strlen(sir2))
                {
                    int mijloc=strlen(sir2)/2;
                    sirParolaNoua[x++]=sir2[mijloc];
                    strcpy(sir,sir2+1+mijloc);
                    sir2[mijloc]=NULL;
                    criptare(sir2);
                    criptare(sir);
                }
    }
}

int main()
{
    scanf("%d %s %s %s", &N, ALF, MUST, PASS);
    backtracking(0);
    criptare(PASS);
    printf("%d\n%s",c,sirParolaNoua);

}
