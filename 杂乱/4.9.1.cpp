#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=10005;
int t,n,m,ans;
int gcd(int nn,int mm){
	if(nn%mm==0) return mm;
	else return gcd(mm,nn%mm);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		printf("%d\n",n/gcd(n,m));
	}
	return 0;
}