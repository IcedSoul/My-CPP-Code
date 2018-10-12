#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=1000005;
long long t,x,counts;
long long GCD(long long m,long long n){
	if(m%n==0) return n;
	return GCD(n,m%n);
}
long long LCM(long long n){
	if(n==2) return 2;
	return (LCM(n-1)/(GCD(LCM(n-1),n)))*n%1000000007;
}
long long isPrime(long long n){
	for(int i=2;i<=sqrt((double)n);i++)
		if(n%i==0)
			return 0;
	return 1;
}
long long Num(long long n){
	if(n==2) return 2;
	return Num(n-1)*(isPrime(n)?n:1)%1000000007;
}
int main(){
	cin>>t;
	counts=0;
	while(t--){
		cin>>x;
		cout<<"Case: "<<++counts<<":"<<LCM(x)/Num(x)%1000000007<<endl;
	}
	return 0;
}