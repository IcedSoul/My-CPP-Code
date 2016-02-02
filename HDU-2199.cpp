#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>
using namespace std;
double f(double x){
	return 8.0*pow(x,4.0)+7.0*pow(x,3.0)+2.0*pow(x,2.0)+3.0*x+6.0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		double y;
		cin>>y;
		if(f(0)<=y && f(100)>y){
			double ans=0;
			double a=0,b=50,c=100;
			while((c-a)>=0.000001){
				if(f(b)==y){
					ans=b;break;
				}
				else if(f(b)>y){
					c=b;
					b=(a+c)/2.0;
				}
				else{
					a=b;
					b=(a+c)/2.0;
				}
			}
			if(ans!=0)
				printf("%.4lf\n",ans);
			else
				printf("%.4lf\n",(a+c)/2);
		}
		else
			cout<<"No solution!"<<endl;
	}
	return 0;
}