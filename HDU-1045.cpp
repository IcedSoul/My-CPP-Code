#include<iostream>
#include<algorithm>
#define maxn 1005
using namespace std;
int n;
char s[5][5];
int b[5][5],bb[5][5],c[5][5];
int dfs(int i,int j,int mark);
int dfs2(int i,int j,int mark);
int dfs2(int i,int j,int mark){
	int ans=0;
     for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int temp=dfs(i,j,mark);
			if(temp>ans)
			ans=temp;
			}
		}
	return ans;
}
int dfs(int i,int m,int mark){
	int ans=0;
	if(b[i][m]==2)
		return ans;
	else if(mark==0){
		if(b[i][m]==0){
			ans++;
			for(int p=m;p<n;p++){
				if(b[i][p]!=2){
				b[i][p]=1;
				}
				else
				break;
		    }
			for(int p=m;p>=0;p--){
				if(b[i][p]!=2){
				b[i][p]=1;
				}
				else
				break;
			}
			for(int p=i;p<n;p++){
				if(b[p][m]!=2){
				b[p][m]=1;
				}
				else
				break;
			}
			for(int p=i;p>=0;p--){
				if(b[p][m]!=2){
					b[p][m]=1;
			    }
				else
				break;
			}
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(b[j][j]==0)
						for(int d=0;d<n;d++)
					for(int z=0;z<n;z++)
				c[d][z]=b[d][z];
					 ans+=dfs2(j,k,1);
				}
			}
			return ans;
		}
		return ans;
	}
	else{
		if(c[i][m]==0){
			ans++;
			for(int p=m;p<n;p++){
				if(c[i][p]!=2){
				c[i][p]=1;
				}
				else
				break;
		    }
			for(int p=m;p>=0;p--){
				if(c[i][p]!=2){
				c[i][p]=1;
				}
				else
				break;
			}
			for(int p=i;p<n;p++){
				if(c[p][m]!=2){
				c[p][m]=1;
				}
				else
				break;
			}
			for(int p=i;p>=0;p--){
				if(c[p][m]!=2){
					c[p][m]=1;
			    }
				else
				break;
			}
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){

					if(c[j][j]==0)
					 ans+=dfs2(j,k,1);
				}
			}
			return ans;
		}
		return ans;
	}
}
int main(){
	while(cin>>n && n){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				{cin>>s[i][j];
				if(s[i][j]=='.')
					bb[i][j]=0;
				else
					bb[i][j]=2;}
	int ans=0;
	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
		 		for(int d=0;d<n;d++)
					for(int z=0;z<n;z++)
				b[d][z]=bb[d][z];
				int temp=dfs(i,j,0);
				if(temp>ans)
					ans=temp;
			}		}
		cout<<ans<<endl;
	}
	return 0;
}