#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
const int maxn=1000000005;
using namespace std;
int main(){
    int n,a,minnum=maxn;
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a%2==0)
            ans+=a;
        else{
            ans+=a;
            minnum=min(a,minnum);
        }
    }
    if(ans%2==0)
        cout<<ans;
     else
        cout<<ans-minnum;
    return 0;
}