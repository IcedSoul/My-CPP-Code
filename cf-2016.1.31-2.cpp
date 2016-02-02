#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
const int maxn=1005;
using namespace std;
int map[maxn][maxn];
int n;
int x,y;
long long c(int a,int b){
    if(a==b) return 1;
    else if(b==1) return a;
    else return c(a-1,b)+c(a-1,b-1); 
}
void dfs(int a,int b){
    map[a][b]=1;
    for(i=1;i<=1000;i++){
        if(a+i<=1000 && b+i<=1000)
            if(map[a+i][b+i]==0)
                map[a+i][b+i]=1;
            else
                map[a+i][b+i]++;
        if(a-i>=1 && b+i<=1000)
            if(map[a-i][b+i]==0)
                map[a-i][b+i]=1;
            else
                map[a-i][b+i]++;
        if(a+i<=1000 && b-i>=0)
            if(map[a+i][b-i]==0)
                map[a+i][b-i]=1;
            else
                map[a+i][b-i]++;
        if(a-i>=0 && b-i>=0)
            if(map[a-i][b-i]==0)
                map[a-i][b-i]=1;
            else
                map[a-i][b-i]++;
    }
}
int main(){
    while(cin>>n){
        memset(map,0,sizeof(map));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
            dfs(x[i],y[i]);       
        }
        for(int i=0;i<n;i++){
            if()
        }
    }
    return 0;
}