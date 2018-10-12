#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
#define maxn 1005
using namespace std;
int dp[maxn],value[maxn],volume[maxn];
int	main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n,v;
		cin>>n>>v;
		for(int i=1;i<=n;i++)
		  cin>>value[i];
		for(int i=1;i<=n;i++)
		  cin>>volume[i];
		for(int i=1;i<=n;i++){
			for(int j=v;j>=0;j--){
				if(j>=volume[i])
					dp[j]=max(dp[j],dp[j-volume[i]]+value[i]);
			}
		}
		cout<<dp[v]<<endl;
	}
	return 0;
}