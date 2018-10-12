#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 100005;
int tree[maxn];
int mark[maxn];
int x,y,counts;
bool ans;
int find(int a){
	int t = a;
	while(tree[t]!=t)
		t = tree[t];
	return t;
}
void merge(int a,int b){
	int t,p;
	t = find(a);
	p = find(b);
	if(t != p){
		tree[t] = p;
	}
	else
		ans = false;
}
int main(){
	while(1){
		for(int i = 1;i <= 100000;i++)
			tree[i] = i;
		memset(mark,0,sizeof(mark));
		ans = true;
		counts = 0;
		while(scanf("%d%d",&x,&y)!=EOF){
			if(x == 0 && y == 0 ) break;
			if(x == -1 && y == -1 ) break;
			merge(x,y);
			mark[x] = 1;
			mark[y] = 1;
		}
		if(x==-1 && y==-1) break;
		for(int i=1;i<=100000;i++)
			if(mark[i]==1)
				if(tree[i]==i)
					counts++;
		if(counts>1)
			ans = false;
		if(ans == true)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}