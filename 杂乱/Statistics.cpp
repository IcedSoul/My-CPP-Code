#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
string a[100005];
int main(){
	while(cin>>n){
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		int k=unique(a,a+n)-a;		
		cout<<k<<endl;
		for(int i=0;i<k;i++)
			cout<<a[i]<<endl;
	}
	
	return 0;
}