#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=305;
int t,l;
char s[maxn],a,ans,b[maxn];
int isHui(){
	for(int i=0;i<=l/2;i++)
		if(b[i]!=b[l-1-i])
			return 0;
	return 1;
}
int main(){
	cin>>t;
	while(t--){
		cin>>s;
		ans=0;
		l=strlen(s);
		l++;
		for(int i=0;i<l;i++){
			for(int j=0;j<l-1;j++)
				b[j]=s[j];
			for(int j=0;j<=i;j++){
				b[l-j-1]=b[l-j-2];
			}
			a='a';
			for(;a<='z';a++){
				b[l-i-1]=a;
				// cout<<b<<endl;
				if(isHui()){
					ans=1;
					break;
				}
			}
			if(ans==1)
				break;
		}
		if(ans==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}