#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=10005;
int n[maxn],x;
int a[maxn];
int functions(int n){
    for(int i = 1; i <= n; i++){
        a[i] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j+= i){
            a[j] = a[j] ^ 1;
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; i++ ){
        ret = ret + a[i];
    }
    return ret;
}
int main(){
    for(int i=1;i<=200;i++){
        n[i]=functions(i);
        cout<<i<<"  "<<n[i]<<" "<<i-functions(i)<<endl;
    }
    while(cin>>x)
        cout<<n[x]<<endl;
    return 0;
}