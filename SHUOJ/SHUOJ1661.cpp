#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdio>
using namespace std;
int n;
int counts=0;
int main(){
	while(scanf("%d",&n)!=EOF){
		counts++;
		printf("Case %d: n=%d\n",counts,n);
		if(n<=0 || n>26){
			printf("No image!\n");
			printf("\n");
			continue;
		}
		int num1=n-1,num2=1;
		for(int i=0;i<n;i++){	
			for(int j=0;j<num1;j++)
				printf(" ");
			for(int j=0;j<num2;j++)
				printf("%c",(char)((int)'A'+i));
			printf("\n");
			num1--;num2+=2;
		}
		num1++;num2-=2;
		for(int i=n-2;i>=0;i--){
			num1++;num2-=2;
			for(int j=0;j<num1;j++)
				printf(" ");
			for(int j=0;j<num2;j++)
				printf("%c",(char)((int)'A'+i));
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}