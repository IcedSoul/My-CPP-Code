#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
#include<stack>
using namespace std;
const int maxn=10005;
int main(){
	int n;
	char in[maxn],out[maxn];
	int ans[maxn];
	while(cin>>n){
		for(int i=0;i<n;i++)
			cin>>in[i];
		for(int i=0;i<n;i++)
			cin>>out[i];
		stack<char> S;
		int count=0,j=0;
		for(int i=0;i<n;i++){
			S.push(in[i]);
			ans[count++]=0;
			while(S.top()==out[j] && j<=i){
				S.pop();
				ans[count++]=1;
				j++;
				if(S.empty()) break;
			}
		}
		if(S.empty()){
			cout<<"Yes."<<endl;
			for(int i=0;i<2*n;i++)
				if(ans[i]==0)
					cout<<"in"<<endl;
				else
					cout<<"out"<<endl;
		}
		else
			cout<<"No."<<endl;
		cout<<"FINISH"<<endl;
	}
	return 0;
} 
