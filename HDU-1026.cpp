#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn=105;
char map[maxn][maxn];
int n,m;
int mark[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int mintime,temp;
struct T
{
	int a;
	int b;
	int time;
};
struct P
{
	int timemap;
	int prex;
	int prey;
};
P p[maxn][maxn];
T ans[10005];
T s,k;
void bfs(){
	queue<T> Q;
	s.a=0;
	s.b=0;
	s.time=0;
	Q.push(s);
	p[0][0].timemap=0;
	while(!Q.empty()){
		s=Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int x=s.a+mark[i][0];
			int y=s.b+mark[i][1];
			if(x>=0 && x<n &&y>=0 && y<m){
				if(map[x][y]=='.'){
					k.a=x;
					k.b=y;
					k.time=s.time+1;
					if(k.time < p[x][y].timemap){
					p[x][y].prex=s.a;
					p[x][y].prey=s.b;
					p[x][y].timemap=k.time;
					Q.push(k);
				}
				}
				else if(map[x][y]>='0' && map[x][y]<='9'){
					temp=(int)map[x][y]-48;
					k.a=x;
					k.b=y;
					k.time=s.time+temp+1;
					if(k.time<p[x][y].timemap){
					p[x][y].prex=s.a;
					p[x][y].prey=s.b;
					p[x][y].timemap=k.time;
					Q.push(k);
				}
				}
			}
		}
	}
}
void print(int x,int y,int count){
	int ttt=p[x][y].timemap-p[p[x][y].prex][p[x][y].prey].timemap;
	for(int i=0;i<ttt;i++){
		ans[count-i].a=x;
		ans[count-i].b=y;
	}
	if(x==0 && y==0 ) return;
	print(p[x][y].prex,p[x][y].prey,count-ttt);
}

int main(){
	while(cin>>n>>m){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				cin>>map[i][j];
				p[i][j].timemap=1000005;
			}
		bfs();
		mintime=p[n-1][m-1].timemap;
		if(mintime!=1000005){
			print(n-1,m-1,mintime);
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
