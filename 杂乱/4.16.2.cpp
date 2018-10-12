#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=1000005;
int t,n,m,counts=0;
long long a[maxn],b[maxn],c,d;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		cin>>c;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<=m;i+=c)
			a[i]=1;
		for(int i=1;i<n;i++){
			cin>>c;
			for(int j=0;j<=m;j++)  
				for(int k=0;k+j<=m;k+=c)
					b[j+k]+=a[j];     
			for(int j=0;j<=m;j++){ 
				a[j]=b[j];
				b[j]=0;
			}
		}
		cout<<"Case #"<<++counts<<": "<<a[m]<<endl;
	}
    return 0;
}