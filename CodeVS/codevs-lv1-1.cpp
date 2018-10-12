#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=10005;
long long n,t,sum=0;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		sum+=t;
	}
	cout<<sum;
	return 0;
}