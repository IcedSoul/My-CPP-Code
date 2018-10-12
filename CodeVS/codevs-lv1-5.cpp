#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=40000;
long long a[maxn];
long long n,i,d,l,r,m;
int main(){
	a[0]=0;
	for(i=1;;++i){
		a[i]=a[i-1]+i;
		if(a[i]>10000000)
			break;
	}
	cin>>n;
	if(n!=1){
		l=0;r=i,m=(l+r)/2;
		while(l+1!=r){
			if(n<=a[m])
				r=m;
			else
				l=m;
			m=(l+r)/2;
		}
		int d=n-a[l];
		if(r%2==1){
			l=r-d+1;
			r=d;
		}
		else{
			r=r-d+1;
			l=d;
		}
		if(l==0){
			l=1;
			r--;
		}
		if(r==0){
			r=1;
			l--;
		}
	}
	else{
		l=1;r=1;
	}
	cout<<l<<"/"<<r<<endl;
	return 0;
}