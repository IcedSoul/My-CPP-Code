#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=105;
char map[maxn][maxn];
int n,m;
int mark[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct T
{
	int a=0;
	int b=0;
};
T s[10005];
T ans[10005];
int mintime;
void dfs(int x,int y,int time){
	if(map[n-1][m-1]=='X'){
		if(time<mintime){
		for(int i=0;i<=time;i++){
			ans[i].a=s[i].a;
			ans[i].b=s[i].b;
		}
		mintime=time;
		}
	}
	for(int j=0;j<4;j++){
		if(x+mark[j][0]>=0 && y+mark[j][1]>=0 && x+mark[j][0]<n && x+mark[j][1]<m){
			if(map[x+mark[j][0]][y+mark[j][1]]=='.'){
				map[x+mark[j][0]][y+mark[j][1]]='X';
				s[time].a=x+mark[j][0];
				s[time].b=y+mark[j][1];
				dfs(x+mark[j][0],y+mark[j][1],time+1);
				map[x+mark[j][0]][y+mark[j][1]]='.';
			}
			else if(map[x+mark[j][0]][y+mark[j][1]]>='1' && map[x+mark[j][0]][y+mark[j][1]]<='9'){
				char tt=map[x+mark[j][0]][y+mark[j][1]];
				int temp=(int)map[x+mark[j][0]][y+mark[j][1]]-48;
				map[x+mark[j][0]][y+mark[j][1]]='X';
				for(int i=time;i<=time+temp;i++){
					s[i].a=x+mark[j][0];
					s[i].b=y+mark[j][1];
				}
				dfs(x-+mark[j][0],y+mark[j][1],time+temp+1);
				map[x+mark[j][0]][y+mark[j][1]]=tt;
				}
			}
		}
	return;
	}
int main(){
	ans[0].a=0;ans[0].b=0;
	while(cin>>n>>m){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>map[i][j];
		mintime=1000005;
		dfs(0,0,1);
		mintime--;
		if(mintime!=1000004){
			cout<<"It takes "<<mintime<<" seconds to reach the target position, let me show you the way."<<endl;
			for(int i=1;i<=mintime;i++){
				if(ans[i].a==ans[i-1].a && ans[i].b== ans[i-1].b){
					cout<<i<<"s:FIGHT AT "<<"("<<ans[i].a<<","<<ans[i].b<<")"<<endl;
				}
				else
					cout<<i<<"s:"<<"("<<ans[i-1].a<<","<<ans[i-1].b<<")->"<<"("<<ans[i].a<<","<<ans[i].b<<")"<<endl;
			}	
		}
		else
			cout<<"God please help our poor hero."<<endl;
		cout<<"FINISH"<<endl;
	}
	return 0;
}
