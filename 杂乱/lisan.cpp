#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int a[15],n=0;
int main(){
	for(int i=0;i<13;i++)
		a[i]=-1;
	while(1){
		for(int i=0;i<13;i++){
			if(i!=n-1)
				a[i]=-a[i];
			cout<<i+1<<"   "<<a[i]<<endl;
		}
		cin>>n;
	}
	return 0;
}