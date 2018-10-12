#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *lchild,*rchild;
} bitree;
void createbitree(bitree *&bt){
	int a;
	cin>>a;
	if(a==-1){
		bt=NULL;
		return;
	}
	bt=(bitree*)malloc(sizeof(bitree));
	bt->data=a;
	createbitree(bt->lchild);
	createbitree(bt->rchild);
}
int main(){
	bitree *s;
	createbitree(s);
	bitree *b;
	for(b=s;b!=NULL;b=b->next){
		cout<<b<<"  "<<b->data<<endl;
	}
	return 0;
}