#include<iostream>
using namespace std;
#define maxn 1005
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,ans=10;
		cin>>n;
		int a,b,mark[205];
		for (int i=0;i<204;++i)
		{
			mark[i]=0;
		}
		for (int i=0;i<n;++i)
		{
			cin>>a>>b;
			a=(a-1)/2;b=(b-1)/2;
			if(b<a){
				int temp=a;
				a=b;
				b=temp;
			}
			for (int j=a;j<=b;++j)
			{
				mark[j]+=10;
			}
		}
		for (int i = 0; i < 200; ++i)
		{
			if(mark[i]>ans) ans=mark[i];
		}
		cout<<ans<<endl;

	}
	return 0;
}