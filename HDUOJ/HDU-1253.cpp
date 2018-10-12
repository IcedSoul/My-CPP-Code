#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<math.h> 
using namespace std;
const int maxn=1005;
int map[52][52][52];
int timemap[52][52][52];
int k,a,b,c,t;
int dir[6][3]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

struct T{
	int aa,bb,cc;
};

T sa,sb;
void bfs(){
	queue<T> Q;
	sa.aa=0;
	sa.bb=0;
	sa.cc=0;
	Q.push(sa);
	timemap[0][0][0]=0;
	while(!Q.empty()){
		sa=Q.front();
		Q.pop();
		for(int i=0;i<6;i++){
		int xx=sa.aa+dir[i][0],yy=sa.bb+dir[i][1],zz=sa.cc+dir[i][2];
		if(xx>=0 && xx<a && yy>=0 && yy<b && zz>=0 && zz<c){
			if(map[xx][yy][zz]==0){
				sb.aa=xx;
				sb.bb=yy;
				sb.cc=zz;
				if(timemap[sa.aa][sa.bb][sa.cc]+1<timemap[xx][yy][zz]){
					timemap[xx][yy][zz]=timemap[sa.aa][sa.bb][sa.cc]+1;
					Q.push(sb);
				}
				
			} 
			}
		}
		
	}
}

int main(){
	scanf("%d",&k);
	while(k--){
		scanf("%d%d%d%d",&a,&b,&c,&t);
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				for(int k=0;k<c;k++){
					scanf("%d",&map[i][j][k]);
					timemap[i][j][k]=maxn;
				}
		bfs();		
		if(timemap[a-1][b-1][c-1]<=t)
			printf("%d\n",timemap[a-1][b-1][c-1]);
		else
			printf("-1\n");
	}
	return 0;
}