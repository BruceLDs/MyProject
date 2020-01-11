#define  _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"
//ABD##E#H##CF##G##C
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] != '#'){

		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->data = a[*pi];
		++(*pi);
		root->left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->right = BinaryTreeCreate(a, pi);
		return root;
	}
	else{
		return NULL;
	}
}
void BinaryTreeDestory(BTNode* root)
{
	if (root){
		BinaryTreeDestory(root->left);
		BinaryTreeDestory(root->right);
		free(root);
		root = NULL;
	}
}
void BinaryTreeDestory1(BTNode** root){
	BTNode *curRoot = *root;
	if (curRoot){
		BinaryTreeDestory1(&curRoot->left);
		BinaryTreeDestory1(&curRoot->right);
		free(curRoot);
		*root = NULL;
	}
}
int BinaryTreeSize(BTNode* root)
{
	if (root){
	return	BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
	}
	else{
		return 0;
	}
}
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL){
		return 0;
	}
	if (root->left == NULL&&root->right == NULL){
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL){
		return 0;
	}
	if (k==1){
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode *ret;
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	 ret = BinaryTreeFind(root->left, x);
	 if (ret)return ret;
	 ret = BinaryTreeFind(root->right, x);
	 if (ret)return ret;
	 return NULL;
}
void BinaryTreePrevOrder(BTNode* root)//前序遍历
{
	if (root){
		printf("%c->", root->data);
		BinaryTreePrevOrder(root->left);
		BinaryTreePrevOrder(root->right);
	}
	else{
		printf("#->");
	}
}
void BinaryTreeInOrder(BTNode* root)//中序遍历
{
	if (root){
		BinaryTreeInOrder(root->left);
		printf("%c->", root->data);
		BinaryTreeInOrder(root->right);
	}
	else{
		printf("#->");
	}

}
void BinaryTreePostOrder(BTNode* root)//后序遍历
{
	if (root){
		BinaryTreePostOrder(root->left);
		BinaryTreePostOrder(root->right);
		printf("%c->", root->data);
	}
	else{
		printf("#->");
	}

}

// 非递归遍历
//void BinaryTreeLevelOrder(BTNode* root)// 层序遍历
//{
//	/*Queue q;
//	QueueInit(&q);
//	if (root)
//		QueuePush(&q, root);
//		while (QueueEmpty(&q) == 0){
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		printf("%d->", front->data);
//		if (front -> left)
//			QueuePush(&q,front->left);
//		if (front -> right)
//			QueuePush(&q,front->right);
//		}
//	printf("\n");*/
//	}
//int BinaryTreeComplete(BTNode* root)// 判断二叉树是否是完全二叉树
//{
//	/*
//	Queue q;
//	QueueInit(&q);
//	if (root)
//	QueuePush(&q, root);
//	while (QueueEmpty(&q) == 0){
//	BTNode* front = QueueFront(&q);
//	QueuePop(&q);
//	if (front){
//	QueuePush(&q,front->left);
//	QueuePush(&q,front->right);
//	}
//	else{
//	break;
//	}
//	while(QueueEmpty(&q)==0{
//	BTNode* front = QueueFront(&q);
//	if(front)
//	{
//	QueueDestory(&q);
//	return -1;
//	}
//	QueuePop(&q);
//	}
//	return 1;*/                                                                         
//}
//void BinaryTreePrevOrderNonR(BTNode* root)//非递归前序遍历
//{
//	BTNode* cur = root;
//	BTNode* top;
//	Stack st;
//	StackInit(&st);
//	while (cur){
//		while (cur){
//			//左子树访问完
//			printf("%c->", cur->data);
//			StackPush(&st, cur->data);//入栈
//			cur = cur->left;
//		}
//		//回溯到有右子树处
//		top = StackTop(&st);
//		StackPop(&st);//出栈
//		cur = top->right;
//	}
//	printf("\n");
//}
//void BinaryTreeInOrderNonR(BTNode* root)//非递归中序遍历
//{
//
//	BTNode* cur = root;
//	BTNode* top;
//	Stack st;
//	assert(root);
//	StackInit(&st);
//	while (cur){
//		while (cur){
//			//左子树访问完
//			StackPush(&st, cur->data);//入栈
//			cur = cur->left;
//		}
//		//回溯到有右子树处
//		printf("%c->", cur->data);
//		top = StackTop(&st);
//		StackPop(&st);//出栈
//		cur = top->right;
//	}
//	printf("\n");
//
//}
//void BinaryTreePostOrderNonR(BTNode* root)//非递归后序遍历
//{
//	BTNode* cur = root;
//	BTNode* top;
//	BTNode* prev;
//	Stack st;
//	assert(root);
//	StackInit(&st);
//	while (cur || StackEmpty==0){
//		while (cur){
//			//左子树访问完
//			StackPush(&st, cur->data);//入栈
//			cur = cur->left;
//		}
//		//访问最后一颗子树的右子树
//		top = StackTop(&st);
//		//判断是否存在右子树.
//		//不存在右，访问根，出栈
//		//存在：如果右子树访问完，可以访问根
//		if (top->right == NULL||top->right == prev){
//			printf("%c->", top->data);
//			StackPop(&st);//出栈
//			prev = top;
//		}
//		//访问右子树
//		else{
//			cur = top->right;
//		}
//	}
//	printf("\n");
//}