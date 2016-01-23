#include<iostream>
#include<algorithm>
#include<math.h>
#define maxn 1005
using namespace std;
int dp[maxn][maxn],value[maxn],volume[maxn];
int	main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<maxn;i++){
			volume[i]=0;value[i]=0;
			for(int j=0;j<maxn;j++)
				dp[i][j]=0;
		}
		int n,v;
		cin>>n>>v;
		for(int i=1;i<=n;i++)
		  cin>>value[i];
		for(int i=1;i<=n;i++)
		  cin>>volume[i];
		for(int i=n;i>=1;i--){
			for(int j=0;j<=v;j++){
				dp[i][j]=(i==n?0:dp[i+1][j]);
				if(j>=volume[i])
					dp[i][j]=max(dp[i][j],dp[i+1][j-volume[i]]+value[i]);
			}
		}
		cout<<dp[1][v]<<endl;
	}
	return 0;
}