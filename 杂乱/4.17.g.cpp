#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <queue>
using namespace std;
const int maxn=505;
int t,n,m,num,temp;
char s[maxn],e[maxn];
int list[maxn][maxn],match[maxn],book[maxn],sum,nv,ans1[maxn],ans2[maxn],counts;
int dfs(int u){
	for(int i=1;i<=n;i++){
		if(book[i]==0 && list[u][i]==0){
			book[i]=1;
			if(match[i]==0 || dfs(match[i])){
				match[i]=u;
				match[u]=i;
				return 1;
			}
		}
	}
	return 0;
}
void hungray(){
	for(int i=1;i<=n;i++){
		if(match[i]==0){
			memset(book,0,sizeof(book));
			if(dfs(i)){ 
				sum++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(match[i]!=0 &&  e[match[i]-1]=='1'){
			for(int j=1;j<=n;j++){
				if(list[i][j]==0 && match[j]==0 && e[j-1]=='0'){
					match[match[i]]=0;
					match[i]=j;
					match[j]=i;
				}
			}
		}
	}
	memset(book,0,sizeof(book));
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			book[i]=1;
			book[match[i]]=1;
			ans1[counts]=i;
			ans2[counts++]=match[i];
			if(e[i-1]=='0') nv++;
			if(e[match[i]-1]=='0') nv++;
		}
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		memset(list,0,sizeof(list));
		memset(match,0,sizeof(match));
		memset(book,0,sizeof(book));
		sum=0;nv=0;counts=0;
		scanf("%d",&n);
		cin>>s>>e;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if((s[i]=='0'&&s[j]=='1')|| (s[j]=='0'&&s[i]=='1') ){
					list[i+1][j+1]=0;
					list[j+1][i+1]=0;
				}
				else{
					list[i+1][j+1]=1;
					list[j+1][i+1]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&m);
			for(int j=1;j<=m;j++){
				scanf("%d",&temp);
				list[i][temp]=1;
				list[temp][i]=1;
			}
		}
		hungray();
		printf("%d %d\n",sum,nv);
		for(int i=0;i<counts;i++)
			printf("%d %d\n",ans1[i],ans2[i]);
	}
	return 0;
}