#include<iostream>
#include<cstdio>
using namespace std;
int a[300005],num[300005];
int main(){
int n,count=0;
num[0]=0;
scanf("%d",&n);
for(int i=1;i<=n;i++){
      scanf("%d",&a[i]);
     for(int j=num[count]+1;j<i;j++){
      if(a[i]==a[j]){
       	count++;
        num[count]=i;}}}
     if(count==0){	
       printf("-1\n");}
     else{
   		printf("%d\n",count);
        for(int i=0;i<count-1;i++)
        printf("%d %d\n",num[i]+1,num[i+1]);
        printf("%d %d\n",num[count-1]+1,n);}
return 0;
}