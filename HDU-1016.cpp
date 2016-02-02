#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
using namespace std;
const int maxn=25;
int n;
int prime[11]={3,5,7,11,13,17,19,23,29,31,37};
int visit[maxn];
int ans[maxn];
int IsPrime(int x){
    if(x==1) return 0;
    for(int i=2;i<=sqrt((double)x);i++)
        if(x%i==0) return 0;
        return 1;
}
void dfs(int x){
    if(x==n) {
    if(IsPrime(ans[n-1]+ans[0])){
        for(int i=0;i<n-1;i++)
            printf("%d ",ans[i]);
            printf("%d\n",ans[n-1]);
    }
    }
    else{
        for(int i=0;prime[i]-ans[x-1]<=n && x<n;i++){
            int temp=prime[i]-ans[x-1];
            if(temp>1 && temp<=n){
                if(visit[temp]==0){
                    ans[x]=temp;
                    visit[temp]=1;
                    dfs(x+1);
                    visit[temp]=0;
            }
        }
        }
    }
    return;
}
int main(){
    int count=0;
    while(cin>>n){
        printf("Case %d:\n",++count);
        memset(ans,0,sizeof(ans));
        memset(visit,0,sizeof(visit));
        ans[0]=1;
        visit[1]=1;
        dfs(1);
        printf("\n");
    }
    return 0;
}