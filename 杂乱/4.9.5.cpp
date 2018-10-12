#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=10005;
int t,n;
int edd(int nn){
	int ans=1;
	while(nn>0){
		if(nn%2==1) ans= ans << 1;
		nn= nn >> 1;
	}
	return ans;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",edd(n));
	}
	return 0;
}