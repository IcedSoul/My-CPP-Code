#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <queue>
using namespace std;
const int maxn=100005;
int m,ans=0;
int a[maxn];
int main(){
	for(int i=0;i<10;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=0;i<10;i++)
		if(m+30>=a[i])
			ans++;
	printf("%d\n",ans );
	return 0;
}