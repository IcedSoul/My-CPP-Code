#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
	int a[10];
	a[0]=1;a[1]=1;
	for(int i=2;i<=9;i++)
		a[i]=i*a[i-1];
	for(int i=1;i<=99999;i++){
		int t=i;
		long long sum=0;
		while(t>0){
			sum+=a[t%10];
			t=t/10;
		}
		if(sum==i)
			printf("%d\n",i);
	}
	return 0;
}