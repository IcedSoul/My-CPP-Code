#include<iostream> 
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10;
int map[maxn][maxn];
int n,m,x,y;
int dir[4][2]={{-2,-2},{-2,2},{2,-2},{2,2}};
long long ans[maxn][maxn];
int main(){
    while(cin>>x>>y>>n>>m){
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            map[i][j]=0;
    map[x][y]=1;
    for(int i=0;i<4;i++){
        int tempx=x+dir[i][0];
        int tempy=y+dir[i][1];
        if(tempx>=0 && tempx<=n && tempy>=0 && tempy<=m){
            map[tempx][tempy]=1;
        }
    }
    int k=0;
    for(int i=0;i<=m;i++){
        if(k==1)
            ans[0][i]=0;
        else
            if(map[0][i]==1){
                k=1;
                ans[0][i]=0;
            }
            else
                ans[0][i]=1;
    }
    k=0;
    for(int i=0;i<=n;i++){
        if(k==1)
            ans[i][0]=0;
        else
            if(map[i][0]==1){
                k=1;
                ans[i][0]=0;
            }
            else
                ans[i][0]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(map[i][j]==0)
                ans[i][j]=ans[i-1][j]+ans[i][j-1];
            else
                ans[i][j]=0;
        }
    cout<<ans[n][m]<<endl;
}
    return 0;
}