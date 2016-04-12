#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=15;
int t,ans,counts;
char n[maxn];
int main(){
	cin>>t;
	while(t--){
		counts=0;
		cin>>n;
		int l=strlen(n);
		if(l<=2)
			cout<<"888"<<endl;
		else if(l==3){
			if(n[0]<'8')
				cout<<"888"<<endl;
			else if(n[0]=='8' && n[1] <'8')
				cout<<"888"<<endl;
			else if(n[0]=='8' && n[1] =='8' && n[2] <= '8') 
				cout<<"888"<<endl;
			else
				cout<<"1888"<<endl;
		}
		else{
			for(int i=0;i<l ;i++)
				if(n[i]=='8')
					counts++;
			if(counts<=3){
				int num=3-counts;
				for(int i=l-1;num!=0;i--)
					if(n[i]!='8'){
						num--;
						n[i]='8';
					}
			}
			else{
				
			}
		}



	}
	return 0;
}