#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=10005;
struct T
{
	char a;
	char b;
};
T s[maxn];
int num=0;
bool ans=0;
char str[maxn];
int vis[maxn];

void dfs(char x){
	if(ans==1) return;
	for(int i=0;i<num;i++){
		if(vis[i]==0 && x==s[i].a){
			vis[i]=1;
			if(s[i].b=='m') ans=1;
			dfs(s[i].b);
			vis[i]=0;
		}
	}
	return;
}

int main(){
	while(cin>>str && str[0]!=0){
		if(str[0]=='0' && strlen(str)==1){
			memset(vis,0,sizeof(vis));
			ans=0;
			dfs('b');
			num=0;
			if(ans==1)
				cout<<"Yes."<<endl;
			else
				cout<<"No."<<endl;
		}
		else{
		int k=strlen(str);
		s[num].a=str[0];
		s[num].b=str[k-1];
		num++;
		}
	}
	return 0;
}