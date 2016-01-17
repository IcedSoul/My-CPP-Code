#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<math.h>
using namespace std;
#define maxn 100005
long long c(int a,int b,int m){
	long long ans=1,t=a;
	while(b>0){
		if(b%2==1) ans=ans*t;
		b/=2;
		t=(t*t);
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%lld\n",c(n,m));
	}
}