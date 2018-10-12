#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
using namespace std;
const int maxn=105;
struct T{
	string name;
	int grade1;
	int grade2;
	char st1;
	char st2;
	int num;
	int money;
};
int n;
long long sum=0;
T a,b;
int main(){
	cin>>n;
	b.money=0;
	for(int i=0;i<n;i++){
		a.money=0;
		cin>>a.name>>a.grade1>>a.grade2>>a.st1>>a.st2>>a.num;
		if(a.grade1>80 && a.num>=1) a.money+=8000;
		if(a.grade1>85 && a.grade2>80) a.money+=4000;
		if(a.grade1>90) a.money+=2000;
		if(a.grade1>85 && a.st2=='Y') a.money+=1000;
		if(a.grade2>80 && a.st1=='Y') a.money+=850;
		if(a.money>b.money){
			b.money=a.money;
			b.name=a.name;
		}
		sum+=a.money;	
	}
	cout<<b.name<<endl<<b.money<<endl<<sum;

	return 0;
}
