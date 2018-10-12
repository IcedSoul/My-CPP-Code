#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <queue>
using namespace std;
const int maxn=100005;
int m,n;
int a[maxn];
int main(){
	cin>>m>>n;
	for(int i=0;i<m;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		next_permutation(a,a+m);
	for(int i=0;i<m-1;i++)
		cout<<a[i]<<" ";
	cout<<a[m-1]<<endl;
	return 0;
}