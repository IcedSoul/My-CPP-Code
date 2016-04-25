#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;
const int maxn=100005;
string x;
char f[maxn];
int l,a,b,counts,num[maxn];
int main(){
	while(cin>>x){
		memset(f,0,sizeof(f));
		counts=0;
		stack<char> S,B;
		l=x.length();
		for(int i=0;i<l;i++){
			if(x[i]=='+' || x[i]=='-'){
				b=1;a=0;
				while(!B.empty()){
					a+=b*(B.top()-'0');
					B.pop();
					b*=10;
				}
				num[counts++]=a;
				if(S.empty()){
					S.push(x[i]);	
				}
				else{
					f[counts-1]=S.top();
					S.pop();
					S.push(x[i]);
				}
			}
			else if(x[i]=='*' || x[i]=='/'){
				b=1;a=0;
				while(!B.empty()){
					a+=b*(B.top()-'0');
					B.pop();
					b*=10;
				}
				num[counts++]=a;
				if(S.empty()){
					S.push(x[i]);	
				}
				else if(S.top()=='+' || S.top()=='-'){
					S.push(x[i]);
				}
				else{
					f[counts-1]=S.top();
					S.pop();
					S.push(x[i]);
				}
			}
			else
				B.push(x[i]);
		}
		int p=counts;
		while(!S.empty()){
			f[p++]=S.top();
			S.pop();
		}
		a=0;b=1;
		while(!B.empty()){
			a+=b*(B.top()-'0');
			B.pop();
			b*=10;
		}
		num[counts++]=a;
		for(int i=0;i<counts;i++){
			cout<<num[i]<<" ";
			if(f[i]!=0)
				cout<<f[i]<<" ";
		}
		for(int i=counts;i<p;i++)
			cout<<f[i]<<" "<<endl;
		cout<<endl;
	}
    return 0;
}