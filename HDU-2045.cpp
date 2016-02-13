#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
using namespace std;
const int maxn=55;
long long ans[maxn];
int n;
long long num1=0,num2=1,t1,t2; 
int main(){
	ans[1]=1;
	ans[2]=2;
	for(int i=1;i<=48;i++){
		ans[i+2]=3*num1+2*num2;
		t1=num1;
		t2=num2;
		num1=2*t2+t1;
		num2=t1;
	}
	while(cin>>n){
		cout<<3*ans[n]<<endl;
	}
	return 0;
}
