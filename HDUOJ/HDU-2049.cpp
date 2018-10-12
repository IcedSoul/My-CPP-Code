#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
using namespace std;
long long ans[25];
int a,b,t;
long long c(int m,int n){
	if(n==0) return 1;
	if(m==n) return 1;
	if(n==1) return m;
	else return c(m-1,n-1)+c(m-1,n);
}
int main(){
	ans[1]=0;ans[2]=1;
	for(int i=3;i<=20;i++){
		ans[i]=(ans[i-1]+ans[i-2])*(i-1);
	}
	ans[1]=1;
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<c(a,a-b)*ans[b]<<endl;
		
	}
	return 0;
} 

