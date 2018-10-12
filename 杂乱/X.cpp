#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5000;
int n,m;
long long ans[maxn][maxn];
int main(){
	while(cin>>n>>m){
	for(int i=0;i<=m;i++) ans[0][i]=1;
	for(int i=0;i<=n;i++) ans[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
				ans[i][j]=ans[i-1][j]+ans[i][j-1];
	cout<<ans[n][m]<<endl;
}
	return 0;
} 
