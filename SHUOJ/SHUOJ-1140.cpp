#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
char a[105],c[105];

int mark=0;
int main(){
	cin>>n;
	cin>>a;
	int count=0;
	while(count<30){
		int k=strlen(a);
		for(int i=0;i<k;i++) c[i]='0';
		c[k]='0';
		for(int i=0;i<k;i++){
			if((int)(c[i]-'0')+(int)(a[i]-'0')+(int)(a[k-1-i]-'0')>=n){
				c[i+1]='1';
				c[i]=(char)(c[i]+(int)(a[i]-'0')+(int)(a[k-1-i]-'0')-n);
			}
			else
				c[i]=(char)(c[i]+(int)(a[i]-'0')+(int)(a[k-1-i]-'0'));
		}	
		if(c[k]!='0') k++;
		for(int i=k-1;i>=0;i--){
			a[k-1-i]=c[i];
		}
		mark=1;
		for(int i=0;i<=k/2;i++){
			if(a[i]!=a[k-1-i]){
				mark=0;
				break;
			}
		}
		count++;
		if(mark==1) break;
		
	}
	if(count==30)
		cout<<"Impossible!"<<endl;
	else
		cout<<"STEP="<<count<<endl;
	return 0;
}
