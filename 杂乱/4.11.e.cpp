#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=1000005;
int t,m;
int dp[maxn],times,value;
int main(){
	while(cin>>t>>m){
		 memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;i++){
			cin>>times>>value;
			for(int j=t;j>=times;j--)  
        		dp[j]=max(dp[j],dp[j-times]+value);
        }
    	cout<<dp[t]<<endl;
	}
	return 0;
}