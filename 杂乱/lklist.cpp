#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next;
} lklist;
void createlklist(lklist *&lk){
	int a;
	cin>>a;
	if(a==-1){
		lk=NULL;
		return;
	}
	lk=(lklist*)malloc(sizeof(lklist));
	lk->data=a;
	createlklist(lk->next);
}
int main(){
	lklist *s;
	createlklist(s);
	lklist *b;
	for(b=s;b!=NULL;b=b->next){
		cout<<b<<"  "<<b->data<<endl;
	}
	return 0;
}