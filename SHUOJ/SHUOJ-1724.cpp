#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=10005;
int map[25][25];
int dir[4][2]={{-1,2},{-2,1},{2,1},{1,2}};
int m,n,a,b,c,d;
struct T{
    int x,y;
};
T sa,sb;
int bfs(int x,int y){
    queue<T> Q;
    sa.x=x;
    sa.y=y;
    map[x][y]=0;
    Q.push(sa);
    while(!Q.empty()){
        sa=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int xx=sa.x+dir[i][0];
            int yy=sa.y+dir[i][1];
            if(xx<=m && xx>=0 && yy<=n&& yy>=0){
                sb.x=xx;
                sb.y=yy;
                if(map[sa.x][sa.y]+1<map[xx][yy]){
                    map[xx][yy]=map[sa.x][sa.y]+1;
                    Q.push(sb);
                }
                 
            }
        }
    }
}
int main(){
    while(cin>>m>>n){
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                map[i][j]=maxn;
        cin>>a>>b>>c>>d;
        bfs(a,b);
        if(map[c][d]==maxn){
            cout<<"Impossible"<<endl;
        }
        else
            cout<<map[c][d]<<endl;
    }
    return 0;
} 
