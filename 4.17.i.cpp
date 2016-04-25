#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <queue>
using namespace std;
const int maxn=100005;
int n,m;
int ac(double x){
	m=sqrt(8.0*x+1);
	n=(m-1)/2.0;
	m=(m+1)/4.0;
	if(n*(n+1)/2==x && m*(2*m-1)==x)
		return 1;
	else
		return 0;
}
int leap(double x){
	n=x;
	if(n%400==0)
		return 1;
	else{
		if(n%100==0)
			return 0;
		else{
			if(n%4==0)
				return 1;
			else
				return 0;
		}
	}
	return 0;
}
int main(){
	for(double i=2016;i<=990528;i++)
		if(ac(i) && leap(i)){
			printf("%.0f\n",i);
		}
	return 0;
}