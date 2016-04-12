#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=100005;
int a[maxn];
int n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
		cout<<a[i]<<" ";
	cout<<a[n-1];
	return 0;
}