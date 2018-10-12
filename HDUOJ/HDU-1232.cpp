#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn=1005;
int tree[maxn];
int n,m,x,y,ans;
int find(int a){
	int t=a;
	while(tree[t]!=t)
		t=tree[t];
	return t;
}
void merge(int a,int b){
	int t,p;
	t=find(a);
	p=find(b);
	if(t!=p)
		tree[t]=p;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0) break;
		for(int i=0;i<=n;i++)
			tree[i]=i;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			merge(x,y);
		}
		ans=0;
		for(int i=1;i<=n;i++)
			if(tree[i]==i)
				ans++;
		printf("%d\n",ans-1);
	}
	return 0;
}