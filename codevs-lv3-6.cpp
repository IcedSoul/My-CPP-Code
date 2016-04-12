#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <math.h>
using namespace std;
const int maxn=1000005;
int x,y,counts=0;
char a[maxn];
int main(){
	cin>>x>>y;
	while(x>=y-1){
		if(x%y<10)
			a[counts++]='0'+x%y;
		else
			a[counts++]='A'+(x%y-10);
		x/=y;
	}
	if(x!=0)
		a[counts++]=x+'0';
	for(int i=counts-1;i>=0;i--)
		cout<<a[i];

	return 0;
}