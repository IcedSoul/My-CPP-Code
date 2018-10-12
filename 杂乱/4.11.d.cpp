#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <queue>
using namespace std;
const int maxn=1005;
int n,a[maxn][maxn],num[maxn],v[maxn],counts,ans;
double x[maxn],y[maxn];
int s;
int distance(double x1,double y1,double x2,double y2){
	if(sqrt(pow((x1-x2),2)+pow((y1-y2),2))<=20){
		return 1;
	}
	return 0;
}
int hh(int bb){
	// cout<<"---"<<endl;
	for(int i=1;i<100;i++){
		int mk=0;
		for(int j=0;j<num[bb];j++){
			if(a[bb][j]==i){
				mk=1;
				break;
			} 
		}
		if(mk==0){
			if(i>ans)
				ans=i;
			return i;
		}
	}
	return 0;
}
void bfs(int sos){
	queue<int> Q;
	Q.push(sos);
	while(!Q.empty()){
		s=Q.front();
		// cout<<s<<endl;
		Q.pop();
		for(int i=0;i<num[s];i++){
			if(v[a[s][i]]==0){
				v[a[s][i]]=hh(a[s][i]);
				Q.push(a[s][i]);
			}
		}
	}
}
int main(){
	counts=0;
	while(cin>>n && n){
		ans=0;
		memset(a,0,sizeof(a));
		memset(num,0,sizeof(num));
		memset(v,0,sizeof(v));
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i];
		}
		for(int i=0;i<n;i++){
			int c=0;
			for(int j=0;j<n;j++){
				if(i!=j){
					if(distance(x[i],y[i],x[j],y[j]))
						a[i][c++]=j;
				}
			}
			num[i]=c;
		}
		for(int i=0;i<n;i++){
			memset(v,0,sizeof(v));
			v[i]=1;
			bfs(i);
		}
		// for(int i=0;i<=n;i++){
		// 	for(int j=0;j<num[i];j++)
		// 		cout<<a[i][j]<<" ";
		// 	cout<<endl;
		// }
		cout<<"The towers in case "<< ++counts<<" can be covered in "<<ans<<" frequencies."<<endl;
	}
	return 0;
}