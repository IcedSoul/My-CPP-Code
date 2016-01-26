#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int a[10];
	a[0]=1;
	a[1]=3;
	a[2]=12;
	a[3]=6;
	a[4]=17;
	a[5]=9;
	a[6]=11;
	a[7]=18;
	a[8]=15;
	a[9]=16;
	int p=lower_bound(a,a+10,9)-a;
	cout<<p<<endl;
	return 0;
}