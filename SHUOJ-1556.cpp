#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
using namespace std;
const int maxn=10;
int n,m;
int map[maxn][maxn];
int visit[maxn][maxn];
int vis[maxn];
bool ans=0;
int t;
void dfs(int x,int y){
	if(ans==1) return;
	if(x==9){
		ans=1;
		return;
	}
	
	for(int j=y;j<=y+1;j++){
		if(vis[map[x+1][j]]==0 && visit[x+1][j]==0){
			vis[map[x+1][j]]=x;
			visit[x+1][j]=1;
			dfs(x+1,j);
			visit[x+1][j]=0;
			vis[map[x+1][j]]=0;
		}
	}
}
int main(){
	int count=1;
	cin>>t;
	while(t--){
		for(int i=1;i<=9;i++){
			for(int j=1;j<=i;j++){
				visit[i][j]=0;
				cin>>map[i][j];
			}
			vis[i]=0;
		}
		ans=0;
		vis[map[1][1]]=1;
		dfs(1,1);
		cout<<"Case "<<count++<<":"<<endl;
		if(ans==1)
			cout<<"Possible"<<endl;
		else
			cout<<"Impossible"<<endl;
			
	}
	return 0;
}
