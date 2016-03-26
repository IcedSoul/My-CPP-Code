#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
int n,k,counts,num,c[50005];
double p,x,y,ans;
int a[50005]
int main(){
	while(cin>>n>>k){
		cin>>x;
		getchar();
		cin>>y;
		p=x/y;
		counts=0;
		for(int i=0;i<n;i++)
			cin>>a[i];
		double b;
		for(int i=0;i<n;i++)
		{
			if(k-i<=n){
				int s=max(k-i,n+1); 
				for(int j=s;j<=n;j++){
					b+=a[i]*a[j];
					c[counts++]=a[i]+b[i];
				}
			}
		}
		ans=(b*p)/((double)(n*(n-1))/2.0);
		sort(c,c+counts);
		num=0;
		for(int i=1;i<counts;i++){
			if(c[i]!=c[i-1])
				num++;
		}
		if(ans>0){
			cout<<ans<<endl;
		}
		else
			cout<<"Impossible."<<endl;
		cout<<num<<endl;

	}
	
	return 0;
}