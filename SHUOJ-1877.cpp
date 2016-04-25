#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <map>
#include <queue>
#include <cstdio>
using namespace std;
const int maxn=100005;
int tree[maxn];
int n,m,t,a,b;
int find(int c){
	int p=c;
	while(tree[p]!=p){
		p=tree[p];
	}
	int q=c;
	while(tree[q]!=p){
		c=tree[q];
		tree[q]=p;
		q=c;
	}
	return p;
}
void merge(int x,int y){
	int e=find(x);
	int f=find(y);
	if(e!=f){
		tree[e]=f;
	}
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++)
			tree[i]=i;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&t,&a,&b);
			if(t==1)
				merge(a,b);
			else{
				if(find(a)==find(b))
					printf("Yes\n");
				else
					printf("No\n");
			}
		}
	}
	return 0;
}
