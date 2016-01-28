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
		if(b%2==1) ans=(ans*t)%m;
		b>>=1;
		t=(t*t)%m;
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int x,y,m;
		cin>>x>>y>>m;
		cout<<c(x,y,m)<<endl;
	}
}