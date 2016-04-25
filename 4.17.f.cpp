#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <queue>
using namespace std;
const int maxn=100005;
int t,n,a,ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			if(a>0)
				ans++;
			if(a>ans)
				ans=a;
		}
		printf("%d\n",ans);
	}
	return 0;
}