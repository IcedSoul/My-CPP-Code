#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int maxn=1005;
int m,n;
long long c(int a,int b){
	if(b==1) return a;
	if(a==b) return 1;
	else return c(a-1,b)+c(a-1,b-1);
}
long long j(int n){
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans*=i;
	return ans;
}
int main(){
	while(cin>>m>>n){
		cout<<c(n,m)*j(n-1)*j(m)<<endl;
	}
	return 0;
}