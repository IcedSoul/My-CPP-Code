#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
#define maxn 10005
using namespace std;
double dp[maxn];
int main(){
	int n,m;
	while(cin>>n>>m &&(n||m)){
		for(int i=0;i<maxn;++i)
			dp[i]=1.0;
		for(int i=1;i<=m;i++){
			int v;
			double w;
			cin>>v>>w;
			w=1.0-w;
			for(int j=n;j>=0;j--)
				if(j>=v)
				 dp[j]=min(dp[j],dp[j-v]*w);
		}
		printf("%.1f%%\n",(1-dp[n])*100);
	}
	return 0;
}