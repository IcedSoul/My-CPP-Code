#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdio>
using namespace std;
const int maxn= 10005;
int a[maxn],b[maxn];
int dir[3]={1,2,5},num[3];
int main(){
	while(cin>>num[0]>>num[1]>>num[2]){
		if(num[0]==0 && num[1]==0 && num[2]==0) break;
		for(int i=0;i<=num[0]+num[1]*2+num[2]*5;i++){
			a[i]=0;
			b[i]=0;
		}
		int t=0;
		for(int i=0;i<=num[0];i++) a[i]=1;
		for(int i=1;i<3;i++){
			t+=num[i-1]*dir[i-1];
			for(int j=0;j<=t;j++)
				for(int k=0;k<=num[i]*dir[i];k+=dir[i]){
					b[j+k]+=a[j];
				}
			for(int j=0;j<=t+num[i]*dir[i];j++){
				a[j]=b[j];
				b[j]=0;
			}
		}
		int k=0;
		for(int i=0;i<=num[0]+num[1]*2+num[2]*5;i++)
			if(a[i]==0){
				k=1;
				cout<<i<<endl;
				break;
			}
		if(k==0)
			cout<<num[0]+num[1]*2+num[2]*5+1<<endl;
		
	}
	return 0;
}
