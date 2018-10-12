#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <math.h>
using namespace std;
const int maxn=1005;
int n,l;
string s;
typedef struct BinaryNode{
	char type;
	struct BinaryNode *lChild,*rChild;
}BinaryNode;

BinaryNode* r;

void creat(int len,string  st,BinaryNode* &r){
	r=new BinaryNode;
	if(len<1) {
		r=NULL;
		return;
	}
	string s1,s2;
	if(st.find('1',0)!=-1 && st.find('0',0)!=-1 )
		r->type='F';
	else if(st.find('1',0)==-1 && st.find('0',0)!=-1)
		r->type='B';
	else if(st.find('1',0)!=-1 && st.find('0',0)==-1 )
		r->type='I';
	s1=st.substr(0,len/2);
	s2=st.substr(len/2,len/2);
	// cout<<s1<< " "<<s2<<" "<<r->type<<endl;
	creat(len/2,s1,r->lChild);
	creat(len/2,s2,r->rChild);
}

void order(BinaryNode *r){
	if(r!=NULL){
		order(r->lChild);
		order(r->rChild);
		printf("%c",r->type);	
	}
	return;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		cin>>s;
		l=s.length();
		creat(l,s,r);
		// cout<<r->type<<endl;
		order(r);
		printf("\n");
	}
	return 0;
}