#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn=1005;
int t;
int n;
int a[maxn],ans;
int main(){
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		while(n>4){
			ans+=min(2*a[0]+a[1]+a[n-2]+a[n-1],a[0]+3*a[1]+a[n-1]);
			n-=2;
		}
		cout<<ans<<endl;
		if(n==1)
			ans+=a[0];
		else if(n==2)
			ans+=a[1];
		else if(n==3)
			ans+=a[0]+a[1]+a[2];
		else if(n==4)
			ans+=min(2*a[0]+a[1]+a[2]+a[3],a[0]+3*a[1]+a[3]);
		cout<<ans<<endl;
	}
	return 0;
}