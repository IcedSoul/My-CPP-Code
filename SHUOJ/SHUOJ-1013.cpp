#include<iostream> //超时的代码
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=25;
int map[maxn][maxn];
int n,m,x,y;
int dir[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{2,1},{2,-1},{1,2},{1,-2}};
long long ans[maxn][maxn];
int main(){
    cin>>n>>m>>x>>y;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            map[i][j]=0;
    map[x][y]=1;
    for(int i=0;i<8;i++){
        int tempx=x+dir[i][0];
        int tempy=y+dir[i][1];
        if(tempx>=0 && tempy<=n && tempy>=0 && tempy<=m){
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
    cout<<ans[n][m];
    return 0;
} 