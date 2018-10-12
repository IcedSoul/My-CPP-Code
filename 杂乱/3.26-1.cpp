#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn=5005;
struct T
{
	char sex;
	int startday;
	int endday;
};
T a[maxn];
int n;
int ans,f[370],m[370],mins;
int main(){
	while(cin>>n){
		ans=0;
		memset(f,0,sizeof(f));
		memset(m,0,sizeof(m));
		for(int i=0;i<n;i++){
			cin>>a[i].sex>>a[i].startday>>a[i].endday;
			for(int j=a[i].startday;j<=a[i].endday;j++){
				if(a[i].sex=='F')
						f[j]++;
					else
						m[j]++;
				}
		}
		for(int i=1;i<=366;i++){
			mins=min(f[i],m[i]);
			if(mins>ans)
				ans=mins;
		}
		cout<<ans*2<<endl;
	}
	return 0;
}