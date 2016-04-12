#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=105;
long long a[maxn][maxn],sum=0;
int n;
int main(){
    cin>>n;
    int k=(n+1)/2,j=(n+1)/2;
    a[k][j]=1;
    for(int i=1;i<(n+1)/2;i++)
    {   
        a[k-i][j-i]=4*i*i+1;
        for(int s=1;s<2*i+1;s++)
            a[k-i+s][j-i]=a[k-i+s-1][j-i]+1;
        for(int s=1;s<2*i+1;s++)
            a[k+i][j-i+s]=a[k+i][j-i+s-1]+1;
        for(int s=1;s<2*i+1;s++)
            a[k-i][j-i+s]=a[k-i][j-i+s-1]-1;
        for(int s=1;s<2*i;s++)
             a[k-i+s][j+i]=a[k-i+s-1][j+i]-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
                cout<<a[i][j]<<" ";
                if(i==j || i==n+1-j) sum+=a[i][j];
            }
            if(i==n || i==1) sum+=a[i][n];
            cout<<a[i][n]<<endl;
    }
    cout<<sum;
    return 0;
}