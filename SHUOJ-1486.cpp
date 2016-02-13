#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
using namespace std;
const int maxn=10005;
int n,a,b,temp1,temp2;
int x,i=1,sum=0;
char s=' ';
int maxNum=-30005,minNum=30005;
int maxIndex=0,minIndex=0;
int main(){
	scanf("%d",&x);
	getchar();
	int count=1;
	while(1){
		scanf("%d",&n);
		scanf("%c",&s);
		if(i==1) {
			a=n;temp1=n;
		}
		else if(i==2) {
			b=n;temp2=n;
		}
		else{
			sum=temp1+temp2+n;
			temp1=temp2;
			temp2=n;
			if(sum<minNum){
				minNum=sum;
				minIndex=i;
			}
			if(sum>maxNum){
				maxNum=sum;
				maxIndex=i; 
			}
		}
		
		if(s=='\n'){
			cout<<"Case "<<count++<<":"<<endl;
			if(i<3)
				cout<<"No maximal and minimal!"<<endl;
			else{
				sum=temp1+temp2+a;
			temp1=temp2;
			temp2=a;
			if(sum<minNum){
				minNum=sum;
				minIndex=i+1;
			}
			if(sum>maxNum){
				maxNum=sum;
				maxIndex=i+1; 
			}
			sum=temp1+temp2+b;
			temp1=temp2;
			temp2=b;
			if(sum<minNum){
				minNum=sum;
				minIndex=i+2;
			}
			if(sum>maxNum){
				maxNum=sum;
				maxIndex=i+2; 
			}
				cout<<"maximum = "<<maxNum<<", minimum = "<<minNum<<", MaxIndex = "<<maxIndex-2<<", MinIndex = "<<minIndex-2<<endl;
				maxNum=-30005;
				minNum=30005;
			}
			i=0;
			x--;
		}
		if(x==0) break;
		i++;
	}
	return 0;
}
