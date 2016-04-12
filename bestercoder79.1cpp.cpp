#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=10005;
int t;
double n,m;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		n=180-360/n;
		m=180-360/m;
		int x=360/n,y=360/m;
		int k=0;
		for(int i=0;i<=x;i++)
			for(int j=0;j<=y;j++)
				if(i*n+j*m==360){
					k=1;break;
				}
		if(k==0)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}