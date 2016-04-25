#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <map>
#include <queue>
#include <cstdio>
using namespace std;
const int maxn=10000005;
int n,n1,n2,n5;
int a[maxn],b[maxn];
int main(){
	while(scanf("%d%d%d%d",&n,&n1,&n2,&n5)!=EOF){
		for(int i=0;i<=n1+2*n2+5*n5;i++)
			b[i]=0;
		for(int i=0;i<=n1;i++){
			a[i]=1;
		}
		for(int i=0;i<=n1;i++)
			for(int j=2;j<=n2*2;j+=4)
				b[i+j]+=a[i];
		for(int i=0;i<=n1+2*n2;i++){
			a[i]=b[i];
			b[i]=0;
		}
		for(int i=0;i<=n1+n2*2;i++)
			for(int j=0;j<=n5*5;j+=10)
				b[i+j]+=a[i];
		printf("%d\n",b[n]);
	}
	return 0;
}
