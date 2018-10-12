#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=105;
int t,num1,num2,num3,num4,num;
long long a,b,c,d,ans;
int sa[maxn],sb[maxn],sc[maxn],sd[maxn];
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		num1=num2=num3=num4=0;
		memset(sa,0,sizeof(sa));
		memset(sb,0,sizeof(sb));
		memset(sc,0,sizeof(sc));
		memset(sd,0,sizeof(sd));
		while(a>0){
			sa[num1++]=a%2;
			a=a>>1;
		}
		while(b>0){
			sb[num2++]=b%2;
			b=b>>1;
		}
		while(c>0){
			sc[num3++]=c%2;
			c=c>>1;
		}
		while(d>0){
			sd[num4++]=d%2;
			d=d>>1;
		}
		num=max(max(num1,num2),max(num3,num4));
		for(int i=num-1;i>=0;i--){
			if((sa[i]!=sc[i])||(sa[i]!=sd[i])||(sb[i]!=sc[i])||(sb[i]!=sd[i]))
				ans+=1<<i;
		}
		cout<<ans<<endl;


	}
	return 0;
}