	#include<iostream>
	#include<cstring>
	#include<algorithm>
	#include<cstdio>
	#include<math.h> 
	using namespace std;
	const int maxn=55;
	long long ans[maxn];
	int n;
	int main(){
		for(int i=1;i<=50;i++)
				if(i==1) ans[i]=1;
				else if(i==2) ans[i]=2;
				else
					ans[i]=ans[i-1]+ans[i-2];
		while(cin>>n){
			cout<<ans[n]<<endl;
		}
		return 0;
	}
