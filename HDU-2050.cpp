#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
using namespace std;
const int maxn=10005;
int ans[maxn];
int main(){
	ans[1]=2;
	for(int i=2;i<=10000;i++)
		ans[i]=ans[i-1]+4*(i-1)+1;
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<ans[n]<<endl;
	}
	return 0;
} 
