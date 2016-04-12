#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <math.h>
using namespace std;
const int maxn=1000005;
int x;
int isPrime(){
	if(x==1) return 0;
	for(int i=2;i<=(int)sqrt((double)x);i++)
		if(x%i==0)
			return 0;
		return 1;
}
int main(){
	cin>>x;
	if(isPrime())
		cout<<"\\t"<<endl;
	else
		cout<<"\\n"<<endl;
	return 0;
}