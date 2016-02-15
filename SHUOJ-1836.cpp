#include<iostream>//超时
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdio>
using namespace std;
const int maxn= 10000005;
int a[maxn],b[maxn];
int n,num1,num2,num5;
int main(){
    while(cin>>n>>num1>>num2>>num5){
        if(num1==0 && num2==0 && num5==0) break;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<=num1;i++) a[i]=1;
            for(int j=0;j<=num1;j++)
                for(int k=2;k<=num2*2;k+=4){
                    b[j+k]+=a[j];
                }
            for(int j=0;j<=num1+num2*2;j++){
                a[j]=b[j];
                b[j]=0;
            }
            for(int j=0;j<=num1+num2*2;j++)
                for(int k=0;k<=num5*5;k+=10){
                    b[j+k]+=a[j];
                }
            for(int j=0;j<=num1+num2*2+num5*5;j++){
                a[j]=b[j];
                b[j]=0;
            }
        if(n<=num1+num2*2+num5*5)
            cout<<a[n]<<endl;
        else
            cout<<"0"<<endl;
         
    }
    return 0;
}