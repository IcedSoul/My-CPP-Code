#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
using namespace std;
long long c(int m,int n){
	if(n==0 || m==n) return 1;
	if(n==1) return m;
	else return c(m-1,n-1)+c(m-1,n);
}
int x,y;
int main(){
	while(cin>>x>>y){
		cout<<c(x,y)<<endl;
	}
	return 0;
}
