#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=1000005;
int a[15],b,c,d;
int main(){
	while(cin>>a[0]){
		for(int i=1;i<12;i++)
			cin>>a[i];
		b=0;c=0;d=0;
		for(int i=0;i<12;i++){
			b+=300;
			if(b<a[i]){
				c=i+1;
				break;
			}
			else{
				b-=a[i];
				d+=b/100;
				b=b%100;
			}
		}
		if(c!=0)
			cout<<-c<<endl;
		else
			cout<<d*100*1.2+b<<endl;
	}
	return 0;
}