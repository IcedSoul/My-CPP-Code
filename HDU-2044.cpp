#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
using namespace std;
const int maxn=55;
long long ans[maxn][maxn];
int t,a,b;
int main(){
	for(int i=1;i<=50;i++)
		for(int j=i+1;j<=50;j++){
			if(j==i+1) ans[i][j]=1;
			else if(j==i+2) ans[i][j]=2;
			else
				ans[i][j]=ans[i][j-1]+ans[i][j-2];
		}
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<ans[a][b]<<endl;
	}
	return 0;
}
