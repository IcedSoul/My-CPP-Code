#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=9;
char map[maxn][maxn];
int visit[maxn][maxn];
bool ans=0;
int n,m,t;
int abs(int x){
	return x>=0?x:-x;
}
void dfs(int x,int y,int time){
	if(ans) return;
	if(x-1>=0){
		if(visit[x-1][y]==3 && time==t){
			ans=1;
			return;
		}
		if(visit[x-1][y]==0){ 
			visit[x-1][y]=1;
			dfs(x-1,y,time+1);
			visit[x-1][y]=0;
		}
	}
	if(x+1<n){
		if(visit[x+1][y]==3 &&time==t){
			ans=1;
			return;
		}
		if(visit[x+1][y]==0){
			visit[x+1][y]=1;
			dfs(x+1,y,time+1);
			visit[x+1][y]=0;
		}
	}
	if(y-1>=0){
		if(visit[x][y-1]==3 && time==t){
			ans=1;
			return;
		}
		if(visit[x][y-1]==0){
			visit[x][y-1]=1;
			dfs(x,y-1,time+1);
			visit[x][y-1]=0;
		}
	}
	if(y+1<m){
		if(visit[x][y+1]==3 && time==t){
			ans=1;
			return;
		}
		if(visit[x][y+1]==0) {
			visit[x][y+1]=1;
			dfs(x,y+1,time+1);
			visit[x][y+1]=0;
		}
	}
	return;
}
int main(){
	while(cin>>n>>m>>t){
		if(n==0 && m==0 && t==0) break;
		int x,y,x2,y2,k1,k2;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				cin>>map[i][j];
				if(map[i][j]=='X')
					visit[i][j]=-1;
				else if(map[i][j]=='S'){
					visit[i][j]=2;
					k1=(i+j)%2;
					x=i;y=j;
				}
				else if(map[i][j]=='D'){
					visit[i][j]=3;
					x2=i;y2=j;
					k2=(i+j)%2;
				}
				else
					visit[i][j]=0;
			}
		k1=(k1+k2)%2;
		if((k1==0 && t%2==1)||(k1==1 && t%2==0)||(abs(x2-x)+abs(y2-y)>t)){
			cout<<"NO"<<endl;
			continue;
		}
		ans=0;
		dfs(x,y,1);
		if(ans)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
	}
	return 0;
}
