#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
using namespace std;
double ans[25];
int d,n;
long long v=2;
long long t1,t2,t;
int main(){
	ans[1]=0;ans[2]=50;
	t1=0;t2=1;
	for(int i=3;i<=20;i++){
		v=v*i;
		t=(t1+t2)*(i-1);
		ans[i]=(double)t*100/(double)v;
		t1=t2;
		t2=t;
	}
	cin>>d;
	while(d--){
		cin>>n;
		printf("%.2lf%%\n",ans[n]);
	}
	return 0;
} 

