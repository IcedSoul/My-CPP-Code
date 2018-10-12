#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <string.h>
using namespace std;
const int maxn = 1005;
long long a,b,l;
long long counts=0,ans;
int main(){
	while(cin>>a>>l){
		b=a;
		ans=1;
		if(a<0 && l<0) break;
		while(a!=1){
			if(a%2==0){
				a=a/2;
				ans++;
			}
			else{
				a=3*a+1;
				if(a>l) break;
				ans++;
			}
			
		}
		cout<<"Case "<< (++counts)<<": A = "<<b<<", limit = "<<l<<", number of terms = "<<ans<<endl;
	}
	return 0;
}