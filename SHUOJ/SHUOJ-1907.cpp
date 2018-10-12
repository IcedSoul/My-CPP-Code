#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=1000005;
long long x,y,p,q,a,ans;
long long GCD(long long m,long long n){
	if(m%n==0) return n;
	return GCD(n,m%n);
}
int main(){
	cin>>x>>y;
	
	cout<<GCD(x,y)<<endl;
	return 0;
}