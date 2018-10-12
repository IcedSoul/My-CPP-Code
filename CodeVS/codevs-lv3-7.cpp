#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <map>
#include <cstdio>
using namespace std;
int n,counts,a,ans;
int main(){
	scanf("%d",&n);
	scanf("%d",&ans);
	counts=1;
	for(int i=1;i<n;i++){
		scanf("%d",&a);
		if(a==ans)
			counts++;
		else
			counts--;
		if(counts==0){
			ans=a;
			counts=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}