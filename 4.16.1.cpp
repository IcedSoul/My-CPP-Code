#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=100000005;
char a[maxn];
int l;
int isHui(){
	for(int i=0;i<=l/2;i++)
		if(a[i]!=a[l-1-i])
			return 0;
	return 1;
}
int main(){
	while(cin>>a){
		l=strlen(a);
		if(isHui())
			printf("Yes\n");
		else
			printf("NO\n");
		memset(a,0,sizeof(a));
	}
    return 0;
}