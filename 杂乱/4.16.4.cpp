#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=5005;
int t,n;
long long p,g,a,ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=n/2;
		p=ans;
		g=ans;
		while(p>=2 || g>=4){
			if(p>=2){
				a=p/2;
				ans+=a;
				p=p%2+a;
				g+=a;

			}
			if(g>=4){
				a=g/4;
				ans+=a;
				p+=a;
				g=g%4+a;
			}
		}
		printf("%ld\n",ans);
	}
    return 0;
}