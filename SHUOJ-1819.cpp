#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <math.h>
using namespace std;
const int maxn=1000005;
int x,y,counts,co=0;
char a[maxn];
int main(){
	while(cin>>x>>y){
		counts=0;
		while(x!=0){
			if(x%y<10)
				a[counts++]='0'+x%y;
			else{
				a[counts++]='A'+(x%y-10);
			}
			x/=y;
		}
		if(x!=0)
			a[counts++]=x+'0';
		cout<<"Case "<<++co<<": ";
		for(int i=counts-1;i>=0;i--)
			cout<<a[i];
		cout<<endl;
	}
	return 0;
}