#include<iostream>
#include<algorithm>
#include<cstdio>
#define maxn 10005
using namespace std;
int main(){
	int a;
	char s[maxn];
	while(scanf("%d",&a)!=EOF){
		int i=1;
		while(a>0){
			int b=a%3;
			s[i]=(int)(b+48);
			a=(a-b)/3;
			i++;
			}
			for(int j=i-1;j>0;j--)
			putchar(s[j]);
	}
	return 0;
}