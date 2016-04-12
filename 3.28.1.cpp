#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int a,b,c,d,e,f,dd,sum,x,y;
int main(){
	while(cin>>a>>b>>c>>d>>e>>f){
		if(a==0 && b==0 && c==0 && d==0 && e==0 && f==0) break;
		dd=a+c+e-b-d-f;
		sum=a+b;
		cout<<"Anna's won-loss record is "<<(sum-dd)/2<<"-"<<(sum+dd)/2<<"."<<endl;
	}
	return 0;
}