#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);//创建二叉树
void BinaryTreeDestory(BTNode* root);//销毁二叉树
void BinaryTreeDestory1(BTNode** root);
int BinaryTreeSize(BTNode* root);//树的长度
int BinaryTreeLeafSize(BTNode* root);//叶子数
int BinaryTreeLevelKSize(BTNode* root, int k);//每层节点数
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);//查找
//递归遍历
void BinaryTreePrevOrder(BTNode* root);// 前序遍历
void BinaryTreeInOrder(BTNode* root);//中序遍历
void BinaryTreePostOrder(BTNode* root);//后序遍历
// 非递归遍历
void BinaryTreeLevelOrder(BTNode* root);// 层序遍历
int BinaryTreeComplete(BTNode* root);// 判断二叉树是否是完全二叉树
void BinaryTreePrevOrderNonR(BTNode* root);//前序遍历
void BinaryTreeInOrderNonR(BTNode* root);//中序遍历
void BinaryTreePostOrderNonR(BTNode* root);//后序遍历
