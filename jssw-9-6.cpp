#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <queue>
using namespace std;
const int maxn=105;
int a[maxn][maxn];
int t1,t2;
int m,n;
bool ans;
void dfs(int x){
	if(ans==1) return;
	for(int i=0;i<n;i++){
		if(a[x][i]==1 && a[i][x]==1){
			ans=1;
			return;
		}
		if(a[x][i]==1)
			for(int j=0;j<n;j++)
				if(a[i][j]==1)
					a[x][j]=1;
	}
}
int main(){
	while(cin>>n>>m){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=0;
		for(int i=0;i<m;i++){
			cin>>t1>>t2;
			a[t1][t2]=1;
		}
		ans=0;
		for(int i=0;i<n;i++)
			dfs(i);
		if(ans==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}