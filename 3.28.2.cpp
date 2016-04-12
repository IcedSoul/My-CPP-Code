#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int t;
int n;
long long ans,x;
long long GCD(long long a,long long b){
	if(a%b==0)
		return b;
	else return GCD(b,a%b);
}
long long LCM(long long a,long long b){
	return a*b/GCD(a,b);
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		cin>>ans;
		for(int i=1;i<n;i++){
			cin>>x;
			ans=LCM(ans,x);
		}
		cout<<ans<<endl;
	}
	return 0;
}