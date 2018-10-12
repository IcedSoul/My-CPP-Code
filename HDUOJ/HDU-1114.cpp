#include<iostream>
#include<algorithm>
#include<math.h>
#define maxn 10005
#define dada 1000000
using namespace std;
int dp[maxn],value,weight;
int	main(){
	int t;
	cin>>t;
	while(t--){
		dp[0]=0;
		for(int i=1;i<maxn;i++)
			dp[i]=dada;
		int e,f;
		cin>>e>>f;
		int c=f-e;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>value>>weight;
			for(int j=0;j<=c;j++){
					if(j>=weight)
						dp[j]=min(dp[j],dp[j-weight]+value);
			}
		}
		if(dp[c]==dada){
			cout<<"This is impossible."<<endl;
		}
		else
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[c]<<"."<<endl;
	}
	return 0;
}