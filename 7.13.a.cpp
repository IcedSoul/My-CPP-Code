#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define maxn 10005
using namespace std;
int main(){
	long a,b,c;
	while(scanf("%ld%ld",&a,&b)!=EOF){
		c=a-b;
		if(c<0) c=-c;
		printf("%ld\n",c);
	}
	return 0;
}