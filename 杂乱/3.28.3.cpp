#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=15;
char key[maxn],t[105],a[maxn][maxn];
int l,ll,counts,sss[15];
typedef struct T
{
	char k;
	int num;
}T;
T kk[maxn];
int cmp(T aa,T bb){
	return aa.k < bb.k;
}
int main(){
	while(cin>>key){
		counts=0;
		l=strlen(key);
		if(l==6 && key[0]=='T' && key[1]=='H' && key[2]=='E' && key[3]=='E' && key[4]=='N' && key[5]=='D') break;
		for(int i=0;i<l;i++){
			kk[i].num=i;
			kk[i].k=key[i];
		}
		cin>>t;
		ll=strlen(t);
		counts=0;
		sort(kk,kk+l,cmp);
		for(int i=0;i<l;i++){
			if(i<ll%l)
				sss[i]=(ll-1)/l+1;
			else
				sss[i]=(ll-1)/l;
		}
		for(int i=0;i<l;i++){
			for(int j=0;j<=sss[i];j++)
				a[j][kk[i].num]=t[counts++];
		}
		for(int i=0;i<=(ll-1)/l;i++)
			for(int j=0;j<l;j++)
				cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}