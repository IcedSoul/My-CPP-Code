#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
template <class ElemType>
struct BinTreeNode
{
	ElemType data;
	BinTreeNode<ElemType> *leftChild;
	BinTreeNode<ElemType> *rightChild;
	BinTreeNode(){
		leftChild=rightChild=NULL;
	}
	BinTreeNode(const ElemType &d,BinTreeNode<ElemType> *lChild,BinTreeNode<ElemType> *rChild){
		data=d;
		leftChild=lChild;
		rightChild=rChild;
	}
};

template <class ElemType>
class BinaryTree
{
protected:
	BinTreeNode<ElemType> *root;

	BinTreeNode<ElemType> *CopyTree(BinTreeNode<ElemType> *t);
	void Destroy(BinTreeNode<ElemType> * &r);                                       //删除以r为根的二叉树
	void PreOrder(BinTreeNode<ElemType> *r ,void (*Visit)(const ElemType &)) const; //前序遍历以r为根的二叉树
	void InOrder(BinTreeNode<ElemType> *r ,void (*Visit)(const ElemType &)) const;  //中序遍历以r为根的二叉树
	void PostOrder(BinTreeNode<ElemType> *r ,void (*Visit)(const ElemType &)) const;//后序遍历以r为根的二叉树
	int Height(const BinTreeNode<ElemType> *r) const;                               //求以r为根的二叉树的高度
	int NodeCount(const BinTreeNode<ElemType> *r) const;                            //求以r为根的二叉树的结点个数
	BinTreeNode<ElemType> *Parent(BinTreeNode<ElemType> *r,const BinTreeNode<ElemType> *p) const;//在以r为根的二叉树中寻找结点p的双亲节点

public:
	BinaryTree();
	BinaryTree(const ElemType e);
	virtual ~BinaryTree();
	BinaryTree<ElemType> *GetRoot() const;
	bool IsEmpty() const;
	void GetElem(BinaryTree<ElemType> *p,ElemType &e) const;
	void SetElem(BinaryTree<ElemType> *p,const ElemType &e);
	void InOrder(void (*Visit)(const ElemType &)) const;             //中序遍历
	void PreOrder(void (*Visit)(const ElemType &)) const;            //先序遍历
	void PostOrder(void (*Visit)(const ElemType &)) const;           //后序遍历
	void LevelOrder(void (*Visit)(const ElemType &)) const;          //层次遍历
	int NodeCount() const;                                           //求二叉树节点个数
	BinTreeNode<ElemType> *LeftChild(BinTreeNode<ElemType> *p) const;//求结点p的左孩子
	BinTreeNode<ElemType> *RightChild(<BinTreeNode<ElemType> *p) const;//求结点p的右孩子
	BinTreeNode<ElemType> *LeftSibling(BinTreeNode<ElemType> *p) const;//求结点p的左兄弟
	BinTreeNode<ElemType> *RightSibling(<BinTreeNode<ElemType> *p) const;//求结点p的右兄弟
	BinTreeNode<ElemType> *Parent(BinTreeNode<ElemType> *p) const;      //求结点p的双亲节点
	void InsertLeftChild(BinTreeNode<ElemType> *p,const ElemType &e);  //在结点p插入一个左孩子	
	void InsertRightChild(BinTreeNode<ElemType> *p,const ElemType &e);  //在结点p插入一个右孩子	
	void DeleteLeftChild(BinTreeNode<ElemType> *p);                     //删除结点p的左子树
	void DeleteRightChild(BinTreeNode<ElemType> *p);                    //删除结点p的右子树
	int Height() const;                                                 //求二叉树的高度
	BinaryTree(const BinaryTree<ElemType> &t);                          //复制构造函数
	BinaryTree(BinaryTree<ElemType> *r);                                //建立以r为根的二叉树
	BinaryTree<ElemType> &operator=(const BinaryTree<ElemType> &t);
};
//删除以r为根结点的二叉树
template <class ElemType>                                                
void BinaryTree<ElemType>::Destroy(BinaryTree<ElemType> *&r){
	if(r!=NULL){
		Destroy(r->leftChild);
		Destroy(r->rightChild);
		delete r;
		r=NULL;
	}
}
//先序遍历以r为根结点的二叉树
template <class ElemType>
void BinaryTree<ElemType>::PreOrder<BinTreeNode<ElemType> *r,void (*Visit)(const ElemType &){
	if(r!=NULL){
		(*Visit)(r->data);
		PreOrder(r->leftChild,Visit);
		PreOrder(r->rightChild,Visit);
	}
}
//中序遍历以r为根结点的二叉树
template <class ElemType>
void BinaryTree<ElemType>::InOrder<BinTreeNode<ElemType> *r,void (*Visit)(const ElemType &){
	if(r!=NULL){
		InOrder(r->leftChild,Visit);
		(*Visit)(r->data);
		IneOrder(r->rightChild,Visit);
	}
}
//后序遍历以r为根结点的二叉树
template <class ElemType>
void BinaryTree<ElemType>::PostOrder<BinTreeNode<ElemType> *r,void (*Visit)(const ElemType &){
	if(r!=NULL){
		PostOrder(r->leftChild,Visit);
		PostOrder(r->rightChild,Visit);
		(*Visit)(r->data);
	}
}
//求以r为根结点的二叉树中结点p的双亲
template <class ElemType>
BinTreeNode<ElemType> * BinaryTree<ElemType>:: Parent(BinTreeNode<ElemType> *r,const BinTreeNode<ElemType> *p){
	if(r==NULL)
		return NULL;
	else if(r->leftChild == p || r->rightChild == p)
		return r;
	else{
		BinTreeNode<ElemType> *temp;
		temp=Parent(r->leftChild,p);
		if(temp!=NULL) return temp;
		temp=Parent(r->rightChild,p);
		if(temp!=NULL) return temp;
		return NULL;
	}
}
//求以r为根结点的二叉树高度
template <class ElemType>
int BinaryTree<ElemType>::Height(BinTreeNode<ElemType> *r){
	int count=0;
	if(r==NULL) return 0;
	else{
		count=max(Height(r->leftChild),Height(r->rightChild))+1;
		return count;
	}
}
//求以r为根结点的二叉树结点个数
template <class ElemType>
int BinaryTree<ElemType>::NodeCount(BinTreeNode<ElemType> *r){
	int count=0;
	if(r==NULL) return 0;
	else{
		count=NodeCount(r->leftChild)+NodeCount(r->rightChild)+1;
	}
}
//构造函数
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(){
	root=NULL;
}
//构造以e为根的二叉树
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &e){
	root->data=e;
	root->leftChild=NULL;
	root->rightChild=NULL;
}
//析构函数
template <class ElemType<
BinaryTree<ElemType>::~BinaryTree(){
	Destroy(root);
}
//判断二叉树是否为空
template <class ElemType>
bool BinaryTree<ElemType>::IsEmpty(){
	if(root==NULL) return true;
	else return false;
}
//取p所指结点的元素值
template <class ElemType>
void BinaryTree<ElemType>::GetElem(BinTreeNode<ElemType> *p,ElemType &e) const{
	if(p!=NULL)
		e=p->data;
	else
		cout<<"没有元素";
}
//将元素值赋给结点p所指
template <class ElemType>
void BinaryTree<ElemType>::SetElem(BinTreeNode<ElemType> *p,const ElemType &e){
	if(p==NULL){
		BinTreeNode<ElemType> *temp;
		p=temp;
		temp->leftChild=NULL;
		temp->rightChild=NULL;
	}
	p->data=e;
}
//二叉树的中序遍历
template <class ElemType>
void BinaryTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const{
	InOrder(root,*Visit);
}
//二叉树的先序遍历
template <class ElemType>
void BinaryTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const{
	PreOrder(root,*Visit);
}
//二叉树的后序遍历
template <class ElemType>
void BinaryTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const{
	PostOrder(root,*Visit);
}
//二叉树的层次遍历
template <class ElemType>
void BinaryTree<ElemType>::LevelOrder(void (*Visit)(const ElemType &)) const{
	queue<BinTreeNode<ElemType> *> q;
	BinTreeNode<ElemType> *p;
	if(root!=NULL) q.push(root);
	while(!q.empty()){
		p=q.front();
		(*Visit)(p->data);
		q.pop();
		if(q->leftChild!=NULL)
			q.push(q->leftChild);
		if(q->rightChild!=NULL)
			q.push(q->rightChild);
	}
}
//求二叉树的结点个数
template <class ElemType>
int BinaryTree<ElemType>::NodeCount() const{
	return NodeCount(root);
}
//求结点p的左孩子
template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::LeftChild(BinTreeNode<ElemType> *p) const{
	if(p!=NULL){
		if(p->leftChild!=NULL)
			return p->leftChild;
	}
	return NULL;
}
//求结点p的右孩子
template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::RightChild(BinTreeNode<ElemType> *p) const{
	if(p!=NULL){
		if(p->rightChild!=NULL)
			return p->rightChild;
	}
	return NULL;
}
//求结点p的左兄弟
template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::LeftSibling(BinTreeNode<ElemType> *p) const{
	BinTreeNode<ElemType> *r=Parent(root,p);
	if(r==NULL) return NULL;
	else if(r->rightChild == p)
		return r->leftChild;
	else
		return NULL;
}
//求结点p的右兄弟
template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::RightSibling(BinTreeNode<ElemType> *p) const{
	BinTreeNode<ElemType> *r=Parent(root,p);
	if(r==NULL) return NULL;
	else if(r->leftChild == p)
		return r->rightChild;
	else
		return NULL;
}
//求结点p的双亲结点
template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::Parent(BinTreeNode<ElemType> *p) const{
	return Parent(root,p);
}
//在结点p插入一个左孩子
template <class ElemType>
void BinaryTree<ElemType>::InsertLeftChild(BinTreeNode<ElemType> *p,const ElemType &e){
	if(p==NULL) return;
	else{
	BinTreeNode<ElemType> *child=new BinTreeNode<ElemType> (e);
	if(p->leftChild!=NULL)
		child->leftChild=p->leftChild;
	p->leftChild = child;
	return;
	}
}
//在结点p插入一个右孩子
template <class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinTreeNode<ElemType> *p,const ElemType &e){
	if(p==NULL) return;
	else{
	BinTreeNode<ElemType> *child=new BinTreeNode<ElemType> (e);
	if(p->rightChild!=NULL)
		child->rightChild=p->rightChild;
	p->rightChild = child;
	return;
	}
}
//删除结点p左子树
template <class ElemType>
void BinaryTree<ElemType>::DeleteLeftChild(BinTreeNode<ElemType> *p){
	if(p==NULL) return;
	else{
		Destroy(p->leftChild);
	}
}
//删除结点p右子树
template <class ElemType>
void BinaryTree<ElemType>::DeleteRightChild(BinTreeNode<ElemType> *p){
	if(p==NULL) return;
	else{
		Destroy(p->rightChild);
	}
}
//求二叉树的高度
template <class ElemType>
int BinaryTree<ElemType>::Height(){
	return Height(root);
}
//复制构造函数
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType> &t){
	if(root==NULL) t=NULL;
	else{

	}
}
//建立以r为根的二叉树
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(BinaryTree<ElemType> *r){
	r->leftChild=NULL;
	r->rightChild=NULL;
}
