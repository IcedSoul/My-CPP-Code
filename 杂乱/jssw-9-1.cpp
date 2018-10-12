#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int maxn=1005;
struct T
{
	int d,h,m,s;
};
T a,b;
int main(){
	while(cin>>a.d>>a.h>>a.m>>a.s){
		cin>>b.d>>b.h>>b.m>>b.s;
		if(a.s+b.s>=60){
			a.s+=b.s-60;
			a.m++;
		}
		else
			a.s+=b.s;
		if(a.m+b.m>=60){
			a.m+=b.m-60;
			a.h++;
		}
		else
			a.m+=b.m;
		if(a.h+b.h>=24){
			a.h+=b.h-24;
			a.d++;
		}
		else
			a.h+=b.h;
		a.d+=b.d;
		cout<<a.d<<" "<<a.h<<" "<<a.m<<" "<<a.s<<endl;
	}
	return 0;
}