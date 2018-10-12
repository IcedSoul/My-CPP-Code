#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int maxn=1005;
int n;
char a[8];
int main(){
	cin>>n;
	while(n--){
		cin>>a;
		for(int i=0;i<8;i++){
			if((a[i]>='A' && a[i]<='C')||(a[i]>='a' && a[i]<='c')) a[i]='2';
			if((a[i]>='D' && a[i]<='F')||(a[i]>='d' && a[i]<='f')) a[i]='3';
			if((a[i]>='G' && a[i]<='I')||(a[i]>='g' && a[i]<='i')) a[i]='4';
			if((a[i]>='J' && a[i]<='L')||(a[i]>='j' && a[i]<='l')) a[i]='5';
			if((a[i]>='M' && a[i]<='O')||(a[i]>='m' && a[i]<='o')) a[i]='6';
			if((a[i]>='P' && a[i]<='S')||(a[i]>='p' && a[i]<='s')) a[i]='7';
			if((a[i]>='T' && a[i]<='V')||(a[i]>='t' && a[i]<='v')) a[i]='8';
			if((a[i]>='W' && a[i]<='Z')||(a[i]>='w' && a[i]<='z')) a[i]='9';
		}
		for(int i=0;i<8;i++){
			cout<<a[i];
			if(i==3)
				cout<<"-";
		}
		cout<<endl;
	}
	return 0;
}