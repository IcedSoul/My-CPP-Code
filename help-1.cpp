#include<stdio.h>
int main(void)
{
    int i,n,j;
    double s,e=0.0;
    printf("Input n: ");
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        s=1.0;
        for(j=1;j<=i;j++)
            s=s*j;
        e+=1.0/s;
        }
    printf("e=%.4f",e);
    return 0;
    
}
