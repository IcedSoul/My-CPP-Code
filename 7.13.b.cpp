#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define maxn 10005
using namespace std;
int main(){
	string a;
	while(getline(cin,a)){
		for (int i = 0; i < a.length(); ++i)
		{
			cout<<(char)((int)a.at(i)-7);
		}
		cout<<endl;
	}
	return 0;
}