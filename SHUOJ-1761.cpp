#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<math.h>
typedef long long  l;
using namespace std;
#define maxn 100000005
l c[maxn];
int cc(int a,int b,int m){
    for(int i=0;i<maxn;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%1000000007;
        }
    }   
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%lld\n",c[n][m]);
    }
}