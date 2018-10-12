#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=105;
string a,b;
int k;
int main(){
	cin>>a>>b;
	int k=a.find(b,0);
	cout<<k+1;
	return 0;
}