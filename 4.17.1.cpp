#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <queue>
using namespace std;
const int maxn=1005;
int t;
int a,b,c,d;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a+b+c+d>=80)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}