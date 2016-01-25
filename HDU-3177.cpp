#include<iostream>
#include<algorithm>
#define maxn 1005
using namespace std;
struct S
{
	int actually=0;
	int temp=0;
	int d;
};
int cmp(S a,S b){
	return a.d>b.d;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		S space[maxn];
		int v,n,mark=0;
		cin>>v>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>space[i].actually>>space[i].temp;
			space[i].d=space[i].temp-space[i].actually;
		}
		sort(space,space+n,cmp);
		for (int i = 0; i < n; ++i)
		{
			if(v>=space[i].temp){
				v-=space[i].actually;
			}
			else{
				mark=1;break;
			}		
		}
		if(mark==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}