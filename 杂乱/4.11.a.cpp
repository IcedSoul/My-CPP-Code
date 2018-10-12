#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=1005;
int n,a[maxn][maxn],num[maxn],v[maxn],counts,ans;
int check(){
	for(int i=0;i<=n;i++)
		if(v[i]==0)
			return 0;
	return 1;
}
void dfs(int x){
	if(ans==1) return;
	for(int i=0;i<num[x];i++){
		if(check() && a[x][i] == 0){
			ans=1;
			break;
		}
		if(v[a[x][i]]==0){
			v[a[x][i]]=1;
			dfs(a[x][i]);
			v[a[x][i]]=0;
		}
	}
}
int main(){
	counts=0;
	while(cin>>n && n){
		ans=0;
		memset(a,0,sizeof(a));
		memset(num,0,sizeof(num));
		memset(v,0,sizeof(v));
		getchar();
		char c;int t=0;
		for(int i=1;i<=n;i++){
			c=0;
			for(int j=0;c!='\n';j++){
				scanf("%d",&a[i][j]);
				c=getchar();
				if(a[i][j]==0){
					a[0][t++]=i;
					num[0]++;
				}
				num[i]=j+1;
			}
		}
		v[0]=1;
		dfs(0);
		cout<<"Case "<< ++counts;
		if(ans==1)
			cout<<": Granny can make the circuit."<<endl;
		else
			cout<<": Granny can not make the circuit."<<endl;
	}
	return 0;
}