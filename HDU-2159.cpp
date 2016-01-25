#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#define maxn 105
using namespace std; //错误代码
int dp[maxn],a,b;
int	main(){
	int n,m,k,s;
	while(cin>>n>>m>>k>>s){
		memset(dp,0,sizeof(dp));
		int count=0,mark=0,cc=0;
		for(int i=1;i<=k;i++){
			cin>>a>>b;
			for(int j=0;j<=m;j++){
				if(j>=b){
					if(dp[j]>=dp[j-b]+a){
						dp[j]=dp[j];
					}
					else{
						count++;
						dp[j]=dp[j-b]+a;
					}
				}
				if(dp[j]>=n && mark==0){
					mark=j;
					cc=count;
				}
			}
		}
		cout<<count<<endl;
		cout<<dp[m]<<endl;
		if(mark==0 || mark>=m){
		if(dp[m]>=n && count<=s){
			cout<<m-dp[m]<<endl;
		}
		else
			cout<<"-1"<<endl;
		}
		else{
			if(cc<=count)
				cout<<m-dp[mark]<<endl;
			else
				cout<<"-1"<<endl;
		}
	}
	return 0;
}