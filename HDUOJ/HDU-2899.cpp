#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>
using namespace std;
double f(double y,double x){
	return 42.0*pow(x,6.0)+48.0*pow(x,5.0)+21.0*pow(x,2.0)+10.0*x-y;
}
double ff(double y,double x){
	return 6.0*pow(x,7.0)+8.0*pow(x,6.0)+7.0*pow(x,3.0)+5.0*pow(x,2.0)-y*x;
}
int main(){
	int t;
	double y,a=0,b=0,c=100;
	cin>>t;
	while(t--){
		cin>>y;
		if(f(y,100.0)<0)
		{
			printf("%.4lf\n",ff(y,100.0));
			continue;
		}
		else{
			a=0,c=100;
			while(c-a>0.00000001){
				b=(a+c)/2.0;
				if(f(y,b)<0)
					a=b;
				else
					c=b;
			}
			printf("%.4lf\n",ff(y,b));
		}
		
	}
	return 0;
}
