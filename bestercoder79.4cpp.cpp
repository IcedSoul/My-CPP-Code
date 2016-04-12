#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=10000005;
int t,num[maxn];
int n,m,ans;
int gcd(int nn,int mm){
	if(nn%mm==0) return mm;
	return gcd(mm,nn%mm);
}
int pingfang(int x){
	int t=sqrt((double)x);
	if(t*t==x)
		return 0;
	else
		return 1;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=2;i<=n;i++)
			for(int j=2;j<=m;j++)
				ans+=pingfang(gcd(i,j)); 
		cout<<ans<<endl;

	}
	return 0;
}