#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define maxn 1005
int main(){
	int m,n;
	while(cin>>m>>n){
		double j[maxn],f[maxn];
		double jf[maxn],jf2[maxn],ans=0;
		int mark[maxn];
		if(m==-1 && n==-1) break;
		for (int i = 0; i < n; ++i)
		{
			cin>>j[i]>>f[i];
			jf[i]=j[i]/f[i];
			jf2[i]=jf[i];
			mark[i]=0;
		}
		sort(jf2,jf2+n);
		for (int i = n-1; i >= 0 && m > 0; --i)
		{
			for (int k = 0; k < n; ++k)
			{
				if(jf2[i]==jf[k] && mark[k]==0){
					mark[k]=1;
					if(m>=f[k]){
						m-=f[k];
						ans+=j[k];
					}
					else
					{
						ans+=jf[k]*m;
						m=0;
					}
				}
			}
		}
		printf("%.3f\n",ans);
	}
	return 0;
}