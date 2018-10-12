#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#define maxn 105
using namespace std;
int dp[maxn][maxn],a,b;
int	main(){
	int n,m,k,s;
	while(cin>>n>>m>>k>>s){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=k;i++){
			cin>>a>>b;
			for(int j=0;j<=s;j++)
				for(int k=0;k<=m;k++){
				if(k>=b&&j>=1)
					dp[j][k]=max(dp[j][k],dp[j-1][k-b]+a);
			}
		}
		if(dp[s][m]<n){
			cout<<"-1"<<endl;
		}
		else{
			for(int i=m;i>=0;i--){
				if(dp[s][i]<n){
					cout<<m-i-1<<endl;
					break;
				}
			}
		}
	}
	return 0;
}