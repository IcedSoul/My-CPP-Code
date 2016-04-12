#include<iostream>
#include<algorithm>
#define maxn 1005
using namespace std;
int n,k,counts,s[maxn],a[maxn];
bool isPrime(int x){
    if(x==1) return 0;
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0) return 0;
    return 1;
}
int dfs(int x,int y){
    int i,j;
    for(i=x;i>=y;i--)
    {
        s[y]=i;
        if(y>1)
           dfs(i-1,y-1);
        else{
            int p=0;
            for (j=s[0];j>0;j--){
                p+=a[s[j]];
            }
        if(isPrime(p)==1)
          counts++;
        }
    }
    return counts;
}
int main()
{
    while(cin>>n>>k){
        counts=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        s[0]=k;
        counts=dfs(n,k);
        cout<<counts<<endl;
    }
 } 