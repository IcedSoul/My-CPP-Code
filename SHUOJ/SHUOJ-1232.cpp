#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
using namespace std;
const int maxn=1005;
int a[maxn];
int b[maxn];
int n,temp,ans;
int main(){
	while(cin>>n){
		if(n==0) break;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		temp=-1;ans=0;
		for(int i=0;i<n;i++){
			for(int j=temp+1;j<n;j++){
				if(b[i]<a[j]){
					ans++;
					temp=j;
					break;
				}
			}
			if(ans>n/2) break;
		}
		if(ans>n/2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
