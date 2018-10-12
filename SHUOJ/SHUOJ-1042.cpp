#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=10005;
int l,m,x,y;
int s[maxn],counts=0;
int main(){
	cin>>l>>m;
	counts=l+1;
	for(int i=0;i<=l;i++)
		s[i]=1;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		for(int j=x;j<=y;j++){
			if(s[j]==1){
				counts--;
				s[j]=0;
			}
		}
	}
	cout<<counts;
	return 0;
}