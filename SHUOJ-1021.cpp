#include<iostream>  
#include<cstring>  
#include<algorithm>  
#include<cstdio>  
#include<queue>  
using namespace std;  
const int maxn=105;  
char map[maxn][maxn];  
int timemap[maxn][maxn];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};  
int t,a,b,sx,sy,ex,ey;
struct T{  
    int x,y;  
};  
T sa,sb;
int bfs(int x,int y){  
    queue<T> Q;  
    sa.x=x;  
    sa.y=y;  
    timemap[x][y]=0;  
    Q.push(sa);  
    while(!Q.empty()){  
        sa=Q.front();  
        Q.pop();
        for(int i=0;i<4;i++){
            int xx=sa.x+dir[i][0];  
            int yy=sa.y+dir[i][1];  
            if(xx<a && xx>=0 && yy<b&& yy>=0){
                if(map[xx][yy]=='-'){
                    sb.x=xx;
                    sb.y=yy;  
                    if(timemap[sa.x][sa.y]+1<timemap[xx][yy]){  
                        timemap[xx][yy]=timemap[sa.x][sa.y]+1;  
                        Q.push(sb);  
                    }  
                }
            }
        }  
    }  
}  
int main(){
    cin>>t;
    while(t--){
        cin>>a>>b;
        for(int i=0;i<a;i++)  
            for(int j=0;j<b;j++){
                timemap[i][j]=100005;
                cin>>map[i][j];
                if(map[i][j]=='S'){
                    sx=i;sy=j;
                    map[i][j]='-';
                }
                if(map[i][j]=='E'){
                    ex=i;ey=j;
                    map[i][j]='-';
                }
            }
        bfs(sx,sy);
        if(timemap[ex][ey]==100005)
            cout<<"-1"<<endl;
        else
            cout<<timemap[ex][ey]<<endl;
    }  
    return 0;  
} 
