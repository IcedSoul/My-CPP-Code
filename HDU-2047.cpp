#include<iostream> 
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=25;
int map[maxn][maxn];
int n,m,x,y;
int dir[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{2,1},{2,-1},{1,2},{1,-2}};
int dir2[2][2]={{1,0},{0,1}};
long long ans=0;
void dfs(int a,int b){
	if(map[n][m]==2){
		ans++;
		return;
	}
	for(int i=0;i<2;i++){
		int tempx=a+dir2[i][0];
		int tempy=b+dir2[i][1];
		if(tempx>=0 && tempx<=n && tempy>=0 && tempy<=m){
			if(map[tempx][tempy]==0){
				map[tempx][tempy]=2;
				dfs(tempx,tempy);
				map[tempx][tempy]=0;
			}
		}
	}
	return;
}
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
	dfs(0,0);
	cout<<ans;
	return 0;
} 

