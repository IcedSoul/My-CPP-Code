#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int n,m;
int map[10][10];
int timemap[10][10];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct T{
	int x,y;
};
int ans=0;
T sa,sb;

void bfs(int x,int y){
	queue<T> Q;
	sa.x=x;
	sa.y=y;
	Q.push(sa);
	while(!Q.empty()){
		sa=Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int xx=sa.x+dir[i][0];
			int yy=sa.y+dir[i][1];
			if(xx>=0 && xx <n && yy>=0 && yy<m){
				if(map[xx][yy]>map[sa.x][sa.y]){
				sb.x=xx;
				sb.y=yy;
				if(timemap[xx][yy]<timemap[sa.x][sa.y]+1){
					timemap[xx][yy]=timemap[sa.x][sa.y]+1;
					Q.push(sb);
				}
			}
			}
		}
	}
}
int main(){
	while(cin>>n>>m){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				cin>>map[i][j];
			}
		ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				for(int l=0;l<n;l++)
					for(int k=0;k<m;k++)
						timemap[l][k]=1;
				bfs(i,j);
				int max=0;
				for(int l=0;l<n;l++)
					for(int k=0;k<m;k++)
						if(timemap[l][k]>max)
							max=timemap[l][k];	
				if(ans<=max){
					ans=max;
				}
				
			}
		cout<<ans<<endl;
	}
	return 0;
}
