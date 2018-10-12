#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=5005;
int t,la,lb;
int dp[maxn][maxn];
string a,b;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b;
		la=a.length();
		lb=b.length();
		memset(dp,0,sizeof(dp));
		for(int i=0;i<la;i++)
			for(int j=0;j<lb;j++)
				if(a[i]==b[j])
					dp[i+1][j+1]=dp[i][j]+1;
				else
					dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
		cout<<dp[la][lb]<<endl;
	}
    return 0;
}