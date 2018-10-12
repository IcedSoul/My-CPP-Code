#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
int m,n,t;
int isLeap(int x){
	if(x%400!=0){
		if(x%100==0 || x%4!=0)
			return 0;
	}
	return 1;
}
int main(){
	cin>>t;
	while(t--){
		cin>>m>>n;
		int counts=1,i;
		while(!isLeap(m)){
			m++;
		}
		for(i=m;counts<=n;i+=4){
			if(isLeap(i)){
				counts++;
			}
		}
		cout<<i-4<<endl;
	}
	return 0;
}