#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=10005;
string a[maxn],b;
int main(){
	int i=0;
	while(cin>>b){
		a[i++]=b;
	}
	for(i=i-1;i>0;i--)
		cout<<a[i]<<" ";
	cout<<a[0];
	return 0;
}