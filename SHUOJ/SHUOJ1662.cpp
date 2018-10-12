#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdio>
using namespace std;
const int maxn=105;
struct T
{
	int st,et;
};
int n,ans,temp;
T a[maxn];
int cmp(T sa,T sb){
	return sa.et<sb.et;
}
int main(){
	while(cin>>n && n){
		ans=0;temp=0;
		for(int i=0;i<n;i++)
			cin>>a[i].st>>a[i].et;
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			if(a[i].st>temp){
				ans++;temp=a[i].et;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}