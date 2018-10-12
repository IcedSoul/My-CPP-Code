#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int maxn=10;
int a[maxn];
int k;
int main(){
	while(cin>>a[8]>>a[7]>>a[6]>>a[5]>>a[4]>>a[3]>>a[2]>>a[1]>>a[0]){
		k=0;
		for(int i=8;i>=0;i--){
			if(a[i]!=0){
				if(i!=0){
					if(k==0){
						if(a[i]==1 && i==1)
							cout<<"x";
						else if(a[i]!=1 && a[i]!=-1 && i==1)
							cout<<a[i]<<"x";
						else if(a[i]==1 && a[i]!=-1  && i!=1)
							cout<<"x^"<<i;
						else if(a[i]==-1  && i==1)
							cout<<"-x";
						else if(a[i]==-1 && i!=1)
							cout<<"-x^"<<i;
						else
							cout<<a[i]<<"x^"<<i;
						k=1;
					}
					else{
						if(a[i]>0){
							if(a[i]==1 && i==1)
								cout<<" + x";
							else if(a[i]!=1 && i==1)
								cout<<" + "<<a[i]<<"x";
							else if(a[i]==1 && i!=1)
								cout<<" + "<<"x^"<<i;
							else
								cout<<" + "<<a[i]<<"x^"<<i;
						}
						else{
							if(i==1){
								if(a[i]!=-1)
									cout<<" - "<<abs(a[i])<<"x";
								else
									cout<<" - x";
							}
							else{
								if(a[i]!=-1)
									cout<<" - "<<abs(a[i])<<"x^"<<i;
								else
									cout<<" - x^"<<i;
							}
						}
					}

				}
				else{
					if(k==0){
						cout<<a[i];
						k=1;
					}
					else
						if(a[i]>0)
							cout<<" + "<<a[i];
						else
							cout<<" - "<<abs(a[i]);
				}
			}
			else{
				if(i==0){
					if(k==0)
						cout<<a[i];
				}
			}
		}
		cout<<endl;
		memset(a,0,sizeof(a));
	}
	return 0;
}