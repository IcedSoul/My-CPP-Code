#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1000005;
int a[maxn];
int n,m;
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for(int i=n-1;i>n-m;i--)
			printf("%d ",a[i]);
		printf("%d\n",a[n-m]);
	}
	return 0;
}