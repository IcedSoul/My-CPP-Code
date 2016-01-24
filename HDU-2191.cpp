#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#define maxn 105
using namespace std;
int dp[maxn],a,b,c;
int	main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>a>>b>>c;
			for(int j=1;j<=c;j++)
				for(int k=n;k>=0;k--)
					if(k>=a)
						dp[k]=max(dp[k],dp[k-a]+b);
		}
		cout<<dp[n]<<endl;
	}

	return 0;
}