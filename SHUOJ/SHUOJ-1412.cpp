#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=10000005;
double n,m,r;
int main(){
	cin>>n>>m>>r;
	if(n<=m) printf("%.3f\n",r);
	else
		printf("%.3f\n",sqrt(r*r+(m-n)*(m-n)));
	return 0;
}