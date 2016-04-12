#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 1005
using namespace std;
char n[maxn];
int k,x,y,counts=0;;
int c[10],a[10][10];
long long ans=0;
int num(int x){
    int sum=1;
    for(int i=0;i<10;i++){
        if(a[x][i]==1){
            sum+=num(i);
        }
    }
    return sum;
}
int main()
{
    while(cin>>n>>k){
        memset(a,0,sizeof(a));
        for(int i=0;i<k;i++){
            cin>>x>>y;
            a[x][y]=1;
        }
        for(int i=0;i<10;i++){
            c[i]=num(i);
        }
        ans=1;
        int l=strlen(n);
        for(int i=0;i<l;i++)
            ans*=c[n[i]-'0'];
        cout<<ans<<endl;

        
    }
 } 