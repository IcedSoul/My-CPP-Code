template <class ElemType>

void BinaryTree<ElemType>::InsertRightChild(BinTreeNode<ElemType> *cur, const ElemType &e)

// 初始条件：cur非空

// 操作结果：插入元素值为e的结点为cur的右孩子，如果cur的右孩子非空，则cur原有右子树成为e的右子树

{

 if (cur == NULL)

 { // cur为空，返回

  return;

 }

 else

 { // 插入右孩子

  BinTreeNode<ElemType> *child =  new BinTreeNode<ElemType>(e);// 元素值为e结点

  if (cur->rightChild != NULL)

  { // cur的右孩子非空

   child->rightChild = cur->rightChild; // cur原有右子树成为e的右子树

  }

  cur->rightChild = child;     // e成为cur的右孩子

  return;

 }

}
