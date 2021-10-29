#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* bkt(char* sir);
int valid(char* sir)
{
    int val=0;
    int size =strlen(sir);
    for(int i=0;i<size;i++)
    {
        if(strcmp(sir,bkt(sir))==0)
        {
            val+=1;
        }
    }
    if(val==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char* bkt(char* sir)
{
    int len = strlen(sir);
    char* ret =(char*)malloc(len);
    if(valid(sir)==1)
    {
        printf("palindrom");
    }
    else
    {
        strcpy(ret,"");
        for(int i=len-1;i>=0;i--)
        {
            strcat(ret[i],sir);
        }
    }
    return ret;
}
