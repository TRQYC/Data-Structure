//二叉搜索树树查找，删除，插入
//recursion 
Position Find(Elemtype X,BinTree BST){
if(!BST) return NULL;
if(X<BST->Data)
	return Find(X,BST->Left);
else if(X>BST->Data)
	return Find(X,BST->Right);
else return BST;
}
//no recursion
Position Find(Elemtype X,BinTree BST){
while(BST){
	if(X<BST->Data)
		BST=BST->Left;
	else if(X>BST->Data)
		BST=BST->Right;
	else return BST;
}
return NULL;
)
//迭代版本
Position FindMin(BinTree BST){
	while(BST->Right){
		BST=BST->Right;
	}
	return BST;
}
//递归版本
Position FindMin(BinTree BST){
	if(!BST) retrun NULL;
	else if(!BST->Left)
		return BST;
	else return FinMin(BST->Left)  ;
}

BinTree Insert(Elemtype X,BinTree BST){
	if(!BST){
		BST=malloc(sizeof(struct treenode));
		BST->Data=X;
		BST->Left=NULL;
		BST->Right=NULL;
	}
	else if(X<BST->data)
		BST->Left=Insert(X,BST->Left);
	else if(X>BST->Data)
		BST->Right=Insert(X,BST->Right);
	return BST;
}

BinTree Delete(Elemtype X,BinTree BST){
	Position Tmp;
	if(!BST) error();
	else if(X<BST->Data)
		BST->Left=Delete(X,BST->Left);
	else if(X>BST->Data)
		BST->Right=Delete(X,BST->Right);
	else if(BST->Left&&BST->Right){
		Tmp=FindMin(BST->Right);
		BST->Data=Tmp->Data;
		BST->Right=Delete(BST->Data,BST->Right);
	}
	else{
		tmp=BST;
		if(!BST->Left)
			BST=BST->Right;
		else if(!BST->Right)
			BST=BST->Left;
		free(tmp);
	}
	return BST;
}
