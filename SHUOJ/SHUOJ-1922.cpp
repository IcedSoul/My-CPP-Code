#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=305;
int t,n,a[maxn],b[maxn],ans=0;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			cin>>b[i];
			a[b[i]]=1;
		}
		ans=0;
		for(int i=0;i<n;i++){
			if(a[2*b[i]]==1)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}