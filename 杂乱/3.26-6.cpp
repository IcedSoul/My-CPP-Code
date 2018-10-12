#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn=1005;
int n,p,y,ans,mark;
int v1[maxn],v2[maxn];
void dfs(int k){
	for(int j=mark+1;j<n;j++){
		
			if(v1[j]==v2[k]){
				p++;
				int temp=mark;
				mark=j;
				dfs(k+1);
				mark=temp;
				p--;
			}
			if(v1[j]>v2[k]){
				y++;
				mark=j;
				dfs(k+1);		
			}
			cout<<"k = "<<k<<" "<<v1[j]<<" "<<v2[k]<<" p= "<<p<<" y = "<<y<<endl;
	}
	if(mark+1==n){
		if(2*y+p-n>ans)
			ans=2*y+p-n;
	}

}
int main(){
	while(cin>>n){
		ans=-n;p=0;y=0;
		for(int i=0;i<n;i++)
			cin>>v1[i];
		for(int i=0;i<n;i++)
			cin>>v2[i];
		sort(v1,v1+n);
		sort(v2,v2+n);
		mark=0;
		dfs(0);
		cout<<ans*100<<endl;

	}
	return 0;
}