#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
int n,k,counts,num,c[50005];
int xx,yy,x,y;
int a[50005];
int GCD(int xa,int ya){
	if(xa%ya==0)
		return ya;
	else
		return GCD(ya,xa%ya);
	return 0;
}
int main(){
	while(cin>>n>>k){
		cin>>x;
		getchar();
		cin>>y;
		counts=0;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int b;
		for(int i=0;i<n;i++)
		{
			if(k-i<=n){
				int s=max(k-i,n+1); 
				for(int j=s;j<=n;j++){
					b+=a[i]*a[j];
					c[counts++]=a[i]+a[j];
				}
			}
		}
		cout<<b<<" "<<x<<endl;
		xx=x*b;
		yy=y*(n*(n-1))/2;
		if(xx!=0){
		int temp=GCD(xx,yy);
		xx=xx/temp;
		yy=xx/temp;
		}
		else xx=0;
		sort(c,c+counts);
		num=0;
		for(int i=1;i<counts;i++){
			if(c[i]!=c[i-1])
				num++;
		}
		if(xx!=0){
			cout<<xx<<"/"<<yy<<endl;
		}
		else
			cout<<"Impossible."<<endl;
		cout<<num<<endl;

	}
	
	return 0;
}