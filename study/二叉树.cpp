#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
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
	void Destroy(BinTreeNode<ElemType> * &r);
	void PreOrder(BinTreeNode<ElemType> *r .void (*Visit)(const ElemType&)) const;
	void InOrder(BinTreeNode<ElemType> *r .void (*Visit)(const ElemType&)) const;
	void PostOrder(BinTreeNode<ElemType> *r .void (*Visit)(const ElemType&)) const;
	int Height(const BinTreeNode<ElemType> *r) const;
	int NodeCount(const BinTreeNode<ElemType> *r) const;
	BinTreeNode<ElemType> *Parent(BinTreeNode<ElemType> *r,const BinTreeNode<ElemType> *p) const;

public:
	BinaryTree();
	virtual ~BinaryTree();
	
};
{
public:
	El();
	~El();
	
};
int main(){
	
	return 0;
}