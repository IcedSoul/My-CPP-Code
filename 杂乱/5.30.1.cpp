#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
int n,u,d;
int main(){
	while(cin>>n>>u>>d &&n){
		int ans=-1;
		n-=d;
		while(n>0){
			ans+=1;
			n+=d;
			n-=u;
			ans+=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}