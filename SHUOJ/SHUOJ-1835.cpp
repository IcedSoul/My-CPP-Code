#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdio>
using namespace std;
const int maxn= 125;
int a[maxn],b[maxn];
int n;
int main(){
	while(cin>>n){
		for(int i=0;i<=n;i++){
			a[i]=1;
			b[i]=0;
		}
		for(int i=2;i<=n;i++){
			for(int j=0;j<=n;j++)
				for(int k=0;k+j<=n;k+=i)
					b[j+k]+=a[j];
			for(int j=0;j<=n;j++){
				a[j]=b[j];
				b[j]=0;
			}
		}
		cout<<a[n]<<endl;
	}
	return 0;
}
