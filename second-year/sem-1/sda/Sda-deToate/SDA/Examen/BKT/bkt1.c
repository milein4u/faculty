#include<stdio.h>
#include<stdlib.h>
int sol[19],sol2[19];
int p,n;
void back(int n){
    if(n<4)
    {
        return;
    }
    printf("%d",n);
    back(2*n);
    printf("%d",n);
    
}
int main()
{
    back(1);
    getchar();
    return 0;
}