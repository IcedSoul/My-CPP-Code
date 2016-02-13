#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=10005;
int map[10][10];
int dir[8][2]={{-1,2},{-2,1},{2,1},{1,2},{-1,-2},{-2,-1},{2,-1},{1,-2}};
char aa,cc;
int a,b,c,d;
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
        for(int i=0;i<8;i++){
            int xx=sa.x+dir[i][0];
            int yy=sa.y+dir[i][1];
            if(xx<=8 && xx>=1 && yy<=8&& yy>=1){
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
    while(cin>>aa>>b>>cc>>d){
        for(int i=0;i<=9;i++)
            for(int j=0;j<=9;j++)
                map[i][j]=maxn;
        a=aa-'a'+1;
        c=cc-'a'+1;
        bfs(a,b);
        cout<<aa<<b<<"==>"<<cc<<d<<": "<<map[c][d]<<" moves"<<endl;
    }
    return 0;
} 
