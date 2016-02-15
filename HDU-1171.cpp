#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdio>
using namespace std;
const int maxn= 250005;
int a[maxn],b[maxn];
int n;
int v,m,t;
int counts;
int maxNum,ans1,ans2;
int main(){
	while(cin>>n){
		if(n<0) break;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>v>>m;
		for(int i=0;i<=m;i++)
			a[i*v]=1;
		t=v*m;
		for(int i=1;i<n;i++){
			cin>>v>>m;
			t+=v*m;
			for(int j=0;j<=t;j++)
				for(int k=0;k<=v*m;k+=v)
					b[j+k]+=a[j];
			for(int j=0;j<=t;j++){
				a[j]=b[j];
				b[j]=0;
			}
		}
		counts=0;
		for(int i=1;i<=t;i++){
			if(a[i]!=0)
				b[counts++]=i;
		}
		sort(b,b+counts);
		maxNum=maxn;
		for(int i=0;i<counts;i++){
			if(t-b[i]>=b[i]){
				if(t-b[i]-b[i]<maxNum){
					maxNum=t-b[i]-b[i];
					ans1=t-b[i];
					ans2=b[i];
				}
			}
			else{
				if(2*b[i]-t<maxNum){
					maxNum=2*b[i]-t;
					ans1=b[i];
					ans2=t-b[i];
				}
			}
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}