#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <map>
#include <queue>
#include <cstdio>
using namespace std;
const int maxn=105;
int n,m,temp;
struct T
{
	int x;
	int y;
};
T a,b,ans;
queue<T> Q;
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a.y);
			a.x=i;
			Q.push(a);
		}
		while(!Q.empty()){
			temp=m%n;
			if(temp==0) temp=n;
			for(int i=1;i<temp;i++){
				b=Q.front();
				Q.pop();
				Q.push(b);
			}
			ans=Q.front();
			Q.pop();
			// cout<<ans.x<<" "<<ans.y<<endl;
			n--;m=ans.y;
		}
		printf("%d\n",ans.x);
	}
	return 0;
}