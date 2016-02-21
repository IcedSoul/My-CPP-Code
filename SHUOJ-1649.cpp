#include<iostream>  
#include<cstring>  
#include<algorithm>  
#include<cstdio>  
#include<math.h>   
using namespace std;
const int maxn=1000005;
int n,q,w,sum;
int a1,a2,num;
int main(){
	while(scanf("%d",&n)){
		if(n==0) break;
		scanf("%d",&a1);
		ans[0]=0;
		for(int i=1;i<n;i++){
			ans[i]=0;
			scanf("%d",&a2);
			ans[i]=ans[i-1]+a2-a1;
			a1=a2;
		}
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			sum=0;
			scanf("%d",&w);
			for(int j=w-1;j<n;j++)
				sum+=ans[j]-ans[j-w+1]+1;
			printf("%d\n",sum);
		}
	}
	return 0;
}