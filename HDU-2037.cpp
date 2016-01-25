#include<iostream>
#include<algorithm>
#define maxn 105
using namespace std;
struct Time
{
	int begin=0;
	int end=0;
};
int cmp(Time a,Time b){
	return a.end<b.end;
}
int main(){
	int n;
	while(cin>>n && n){
		Time time[maxn];
		int ans=0,temp=-1;
		for(int i=0;i<n;i++){
		cin>>time[i].begin>>time[i].end;
		}
		sort(time,time+n,cmp);
		for(int i=0;i<n;i++){
			if(time[i].begin>=temp){
				ans++;
				temp=time[i].end;
			}
		}
		cout<<ans<<endl;
	}
}