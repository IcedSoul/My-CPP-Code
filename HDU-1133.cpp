#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
using namespace std;
const int maxn=105;
long long a(int x){
	if(x==0) return 1;
	if(x==1) return 1;
	return x*a(x-1);
} 
int main(){
	long long ans[maxn][maxn];
	int m,n;
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++){
			if(i<j) ans[i][j]=0;
			else if(j==0) ans[i][j]=1;
			else{
				ans[i][j]=ans[i][j-1]+ans[i-1][j];
			}
	}
	while(cin>>m>>n){
		if(m==0 && n==0) break;
		cout<<ans[m][n]*a(m)*a(n)<<" "<<a(m)<<" "<<a(n)<<endl;
	}
	return 0;
} 
