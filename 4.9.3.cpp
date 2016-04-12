#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=1005;
int t,n,b[maxn];
struct T
{
	int x,y;
};
T a[maxn];
int cmp(T s,T b){
	return s.x+s.y > b.x+b.y;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			a[i].x=n-i-1;
			scanf("%d",&a[i].y);
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
			b[i]=a[i].x+a[i].y-n+i+1;
		int k=0;
		for(int i=1;i<n;i++)
			if(b[i]>b[i-1]){
				k=1;
				break;
			}
		if(k==1)
			cout<<"Impossible"<<endl;
		else{
			for(int i=0;i<n-1;i++)
				cout<<b[i]<<" ";
			cout<<b[n-1]<<endl;
		}
	}
	return 0;
}