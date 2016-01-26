#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#define maxn 105
using namespace std;
int dp[maxn],profit[maxn];
int	main(){
	int m,n;
	while(cin>>n>>m){
		if(m==0 && n==0) break;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cin>>profit[j];
			for(int j=m;j>=0;j--)
				for(int k=1;k<=m;k++)
					if(j>=k)
					dp[j]=max(dp[j],dp[j-k]+profit[k]);
		}
		cout<<dp[m]<<endl;
	}
	return 0;
}