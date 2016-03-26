#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
char map[105][105];
int col[105],row[105];
long long ans;
long long c(int m){
	if(m<2) return 0;
	if(m==2) return 1;
	if(m>2) return m*(m-1)/2;
	return 0;
}
int main(){
	while(cin>>n){
		ans=0;
		memset(col,0,sizeof(col));
		memset(row,0,sizeof(row));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>map[i][j];
				if(map[i][j]=='C'){
					row[i]++;
					col[j]++;
				}
			}
		}
		for(int i=0;i<n;i++){
			ans+=c(col[i])+c(row[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
