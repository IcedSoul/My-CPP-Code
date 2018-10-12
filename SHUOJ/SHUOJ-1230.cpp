#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
using namespace std;
char s;
long long ans[30];
int main(){
	memset(ans,0,sizeof(ans));
	while(scanf("%c",&s)){
		if(s=='#') break;
		if(s>='a' && s<='z'){
			ans[s-'a']++;
		}
	}
	for(int i=0;i<26;i++){
		cout<<(char)('a'+i)<<" "<<ans[i]<<endl;
	}
	return 0;
}
