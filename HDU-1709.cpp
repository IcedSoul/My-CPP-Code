#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdio>
using namespace std;
const int maxn= 10005;
int a[maxn],b[maxn],ans[maxn];
int n,v,t,num;
int main(){
	while(cin>>n){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>v;
		a[0]=1;
		a[v]=1;
		t=v;
		for(int i=1;i<n;i++){
			cin>>v;
			t+=v;
			for(int j=0;j<=t;j++){
				b[j]+=a[j];
				b[v+j]+=a[j];
				if(j-v>=0)
					b[j-v]+=a[j];
				else
					b[v-j]+=a[j];
			}
			for(int j=0;j<=t;j++){
				a[j]=b[j];
				b[j]=0;
			}
		}
		num=0;
		for(int i=0;i<t;i++)
			if(a[i]==0){
				ans[num]=i;
				num++;
			}
		cout<<num<<endl;
		if(num!=0){
			for(int i=0;i<num-1;i++)
				cout<<ans[i]<<" ";
			cout<<ans[num-1]<<endl;
		}
	}
	return 0;
}